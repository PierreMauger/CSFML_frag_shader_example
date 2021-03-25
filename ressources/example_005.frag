#version 120
uniform sampler2D currentTexture;
uniform float time;

void main(void)
{
    vec2 coord = gl_TexCoord[0].xy;

    float factor = 0.02 * cos(5. * time);
    float brightness =  0.7 + 0.3 * cos(5 * time);
    coord.x = (coord.x + factor) / (1. + 2. * factor);
    coord.y = (coord.y + factor) / (1. + 2. * factor);
    vec4 pixel_color = texture2D(currentTexture, coord);
    pixel_color.z = min(brightness, pixel_color.z);

    gl_FragColor = pixel_color;
}
