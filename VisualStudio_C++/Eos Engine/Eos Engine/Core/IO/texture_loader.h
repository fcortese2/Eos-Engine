#pragma once
#include <list>
#include <string>
#include <vector>

struct LoadedTextureData
{
	unsigned int TextureID;
	int Width;
	int Height;

	LoadedTextureData(unsigned int tID, int w, int h)
	{
		TextureID = tID;
		Width = w;
		Height = h;
	}
};

class TextureLoader
{
public:
	TextureLoader();
	~TextureLoader();

	static LoadedTextureData LoadTexture(std::string localPath);
	
};


