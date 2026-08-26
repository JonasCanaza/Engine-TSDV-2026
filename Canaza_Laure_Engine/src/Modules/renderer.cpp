#include "Modules/renderer.h"

#include <iostream>

#include "glew.h"
#include "glfw3.h"

#include "exceptions.h"

namespace Renderer
{
	Renderer::Renderer()
	{

	}

	void Renderer::Init()
	{
		try
		{
			if (glewInit() != GLEW_OK)
			{
				throw Exceptions::InitGlewFailed("Failed to init glew");
			}

			unsigned int buffer;
			glGenBuffers(1, &buffer);
			glBindBuffer(GL_ARRAY_BUFFER, buffer);
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		}
		catch (Exceptions::InitGlewFailed except)
		{
			std::cout << except.What();
		}
	}

	void Renderer::ClearScreen()
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Renderer::Draw(int first, int count)
	{
		glDrawArrays(GL_TRIANGLES, first, count);
	}

	Renderer::~Renderer()
	{

	}
}