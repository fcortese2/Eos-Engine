#pragma once

#include <GLM/vec2.hpp>
#include <GLM/mat4x4.hpp>
#include <iostream>

class Object
{
public:
	const unsigned int UID;

	Object(): UID(std::rand() * std::rand()) {}

	glm::vec2 Position;
	glm::vec2 Scale;
	float Rotation;

	virtual void Draw(glm::mat4 projection) {}

private:
	virtual void Destroy(){}
};
