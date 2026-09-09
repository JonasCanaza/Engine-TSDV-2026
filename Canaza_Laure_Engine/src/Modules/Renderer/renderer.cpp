#include "Modules/Renderer/renderer.h"

#include <iostream>
#include <string>

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

	void Renderer::Draw(unsigned int VAO, size_t indexCount, unsigned int shaderProgram)
	{
		glUseProgram(shaderProgram);

		glBindVertexArray(VAO);

		glDrawElements(
			GL_TRIANGLES,
			(int)indexCount,
			GL_UNSIGNED_INT,
			(void*)0
		);

		glBindVertexArray(0);
	}

	Model Renderer::CreateModel(const std::vector<float>& vertices, const std::vector<unsigned int>& indexes)
	{
		Model model;

		model.verticesCount = vertices.size();
		model.indexCount = indexes.size();

		glGenVertexArrays(1, &model.VAO);
		glBindVertexArray(model.VAO);

		glGenBuffers(1, &model.VBO);
		glBindBuffer(GL_ARRAY_BUFFER, model.VBO);
		glBufferData(GL_ARRAY_BUFFER, model.verticesCount * sizeof(float), vertices.data(), GL_STATIC_DRAW);

		glGenBuffers(1, &model.EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, model.EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, model.indexCount * sizeof(float), indexes.data(), GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (void*)0);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (void*)(3 * sizeof(float)));

		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		return model;
	}

	unsigned int Renderer::CreateShader(const char* shaderSource, GLenum shaderType)
	{
		try
		{
			unsigned int shader = glCreateShader(shaderType);

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
		return CreateShaderProgram(CreateShader(vertexShaderSource, GL_VERTEX_SHADER), CreateShader(fragmentShaderSource, GL_FRAGMENT_SHADER));
	}

	void Renderer::DestroyShader(unsigned int shaderProgram)
	{
		glDeleteProgram(shaderProgram);
	}

	void Renderer::DestroyModel(Model& model)
	{
		glDeleteVertexArrays(1, &model.VAO);
		glDeleteBuffers(1, &model.VBO);
		glDeleteBuffers(1, &model.EBO);
	}


	Renderer::~Renderer()
	{

	}
}