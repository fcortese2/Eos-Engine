#include "scene.h"
#include <iostream>

Scene::Scene(glm::mat4 projection): Camera(projection)
{
}


void Scene::AddSprite(ShaderProgram* shader_program, Texture2D texture)
{
	SpriteRenderer sr(shader_program, texture);
	std::cout << texture.Width << "x" << texture.Height << std::endl;
	sr.Scale = glm::vec2(1);
	sr.Position = glm::vec2(0);
	sr.Rotation = 0;
	std::cout << sr.UID << std::endl;
	sceneRenderers.push_back(sr);
}


Scene::~Scene()
{
	
}

void Scene::RenderScene()
{
	for (auto it = sceneRenderers.begin(); it != sceneRenderers.end(); ++it)
	{
		it->Draw(Camera.ProjectionMatrix);
	}
}

void Scene::AddAssetToSceneAssets(SpriteRenderer sprite)
{
	sceneRenderers.push_back(sprite);
}


