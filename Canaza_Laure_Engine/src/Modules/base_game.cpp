#include "Modules/base_game.h"

#include <stdexcept>
#include <iostream>

#include "exceptions.h"

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

			/* Render here */
			renderer->Render();

			window->Update();

			/* Poll for and process events */
			glfwPollEvents();
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
				throw new Exceptions::OpenWindowFailed("Failed to open window.");
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
		Loop();
	}

	BaseGame::~BaseGame()
	{
		delete window;
		delete renderer;
	}
}