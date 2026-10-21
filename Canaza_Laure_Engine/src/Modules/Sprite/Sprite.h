#pragma once

#include "Modules/Entity2D/entity_2d.h"
#include "Modules/TextureImporter/TextureImporter.h"
#include "color_format.h"

namespace Sprite
{
	class ENGINE_API Sprite : public Entity2D::Entity2D
	{
	private:
		int texture = 0;
	public:
		Sprite(glm::mat4 globalTRS, glm::vec4 color, Renderer::Renderer* renderer, TextureImporter::TextureImporter* textImporter, const char path[], int width, int height, ColorFormat::ColorFormat format);

		void Update() override;
		void Draw() override;

		~Sprite();
	};
		
}

