#pragma once

#include <GLM/glm.hpp>

#include "vert_shader.h"
#include "frag_shader.h"

class ShaderProgram
{
public:
	ShaderProgram(VertShader* vert, FragShader* frag);
	~ShaderProgram();
	void Use();

	void SetMatrix4(const char* name, glm::mat4 mat);
	void SetVector3(const char* name, glm::vec3 vec);

	void Destroy();

	unsigned int ShaderProgramHandle = -1;
private:
	bool destroyed;
};
