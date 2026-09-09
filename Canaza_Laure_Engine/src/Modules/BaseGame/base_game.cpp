#include "Modules/BaseGame/base_game.h"

#include <stdexcept>
#include <iostream>

#define GLFW_INCLUDE_NONE
#include "glfw3.h"

#include "Exceptions/exceptions.h"

using namespace std;
using namespace Exceptions;

namespace BaseGame
{
	void BaseGame::Loop()
	{
		/* Loop until the user closes the window */
		while (!window->GetWindowShouldClose())
		{
			renderer->ClearScreen();

			/* Poll for and process events */
			glfwPollEvents();

			OnUpdate();

			window->Update();
		}

		glfwTerminate();
	}

	void BaseGame::Init(int windowWidth, int windowHeight, const char* title)
	{
		try
		{
			/* Initialize the library */
			if (!glfwInit())
			{
				throw Exceptions::OpenWindowFailed("Failed to open window.");
			}

			window = new Window::Window(windowWidth, windowHeight, title);
			renderer = new Renderer::Renderer();
			window->OpenWindow();
			renderer->Init();
		}
		catch (OpenWindowFailed exception)
		{
			cout << exception.What();
			isRunning = false;
		}
	}

	BaseGame::BaseGame()
	{

	}

	void BaseGame::Play(int windowWidth, int windowHeight, const char* windowTitle)
	{
		Init(windowWidth, windowHeight, windowTitle);
		OnInit();
		Loop();
	}

	void BaseGame::OnInit()
	{

	}

	void BaseGame::OnUpdate()
	{

	}

	void BaseGame::OnDeinit()
	{

	}

	BaseGame::~BaseGame()
	{
		delete window;
		delete renderer;

		OnDeinit();
	}
}