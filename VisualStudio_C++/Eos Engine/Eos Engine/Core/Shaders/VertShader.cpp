#include <iostream>

#include "vert_shader.h"
#include "GL/glew.h"

#include "IO/shader_loader.h"

VertShader::VertShader(std::string shaderName)
{
	std::string s = ShaderLoader::LoadInternalVertShader(shaderName);
	Build(s.c_str());
}

void VertShader::Build(const char* source)
{
	VertShaderHandle = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(VertShaderHandle, 1, &source, nullptr);
	glCompileShader(VertShaderHandle);
	
	int success;
	glGetShaderiv(VertShaderHandle, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		char infoLog[512];
		glGetShaderInfoLog(VertShaderHandle, 512, nullptr, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED::" << infoLog << std::endl;
	}
}

VertShader::~VertShader()
{
	Destroy();
}

void VertShader::Destroy()
{
	if (destroyed)
	{
		return;
	}

	glDeleteShader(VertShaderHandle);

	destroyed = true;

	delete(this);
}