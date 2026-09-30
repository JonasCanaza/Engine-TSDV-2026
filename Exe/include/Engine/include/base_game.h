#pragma once

#pragma once

#include <iostream>
#include <vector>

#include "Defines/dll_define.h"
#include "Modules/Window/window.h"
#include "Modules/Renderer/renderer.h"
#include "Modules/Shape/shapes.h"

namespace BaseGame
{
	class ENGINE_API BaseGame
	{
	private:
		bool isRunning = true;

		Window::Window* window = nullptr;

		void Loop();
		void Init(int windowWidth, int windowHeight, const char* title);
	protected:
		Renderer::Renderer* renderer = nullptr;

	public:
		BaseGame();

		void Play(int windowWidth, int windowHeight, const char* windowTitle);

		virtual void OnInit();
		virtual void OnUpdate();
		virtual void OnDeinit();

		virtual ~BaseGame();
	};
}

