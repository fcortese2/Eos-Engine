#include "texture_loader.h"

#define STB_IMAGE_IMPLEMENTATION


#include <gl/glew.h>
#include <stb_image.h>
#include <Windows.h>
#include <filesystem>
#include <iostream>

TextureLoader::TextureLoader()
{
	
}

LoadedTextureData TextureLoader::LoadTexture(std::string localPath)
{
	unsigned int texture;
	glGenTextures(1, &texture);

	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, nrChannels;
	//stbi_set_flip_vertically_on_load(true);
	char path[255];
	GetCurrentDirectoryA(255, path);
	std::string fullPath = path + localPath;
	std::cout << fullPath << std::endl;
	unsigned char* data = stbi_load(fullPath.c_str(), &width, &height, &nrChannels, 0);

	if (data)
	{
		std::cout << "Channels " << nrChannels << std::endl;
		if (nrChannels == 3)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		}
		else if (nrChannels == 4)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		}
		
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}

	stbi_image_free(data);
	LoadedTextureData tData(texture, width, height);
	return tData;
}

TextureLoader::~TextureLoader()
{
	
}