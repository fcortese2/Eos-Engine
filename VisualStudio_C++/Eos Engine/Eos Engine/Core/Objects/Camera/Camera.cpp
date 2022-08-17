#include <GLM/ext/matrix_transform.hpp>

#include "camera.h"

#include "gl/glew.h"

Camera::Camera(glm::mat4 projection)
{
	ProjectionMatrix = projection;
	Position = glm::vec3(0.0, 0.0, 3.0);
	Target = glm::vec3(0.0);
	Direction = glm::normalize(Position - Target);

	Up = glm::vec3(0, 1, 0);
	CameraRight = glm::normalize(glm::cross(Up, Direction));
	CameraUp = glm::cross(Direction, CameraRight);
}

void Camera::Draw()
{
	/*glm::mat4 view;
	view = glm::lookAt(Position, Target, Up);*/
}

void Camera::Move(glm::vec3 motion)
{
	ProjectionMatrix = glm::translate(ProjectionMatrix, motion);
}


Camera::~Camera()
{
	
}

