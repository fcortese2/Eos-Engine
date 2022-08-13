#version 330 core

in vec4 vColor;
in vec2 f_texcoord;

out vec4 pixelColor;

uniform sampler2D texture;

void main()
{
    pixelColor = texture2D(texture, f_texcoord);
}