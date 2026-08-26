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

			for (int i = 0; i < entities.size(); i++)
			{
				entities[i]->Update();
			}

			/* Poll for and process events */
			glfwPollEvents();

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

			float triangleVert[9] =
			{
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
			};

			entities.push_back(new Shapes::Triangle(triangleVert, renderer));
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

		for (int i = 0; i < entities.size(); i++)
		{
			delete entities[i];
		}
	}
}