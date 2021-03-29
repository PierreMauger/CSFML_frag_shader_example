#version 120
uniform sampler2D currentTexture;
uniform float time;

void main(void)
{
    vec2 position = gl_TexCoord[0].xy;
    vec4 pixel_color = texture2D(currentTexture, position);

    pixel_color.x += (position.y + cos((time - position.x) * 2)) / 8;
    pixel_color.y += (position.y + cos((time - position.x) * 2)) / 8;

    gl_FragColor = pixel_color;
}
