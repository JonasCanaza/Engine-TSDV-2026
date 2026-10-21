#pragma once

#include <vector>

#include "Modules/Animation/animation_frame.h"

namespace Animation
{
	class Animation
	{
	private:
		float length = 0.f;
		float timer = 0.f;
		int currentFrameIndex = 0;
		std::vector<AnimationFrame::AnimationFrame> animationFrames;
		AnimationFrame::AnimationFrame* currentFrame = nullptr;
	public:
		Animation();

		void AddFrame(float framePosX, float framePosY, float frameWidth, float frameHeight, float textWidth, float textHeight, float durationInSeconds);

		void Update(float deltaTime);

		AnimationFrame::AnimationFrame* GetCurrentFrame();

		~Animation();
	};
}
