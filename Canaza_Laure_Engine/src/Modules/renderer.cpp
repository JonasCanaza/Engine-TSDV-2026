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

			glGenVertexArrays(1, &VAO);
			glBindVertexArray(VAO);

			glGenBuffers(1, &VBO);
			glBindBuffer(GL_ARRAY_BUFFER, VBO);

			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);

			glBindBuffer(GL_ARRAY_BUFFER, 0);
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
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
	}
}