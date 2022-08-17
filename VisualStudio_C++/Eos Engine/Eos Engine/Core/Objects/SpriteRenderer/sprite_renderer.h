#pragma once

#include "../Eos Engine/Core/Shaders/rendering_lowlevel.h"
#include "../Eos Engine/Core/Objects/Texture2D/texture_2D.h"
#include "GLM/glm.hpp"
#include "../Eos Engine/Core/Objects/object.h"

class SpriteRenderer: public Object
{
public:
	SpriteRenderer(ShaderProgram* shaderProgram, Texture2D texture);
	~SpriteRenderer();

	void Draw(glm::mat4 projection) override;

private:
	ShaderProgram* shader;
	unsigned int quadVAO;
	Texture2D Texture;

	void initRenderData();

	void Destroy() override;
};
