#include <iostream>
#include <GLM/ext/matrix_transform.hpp>

#include "sprite_renderer.h"
#include "gl/glew.h"

SpriteRenderer::SpriteRenderer(ShaderProgram* shaderProgram, Texture2D texture): Texture(texture)
{
	shader = shaderProgram;
	quadVAO = -1;

    Position = glm::vec2(0);
    Scale = glm::vec2(1);
    Rotation = 0;

	initRenderData();
}

void SpriteRenderer::initRenderData()
{
	unsigned int VBO;
    float vertices[] = {
        // pos      // tex
        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f,

        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f
    };

    glGenVertexArrays(1, &quadVAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(quadVAO);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void SpriteRenderer::Draw(glm::mat4 projection)
{
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, Texture.TextureID);
    
    shader->Use();
    glm::mat4 model = glm::mat4(1.0f);
    
    model = glm::translate(model, glm::vec3(Position, 0.0f));
    
    model = glm::translate(model, glm::vec3(0.5f * (Texture.Width * Scale.x), 0.5 * (Texture.Height * Scale.y), 0.0f));
    model = glm::rotate(model, glm::radians(Rotation), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::translate(model, glm::vec3(-0.5f * (Texture.Width * Scale.x), -0.5f * (Texture.Height * Scale.y), 0.0f));
    
    model = glm::scale(model, glm::vec3(Texture.Width * Scale.x, Texture.Height * Scale.y, 1.0f));
    
    shader->SetMatrix4("model", model);
    shader->SetVector3("spriteColor", glm::vec3(1, 1, 1));
    shader->SetMatrix4("projection", projection);

    std::cout << Texture.TextureID << " = TEX ID" << std::endl;
    std::cout << Texture.Width << std::endl;
    std::cout << Texture.Height << std::endl;

    glBindVertexArray(quadVAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}


SpriteRenderer::~SpriteRenderer()
{
	
}

void SpriteRenderer::Destroy()
{
	
}



