#pragma once

#include "Modules/Entity2D/entity_2d.h"
#include "Modules/TextureImporter/texture_importer.h"
#include "color_format.h"
#include "Modules/Animation/animation.h"

namespace Sprite
{
	class ENGINE_API Sprite : public Entity2D::Entity2D
	{
	private:
		int texture = 0;
		Animation::Animation* animation = nullptr;
		AnimationFrame::AnimationFrame* currentFrame = nullptr;

	public:
		Sprite(glm::mat4 globalTRS, glm::vec4 color, Renderer::Renderer* renderer, TextureImporter::TextureImporter* textImporter, const char path[], int width, int height, ColorFormat::ColorFormat format);

		void AddFrame(float framePosX, float framePosY, float frameWidth, float frameHeight, float textWidth, float textHeight, float durationInSeconds);
		void ChangeSprite(AnimationFrame::AnimationFrame* animationFrame);

		void Update(float deltaTime) override;
		void Draw() override;

		~Sprite();
	};

}

