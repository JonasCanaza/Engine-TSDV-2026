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
			float currentFrameTime = static_cast<float>(glfwGetTime());

			float deltaTime = currentFrameTime - lastFrameTime;

			lastFrameTime = currentFrameTime;

			renderer->ClearScreen();

			/* Poll for and process events */
			glfwPollEvents();

			OnUpdate(deltaTime);

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
			renderer = new Renderer::Renderer(window);
			textImporter = new TextureImporter::TextureImporter(renderer);
			window->OpenWindow();
			renderer->Init();
		}
		catch (OpenWindowFailed exception)
		{
			cout << exception.What();
			isRunning = false;
			throw Exceptions::EngineInitFailed("Failed to open window.");
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

	void BaseGame::OnUpdate(float deltaTime)
	{
		deltaTime;
	}

	void BaseGame::OnDeinit()
	{

	}

	BaseGame::~BaseGame()
	{
		delete window;
		delete renderer;
		delete textImporter;

		OnDeinit();
	}
}