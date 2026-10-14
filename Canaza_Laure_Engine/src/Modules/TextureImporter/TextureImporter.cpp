#include "TextureImporter.h"

#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#endif 

#include "stb_image.h"

namespace TextureImporter
{
	TextureImporter::TextureImporter(Renderer::Renderer* renderer)
	{
		this->renderer = renderer;
	}

	int TextureImporter::ImportTexture(const char path[], int width, int height, int colorChannels)
	{
		unsigned char* data = stbi_load(path, &width, &height, &colorChannels, 0);

		unsigned int texture = renderer->CreateTexture(width, height, data);

		stbi_image_free(data);
	}

	TextureImporter::~TextureImporter()
	{

	}
}
