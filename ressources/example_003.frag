// #version 120
// uniform sampler2D currentTexture;
// uniform float time;

// void main()
// {
//     vec2 coord = gl_TexCoord[0].xy;
//     coord.y += cos(radians(3000 * time + coord.y * 10)) * 0.05 * sin(time * 3);
//     vec4 pixel_color = texture2D(currentTexture, coord);

//     gl_FragColor = pixel_color;
// }

#version 120
uniform sampler2D currentTexture;
uniform float time;

vec2 resolution = vec2(500, 500);
uniform sampler2D texture0;

void main() {
    vec2 coord = gl_FragCoord.xy / resolution.xy;
    vec4 color = texture2D(currentTexture, coord * .1);
    gl_FragColor = texture2D(texture0, coord, 1.5);
    for (float i = 0.; i < 4.; i++) {
        vec2 size = resolution.xy * i * .015;
        vec2 drop = 6.28 * coord * size + (color.rg - .5) * 2.;
        vec2 round = sin(drop);
        vec4 calc = texture2D(currentTexture, floor(coord * size - 0.25 + 0.5) / size);
        float t = (round.x + round.y) * max(0., 1. - fract(time * (calc.b + .1) + calc.g) * 2.);

        if (calc.r < (5 - i) * .16 && t > .5) {
            gl_FragColor = calc;
        }
    }
}
