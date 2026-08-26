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

	Renderer::~Renderer()
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
		}
		catch (Exceptions::InitGlewFailed except)
		{
			std::cout << except.What();
		}
	}

	void Renderer::Render()
	{
		glClear(GL_COLOR_BUFFER_BIT);

		float vertices[] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
		};

		unsigned int buffer;
		glGenBuffers(1, &buffer);
		glBindBuffer(GL_ARRAY_BUFFER, buffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glDrawArrays(GL_TRIANGLES, 0, 3);
	}

	void Renderer::Draw()
	{

	}
}