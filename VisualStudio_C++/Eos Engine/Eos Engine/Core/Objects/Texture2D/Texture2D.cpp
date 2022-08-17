#include "texture_2D.h"

Texture2D::Texture2D(unsigned textureID, int width, int height): Width(width), Height(height)
{
	TextureID = textureID;
}

Texture2D::Texture2D(LoadedTextureData* data) : Width(data->Width), Height(data->Height)
{
	TextureID = data->TextureID;
}

