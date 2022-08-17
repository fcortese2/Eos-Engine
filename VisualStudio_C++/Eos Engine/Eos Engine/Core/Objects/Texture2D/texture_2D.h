#pragma once
#include "../Eos Engine/Core/IO/texture_loader.h"

class Texture2D
{
public:
	const int Width, Height;
	Texture2D(unsigned int textureID, int width, int height);
	Texture2D(LoadedTextureData* data);
	unsigned int TextureID;
};