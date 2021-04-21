#version 120

#ifdef GL_ES
precision mediump float;
#endif

uniform float time;
uniform sampler2D currentTexture;

vec2 resolution = vec2(1440, 810);

float snow(vec2 uv, float scale)
{
    float w = smoothstep(1.0, 0.0, -uv.y * (scale / 10.0));
    if (w < .1) return 0.0;
    uv += time / scale;
    uv.y += time * 2.0 / scale;
    uv.x += sin(uv.y + time * .5) / scale;
    uv *= scale;
    vec2 s = floor(uv), f = fract(uv), p;
    float k = 3.0, d;
    p = .5 + .35 * sin(11.0 * fract(sin((s + scale) * mat2(vec2(7, 3),vec2(6, 5))) * 5.0))- f;
    d = length(p);
    k = min(d, k);
    k = smoothstep(0.0, k, sin(f.x + f.y) * 0.01);
    return k * w;
}

void main(void)
{
    vec2 coord = gl_TexCoord[0].xy;
    vec4 pixel_color = texture2D(currentTexture, coord);

	vec2 uv = (gl_FragCoord.xy * 2. - resolution.xy) / min(resolution.x, resolution.y);
	vec3 finalColor = vec3(0);
	float c = smoothstep(1., 0.1, clamp(uv.y * .1 + .8, 0., .75));

	c += snow(uv, 6.0) * 2.;
	c += snow(uv, 5.5) * 2.;
	c += snow(uv, 5.0) * 2.;
	finalColor = (vec3(c));

    gl_FragColor = pixel_color + vec4(finalColor, 1);
}
