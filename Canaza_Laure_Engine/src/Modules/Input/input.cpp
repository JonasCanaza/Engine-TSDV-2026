#include "Modules/Input/input.h"

#define GLFW_INCLUDE_NONE
#include "glfw3.h"

namespace Input
{
	InputData Input::engineInputToGLFW[EngineInputs::maxInputs] =
	{
		InputData(GLFW_KEY_SPACE),
		InputData(GLFW_KEY_APOSTROPHE),
		InputData(GLFW_KEY_COMMA),
		InputData(GLFW_KEY_MINUS),
		InputData(GLFW_KEY_PERIOD),
		InputData(GLFW_KEY_SLASH),
		InputData(GLFW_KEY_0),
		InputData(GLFW_KEY_1),
		InputData(GLFW_KEY_2),
		InputData(GLFW_KEY_3),
		InputData(GLFW_KEY_4),
		InputData(GLFW_KEY_5),
		InputData(GLFW_KEY_6),
		InputData(GLFW_KEY_7),
		InputData(GLFW_KEY_8),
		InputData(GLFW_KEY_9),
		InputData(GLFW_KEY_SEMICOLON),
		InputData(GLFW_KEY_EQUAL),
		InputData(GLFW_KEY_A),
		InputData(GLFW_KEY_B),
		InputData(GLFW_KEY_C),
		InputData(GLFW_KEY_D),
		InputData(GLFW_KEY_E),
		InputData(GLFW_KEY_F),
		InputData(GLFW_KEY_G),
		InputData(GLFW_KEY_H),
		InputData(GLFW_KEY_I),
		InputData(GLFW_KEY_J),
		InputData(GLFW_KEY_K),
		InputData(GLFW_KEY_L),
		InputData(GLFW_KEY_M),
		InputData(GLFW_KEY_N),
		InputData(GLFW_KEY_O),
		InputData(GLFW_KEY_P),
		InputData(GLFW_KEY_Q),
		InputData(GLFW_KEY_R),
		InputData(GLFW_KEY_S),
		InputData(GLFW_KEY_T),
		InputData(GLFW_KEY_U),
		InputData(GLFW_KEY_V),
		InputData(GLFW_KEY_W),
		InputData(GLFW_KEY_X),
		InputData(GLFW_KEY_Y),
		InputData(GLFW_KEY_Z),
		InputData(GLFW_KEY_LEFT_BRACKET),
		InputData(GLFW_KEY_BACKSLASH),
		InputData(GLFW_KEY_RIGHT_BRACKET),
		InputData(GLFW_KEY_GRAVE_ACCENT),
		InputData(GLFW_KEY_WORLD_1),
		InputData(GLFW_KEY_WORLD_2),
		InputData(GLFW_KEY_ESCAPE),
		InputData(GLFW_KEY_ENTER),
		InputData(GLFW_KEY_TAB),
		InputData(GLFW_KEY_BACKSPACE),
		InputData(GLFW_KEY_INSERT),
		InputData(GLFW_KEY_DELETE),
		InputData(GLFW_KEY_RIGHT),
		InputData(GLFW_KEY_LEFT),
		InputData(GLFW_KEY_DOWN),
		InputData(GLFW_KEY_UP),
		InputData(GLFW_KEY_PAGE_UP),
		InputData(GLFW_KEY_PAGE_DOWN),
		InputData(GLFW_KEY_HOME),
		InputData(GLFW_KEY_END),
		InputData(GLFW_KEY_CAPS_LOCK),
		InputData(GLFW_KEY_SCROLL_LOCK),
		InputData(GLFW_KEY_NUM_LOCK),
		InputData(GLFW_KEY_PRINT_SCREEN),
		InputData(GLFW_KEY_PAUSE),
		InputData(GLFW_KEY_F1),
		InputData(GLFW_KEY_F2),
		InputData(GLFW_KEY_F3),
		InputData(GLFW_KEY_F4),
		InputData(GLFW_KEY_F5),
		InputData(GLFW_KEY_F6),
		InputData(GLFW_KEY_F7),
		InputData(GLFW_KEY_F8),
		InputData(GLFW_KEY_F9),
		InputData(GLFW_KEY_F10),
		InputData(GLFW_KEY_F11),
		InputData(GLFW_KEY_F12),
		InputData(GLFW_KEY_F13),
		InputData(GLFW_KEY_F14),
		InputData(GLFW_KEY_F15),
		InputData(GLFW_KEY_F16),
		InputData(GLFW_KEY_F17),
		InputData(GLFW_KEY_F18),
		InputData(GLFW_KEY_F19),
		InputData(GLFW_KEY_F20),
		InputData(GLFW_KEY_F21),
		InputData(GLFW_KEY_F22),
		InputData(GLFW_KEY_F23),
		InputData(GLFW_KEY_F24),
		InputData(GLFW_KEY_F25),
		InputData(GLFW_KEY_KP_0),
		InputData(GLFW_KEY_KP_1),
		InputData(GLFW_KEY_KP_2),
		InputData(GLFW_KEY_KP_3),
		InputData(GLFW_KEY_KP_4),
		InputData(GLFW_KEY_KP_5),
		InputData(GLFW_KEY_KP_6),
		InputData(GLFW_KEY_KP_7),
		InputData(GLFW_KEY_KP_8),
		InputData(GLFW_KEY_KP_9),
		InputData(GLFW_KEY_KP_DECIMAL),
		InputData(GLFW_KEY_KP_DIVIDE),
		InputData(GLFW_KEY_KP_MULTIPLY),
		InputData(GLFW_KEY_KP_SUBTRACT),
		InputData(GLFW_KEY_KP_ADD),
		InputData(GLFW_KEY_KP_ENTER),
		InputData(GLFW_KEY_KP_EQUAL),
		InputData(GLFW_KEY_LEFT_SHIFT),
		InputData(GLFW_KEY_LEFT_CONTROL),
		InputData(GLFW_KEY_LEFT_ALT),
		InputData(GLFW_KEY_LEFT_SUPER),
		InputData(GLFW_KEY_RIGHT_SHIFT),
		InputData(GLFW_KEY_RIGHT_CONTROL),
		InputData(GLFW_KEY_RIGHT_ALT),
		InputData(GLFW_KEY_RIGHT_SUPER),
		InputData(GLFW_KEY_MENU),
	};

	InputData::InputData(int glfwId)
	{
		this->glfwId = glfwId;
	}

	Input::Input(Window::Window* window)
	{
		this->window = window;
	}

	void Input::Update()
	{

		GLFWwindow* glfwWindow = window->GetGLFWWindow();

		for (int i = 0; i < EngineInputs::maxInputs; i++)
		{
			InputData& currentInputData = engineInputToGLFW[i];

			if (glfwGetKey(glfwWindow, currentInputData.glfwId) == GLFW_PRESS)
			{
				if (currentInputData.inputState == EngineInputState::KeyUp
					|| currentInputData.inputState == EngineInputState::JustReleased)
				{
					currentInputData.inputState = EngineInputState::KeyPressed;
				}
				else if (currentInputData.inputState == EngineInputState::KeyPressed)
				{
					currentInputData.inputState = EngineInputState::KeyDown;
				}
			}
			else
			{
				if (currentInputData.inputState == EngineInputState::KeyDown || currentInputData.inputState == EngineInputState::KeyPressed)
				{
					currentInputData.inputState = EngineInputState::JustReleased;
				}
				else
				{
					currentInputData.inputState = EngineInputState::KeyUp;
				}
			}
		}
	}

	bool Input::GetIsKeyPressed(EngineInput input)
	{
		return engineInputToGLFW[int(input)].inputState == EngineInputState::KeyPressed;
	}

	bool Input::GetIsKeyDown(EngineInput input)
	{
		return engineInputToGLFW[int(input)].inputState == EngineInputState::KeyDown;
	}

	bool Input::GetIsKeyJustReleased(EngineInput input)
	{
		return engineInputToGLFW[int(input)].inputState == EngineInputState::JustReleased;
	}

	bool Input::GetIsKeyUp(EngineInput input)
	{
		return engineInputToGLFW[int(input)].inputState == EngineInputState::KeyUp;
	}

	Input::~Input()
	{

	}
}