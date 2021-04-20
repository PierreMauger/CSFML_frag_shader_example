#version 120

#ifdef GL_ES
precision mediump float;
#endif

uniform float time;
uniform sampler2D currentTexture;

vec2 resolution = vec2(500, 500);
const int num_x = 10;
const int num_y = 10;
float w = resolution.x - 30;
float h = resolution.y - 30;

vec4 draw_ball(int i, int j, vec4 color_base)
{
    float x = w / 2. * (1.0 - tan(1 * time + float(2 * j + 5 * i))) + 100;
    float y = h * (1.0 - tan(1 * time + float(2 * i + 5 * j)));
    float size = 1.0 * sin(time);
    if (size < 0)
        size *= -1;
    size += 1;
    vec2 pos = vec2(x, y);
    float dist = length(gl_FragCoord.xy - pos) / 2.0;
    float intensity = pow(size / dist, 3.0);
    vec4 color = vec4(0.0);
    // if (color_base.w == 0) {
        color.x = 1.;//1.0 + cos(time / time / float(i * i * i));
        color.y = 1.;//1.0 + sin(time * float(j));
        color.z = 1.;//1.0 + sin(float(j));
        color.w = 1.0;
    // }
    return color * intensity;
}

void main()
{
    vec2 coord = gl_TexCoord[0].xy;
    vec4 color = texture2D(currentTexture, coord);
    vec2 texPos = vec2(gl_FragCoord.x / resolution);

    for (int i = 1; i < num_x; ++i) {
        for (int j = 1; j < num_y; ++j) {
            color += draw_ball(i, j, color);
        }
    }
    gl_FragColor = color;
}
