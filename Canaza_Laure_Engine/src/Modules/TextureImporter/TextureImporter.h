#pragma once

#include "Modules/Renderer/renderer.h"

namespace TextureImporter
{
	class TextureImporter
	{
	private:
		Renderer::Renderer* renderer = nullptr;
	public:
		TextureImporter(Renderer::Renderer* renderer);

		int ImportTexture(const char path[], int width, int height, int colorChannels);

		~TextureImporter();
	};
}

