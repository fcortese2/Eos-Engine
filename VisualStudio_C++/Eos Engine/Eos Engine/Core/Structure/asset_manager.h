#pragma once

#include <list>

#include "../IO/texture_loader.h"
#include "../Objects/Texture2D/texture_2D.h"
#include "../Objects/SpriteRenderer/sprite_renderer.h"

class AssetManager
{
public:
	AssetManager();
	~AssetManager();

	SpriteRenderer LoadSpriteAsset(const char* localPath, ShaderProgram* shader);
private:
	std::list<Texture2D> loadedTextures;
};
