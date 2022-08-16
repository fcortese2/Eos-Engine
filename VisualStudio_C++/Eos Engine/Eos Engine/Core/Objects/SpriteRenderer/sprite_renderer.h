#pragma once

#include "../Eos Engine/Core/Shaders/rendering_lowlevel.h"
#include "../Eos Engine/Core/Objects/Texture2D/texture_2D.h"
#include "GLM/glm.hpp"

class SpriteRenderer
{
public:
	SpriteRenderer(ShaderProgram* shaderProgram);
	SpriteRenderer();
	~SpriteRenderer();

	void DrawSprite(Texture2D& texture, glm::vec2 position,
		glm::vec2 size = glm::vec2(10.0, 10.0), float rotate = 0.0f,
		glm::vec3 color = glm::vec3(1.0f));

private:
	ShaderProgram* shader;
	unsigned int quadVAO;

	void initRenderData();
};
