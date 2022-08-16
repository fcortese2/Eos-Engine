#pragma once
#include <string>

class TextureLoader
{
public:
	TextureLoader();
	~TextureLoader();

	static unsigned int LoadTexture(std::string localPath);
	
};
