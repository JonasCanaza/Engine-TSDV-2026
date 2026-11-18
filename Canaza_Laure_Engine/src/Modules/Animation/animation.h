#pragma once

#include <vector>

#include "Modules/Animation/animation_frame.h"
#include "Defines/dll_define.h"

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
		int framesCount = 0;
		bool loops = false;
		bool isRunning = false;

	public:
		ENGINE_API Animation();

		void ENGINE_API AddFrame(float framePosX, float framePosY, float frameWidth, float frameHeight, float textWidth, float textHeight, float durationInSeconds, bool shouldLoop);

		void Update(float deltaTime);
		void Restart();
		void ENGINE_API RunAnimation();

		AnimationFrame::AnimationFrame* GetCurrentFrame();
		int GetFramesCount();
		bool ENGINE_API GetIsRunning();

		ENGINE_API ~Animation();
	};
}
