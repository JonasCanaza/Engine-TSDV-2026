#pragma once

#include <glfw3.h>

namespace Window
{
	class Window
	{
	private:
		int width = 0;
		int height = 0;
		const char* title = "";

		GLFWwindow* glfwWindow = nullptr;

	public:
		Window(int width, int height, const char* title);

		void Update();

		void OpenWindow();
		bool GetWindowShouldClose();

		int GetWidth();
		int GetHeight();
		const char* GetTitle();

		~Window();
	};
}

