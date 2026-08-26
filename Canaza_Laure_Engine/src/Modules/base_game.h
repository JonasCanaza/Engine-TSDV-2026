#pragma once

#include <iostream>
#include <vector>

#include "Modules/window.h"
#include "Modules/renderer.h"
#include "Shapes/shapes.h"

namespace BaseGame
{
	class BaseGame
	{
	private:
		bool isRunning = true;

		Window::Window* window = nullptr;
		Renderer::Renderer* renderer = nullptr;		
		
		std::vector<::Entity::Entity*> entities;

		void Loop();
		void Init(int windowWidth, int windowHeight, const char* title);
	public:
		BaseGame();

		void Play(int windowWidth, int windowHeight, const char* windowTitle);

		~BaseGame();
	};
}

