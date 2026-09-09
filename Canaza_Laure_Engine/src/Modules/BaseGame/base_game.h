#pragma once

#include <iostream>
#include <vector>

#include "Modules/Window/window.h"
#include "Modules/Renderer/renderer.h"
#include "Modules/Shape/shapes.h"

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

		virtual void OnInit();
		virtual void OnUpdate();
		virtual void OnDeinit();

		~BaseGame();
	};
}

