#version 120
uniform sampler2D currentTexture;
uniform float time;

void main() {
    vec2 coord = gl_TexCoord[0].xy;
    vec4 pixel_color = texture2D(currentTexture, coord);
    float alpha = 0.5 + 0.5 * cos(2 * time);

    pixel_color.z = min(alpha, pixel_color.z);
    gl_FragColor = pixel_color;
}
