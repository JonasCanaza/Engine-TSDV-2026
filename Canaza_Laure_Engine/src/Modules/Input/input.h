#pragma once

#include "engine_input.h"
#include "Modules/Window/window.h"
#include "Defines/dll_define.h"

using namespace EngineInputs;

namespace Input
{
	struct InputData
	{
	public:
		InputData(int glfwId);

		EngineInputState inputState = EngineInputState::KeyUp;
		int glfwId = 0;
	};

	class Input
	{
	private:

		Window::Window* window;

		static InputData engineInputToGLFW[maxInputs];

	public:
		Input(Window::Window* window);

		void Update();

		bool ENGINE_API GetIsKeyPressed(EngineInput input);
		bool ENGINE_API GetIsKeyDown(EngineInput input);
		bool ENGINE_API GetIsKeyJustReleased(EngineInput input);
		bool ENGINE_API GetIsKeyUp(EngineInput input);

		~Input();
	};
}

