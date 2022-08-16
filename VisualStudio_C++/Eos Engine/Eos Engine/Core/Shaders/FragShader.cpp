#include <iostream>

#include "frag_shader.h"
#include "GL/glew.h"
#include "IO/shader_loader.h"

FragShader::FragShader(std::string shaderName)
{
	std::string s = ShaderLoader::LoadInternalFragShader(shaderName);
	Build(s.c_str());
}

void FragShader::Build(const char* source)
{
	FragShaderHandle = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(FragShaderHandle, 1, &source, nullptr);
	glCompileShader(FragShaderHandle);

	int success;
	glGetShaderiv(FragShaderHandle, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		char infoLog[512];
		glGetShaderInfoLog(FragShaderHandle, 512, nullptr, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED::" << infoLog << std::endl;
	}
}

FragShader::~FragShader()
{
	Destroy();
}

void FragShader::Destroy()
{
	if (destroyed)
	{
		return;
	}

	glDeleteShader(FragShaderHandle);

	destroyed = true;

	delete(this);
}