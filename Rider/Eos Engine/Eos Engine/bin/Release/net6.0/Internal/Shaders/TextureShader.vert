#version 330

uniform vec2 ViewportSize;

layout (location = 0) in vec2 aPosition;
layout (location = 1) in vec2 TexCoord;

in vec2 v_coord;

out vec2 f_texcoord;
 
void main() 
{
	float nx = (aPosition.x / ViewportSize.x) * 2 - 1;
    float ny = (aPosition.y / ViewportSize.y) * 2 - 1;
    gl_Position = vec4(nx, ny, 0.0 , 1.0);
	f_texcoord = TexCoord;
}