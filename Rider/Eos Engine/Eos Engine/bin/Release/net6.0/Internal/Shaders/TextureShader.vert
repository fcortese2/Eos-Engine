#version 330

uniform vec2 ViewportSize;

layout (location = 0) in vec2 aPosition;
layout (location = 1) in vec2 TexCoord;

out vec2 f_texcoord;

uniform mat4 model;
uniform mat4 projection;

void main() 
{
    //float nx = (aPosition.x / ViewportSize.x) * 2 - 1;
    //float ny = (aPosition.y / ViewportSize.y) * 2 - 1;

    gl_Position = projection * model * vec4(aPosition.x, aPosition.y, 0.0, 1.0);
    f_texcoord = TexCoord;
}