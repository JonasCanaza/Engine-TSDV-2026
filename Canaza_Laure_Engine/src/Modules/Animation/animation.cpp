#include "animation.h"

namespace Animation
{
	Animation::Animation()
	{

	}

	void Animation::AddFrame(float framePosX, float framePosY, float frameWidth, float frameHeight, float textWidth, float textHeight, float durationInSeconds)
	{
		AnimationFrame::AnimationFrame frame;

		length = durationInSeconds;

		//Top left
		frame.uvCoords[0].u = framePosX / textWidth;
		frame.uvCoords[0].v = framePosY / textHeight;

		//Top right
		frame.uvCoords[1].u = (framePosX + frameWidth) / textWidth;
		frame.uvCoords[1].v = framePosY / textHeight;

		//Bottom right
		frame.uvCoords[2].u = (framePosX + frameWidth) / textWidth;
		frame.uvCoords[2].v = (framePosY + frameHeight) / textHeight;

		//Bottom left
		frame.uvCoords[3].u = framePosX / textWidth;
		frame.uvCoords[3].v = (framePosY + frameHeight) / textHeight;

		framesCount++;

		animationFrames.push_back(frame);
	}

	void Animation::Update(float deltaTime)
	{
		timer += deltaTime;

		while (timer > length)
		{
			timer -= length;
		}

		float frameLength = length / animationFrames.size();
		currentFrameIndex = static_cast<int>(timer / frameLength);

		if (currentFrameIndex >= animationFrames.size())
		{
			Restart();
		}

		currentFrame = &animationFrames[currentFrameIndex];
	}

	void Animation::Restart()
	{
		currentFrameIndex = 0;
		timer = 0;
	}

	AnimationFrame::AnimationFrame* Animation::GetCurrentFrame()
	{
		return currentFrame;
	}

	int Animation::GetFramesCount()
	{
		return framesCount;
	}

	Animation::~Animation()
	{

	}
}