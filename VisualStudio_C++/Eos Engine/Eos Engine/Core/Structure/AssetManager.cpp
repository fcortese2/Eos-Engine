#include "asset_manager.h"

#include "gl/glew.h"

AssetManager::AssetManager()
{
	
}

SpriteRenderer AssetManager::LoadSpriteAsset(const char* localPath, ShaderProgram* shader)
{
	LoadedTextureData d(TextureLoader::LoadTexture(localPath));
	Texture2D tex(&d);
	loadedTextures.push_back(tex);
	SpriteRenderer renderer(shader, tex);
	return renderer;
}

AssetManager::~AssetManager()
{
}


