#pragma once

#include "glfw3.h"

#include "window.h"

namespace BaseGame
{
	class BaseGame
	{
	private:
		bool isRunning = true;

		Window::Window* window = nullptr;

		void Loop();
		void Init(int windowWidth, int windowHeight, const char* title);
	public:
		BaseGame();

		void Play(int windowWidth, int windowHeight, const char* windowTitle);

		~BaseGame();
	};
}

