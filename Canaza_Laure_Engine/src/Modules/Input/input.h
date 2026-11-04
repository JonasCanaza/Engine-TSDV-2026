#pragma once

#include <map>

#include "engine_input.h"
#include "Modules/Window/window.h"
#include "Defines/dll_define.h"

using namespace EngineInputs;

namespace Input
{
	class Input
	{
	private:
		Window::Window* window;
		std::map<EngineInput, int> engineInputToGLFW;

	public:
		Input(Window::Window* window);

		bool ENGINE_API GetIsKeyDown(EngineInput input);

		~Input();
	};
}

