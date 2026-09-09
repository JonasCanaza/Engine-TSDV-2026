#include "Modules/renderer.h"

#include <iostream>
#include <string>

#include "glew.h"
#include "glfw3.h"

#include "Exceptions/exceptions.h"

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

	void Renderer::Draw(unsigned int shaderProgram, int first, int count)
	{
		glUseProgram(shaderProgram);

		glDrawArrays(GL_TRIANGLES, first, count);
	}

	unsigned int Renderer::CreateShader(const char* shaderSource)
	{
		try
		{
			unsigned int shader = glCreateShader(GL_FRAGMENT_SHADER);

			glShaderSource(shader, maxShaderSourceStringsAmount, &shaderSource, NULL);
			glCompileShader(shader);

			int success;
			char infoLog[maxShaderCreateInfoLog];

			glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

			if (!success)
			{
				glGetShaderInfoLog(shader, maxShaderCreateInfoLog, NULL, infoLog);
				throw Exceptions::CreateShaderFailed("Failed to create shader: Error log: " + std::string(infoLog));
			}

			return shader;
		}
		catch (Exceptions::CreateShaderFailed excep)
		{
			std::cout << excep.What();
			return 0;
		}
	}

	unsigned int Renderer::CreateShaderProgram(unsigned int vertexShader, unsigned int fragmentShader)
	{
		try
		{
			unsigned int shaderProgram = glCreateProgram();

			glAttachShader(shaderProgram, vertexShader);
			glAttachShader(shaderProgram, fragmentShader);

			glLinkProgram(shaderProgram);

			int success;
			char infoLog[maxShaderCreateInfoLog];

			glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

			if (!success) 
			{
				glGetProgramInfoLog(shaderProgram, maxShaderCreateInfoLog, NULL, infoLog);
				throw Exceptions::CreateShaderProgramFailed("Failed to create shader program: Error log: " + std::string(infoLog));
			}

			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);

			return shaderProgram;
		}
		catch (Exceptions::CreateShaderProgramFailed excep)
		{
			std::cout << excep.What();

			return 0;
		}
	}

	unsigned int Renderer::CreateShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource)
	{
		return CreateShaderProgram(CreateShader(vertexShaderSource), CreateShader(fragmentShaderSource));
	}

	void Renderer::DestroyShader(unsigned int shaderProgram)
	{
		glDeleteProgram(shaderProgram);
	}

	Renderer::~Renderer()
	{
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
	}
}