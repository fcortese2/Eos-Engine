#pragma once

#include "GLM/mat4x4.hpp"
#include "GLM/common.hpp"
#include "../object.h"

class Camera
{
public:
	Camera(glm::mat4 projection);
	~Camera();

	glm::mat4 ProjectionMatrix;

	glm::vec3 Position;
	glm::vec3 Target;
	glm::vec3 Direction;

	glm::vec3 Up;
	glm::vec3 CameraUp;
	glm::vec3 CameraRight;

	void Draw();

	void Move(glm::vec3 motion);
};
