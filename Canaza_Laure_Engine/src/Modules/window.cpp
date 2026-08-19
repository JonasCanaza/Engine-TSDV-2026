#include "window.h"

#include <iostream>

namespace Window
{
	Window::Window(int width, int height, const char* title)
	{
		this->width = width;
		this->height = height;
		this->title = title;
	}

	void Window::Update()
	{
		/* Swap front and back buffers */
		glfwSwapBuffers(glfwWindow);
	}

	void Window::OpenWindow()
	{
		glfwWindow = glfwCreateWindow(width, height, title, NULL, NULL);

		if (!glfwWindow)
		{
			glfwTerminate();
		}

		glfwMakeContextCurrent(glfwWindow);
	}

	bool Window::GetWindowShouldClose()
	{
		return glfwWindowShouldClose(glfwWindow);
	}

	int Window::GetWidth()
	{
		return width;
	}

	int Window::GetHeight()
	{
		return height;
	}

	const char* Window::GetTitle()
	{
		return title;
	}

	Window::~Window()
	{

	}
}