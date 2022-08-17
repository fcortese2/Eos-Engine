#pragma once

#include <list>
#include <memory>

#include "../Objects/object.h"
#include "../Objects/SpriteRenderer/sprite_renderer.h"
#include "../Objects/Texture2D/texture_2D.h"
#include "../Objects/Camera/camera.h"

class Scene
{
public:
	Scene(glm::mat4 projection);
	~Scene();

	void AddSprite(ShaderProgram* shader_program, Texture2D texture);
	void RenderScene();

	void AddAssetToSceneAssets(SpriteRenderer sprite);

	Camera Camera;

private:
	std::list<SpriteRenderer> sceneRenderers;
	

};
