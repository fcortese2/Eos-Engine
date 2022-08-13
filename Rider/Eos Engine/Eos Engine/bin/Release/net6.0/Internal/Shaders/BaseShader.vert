#version 330 core

uniform vec2 ViewportSize;

layout (location = 0) in vec2 aPosition;
layout (location = 1) in vec4 aColor;

out vec4 vColor;

void main()
{
    float nx = (aPosition.x / ViewportSize.x) * 2 - 1;
    float ny = (aPosition.y / ViewportSize.y) * 2 - 1;
    gl_Position = vec4(nx, ny, 0.0 , 1.0);

    vColor = aColor;
}