#pragma once

#include "Modules/window.h"
#include "Modules/renderer.h"

namespace BaseGame
{
	class BaseGame
	{
	private:
		bool isRunning = true;

		Window::Window* window = nullptr;
		Renderer::Renderer* renderer = nullptr;		

		void Loop();
		void Init(int windowWidth, int windowHeight, const char* title);
	public:
		BaseGame();

		void Play(int windowWidth, int windowHeight, const char* windowTitle);

		~BaseGame();
	};
}

