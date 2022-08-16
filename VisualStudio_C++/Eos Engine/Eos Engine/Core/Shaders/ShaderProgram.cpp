#include <iostream>

#include "shader_program.h"

#include <gl\glew.h>

ShaderProgram::ShaderProgram(VertShader* vert, FragShader* frag)
{
	ShaderProgramHandle = glCreateProgram();
	glAttachShader(ShaderProgramHandle, vert->VertShaderHandle);
	glAttachShader(ShaderProgramHandle, frag->FragShaderHandle);
	glLinkProgram(ShaderProgramHandle);

	int success;
	glGetProgramiv(ShaderProgramHandle, GL_LINK_STATUS, &success);
	if (!success)
	{
		char infoLog[512];
		glGetProgramInfoLog(ShaderProgramHandle, 512, nullptr, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED::" << infoLog << std::endl;
	}

	vert->Destroy();
	frag->Destroy();
}

void ShaderProgram::Use()
{
	glUseProgram(ShaderProgramHandle);
}

void ShaderProgram::SetMatrix4(const char* name, glm::mat4 mat)
{
	unsigned int l = glGetUniformLocation(ShaderProgramHandle, name);
	glUniformMatrix4fv(l, 1, GL_FALSE, &mat[0][0]);
}

void ShaderProgram::SetVector3(const char* name, glm::vec3 vec)
{
	unsigned int l = glGetUniformLocation(ShaderProgramHandle, name);
	glUniform3f(l, vec.x, vec.y, vec.z);
}


ShaderProgram::~ShaderProgram()
{
	Destroy();
}


void ShaderProgram::Destroy()
{
	if (destroyed)
	{
		return;
	}

	glDeleteProgram(ShaderProgramHandle);

	destroyed = true;
	delete(this);
}