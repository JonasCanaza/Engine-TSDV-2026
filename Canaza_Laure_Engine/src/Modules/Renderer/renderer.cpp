#include "Modules/Renderer/renderer.h"

#include <iostream>
#include <string>

#include "glew.h"
#include "glfw3.h"
#include "glm/gtc/type_ptr.hpp"

#include "Exceptions/exceptions.h"

namespace Renderer
{
	Renderer::Renderer(Window::Window* window)
	{
		this->window = window;

		view = glm::mat4(1.0f);
		projection = glm::ortho(0.0f, static_cast<float>(window->GetWidth()), static_cast<float>(window->GetHeight()), 0.0f, -1.0f, 1.0f);
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

	void Renderer::DrawShape(glm::mat4 globalTRS, unsigned int VAO, size_t indexCount, unsigned int shaderProgram, unsigned int modelLoc, unsigned int viewLoc, unsigned int projLoc)
	{
		glUseProgram(shaderProgram);

		//1 es la cantidad de matrices y false es si la debe trasponer o no
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(globalTRS));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

		glBindVertexArray(VAO);

		glDrawElements(
			GL_TRIANGLES,
			(int)indexCount,
			GL_UNSIGNED_INT,
			(void*)0
		);

		glBindVertexArray(0);
	}

	void Renderer::DrawSprite(glm::mat4 globalTRS, unsigned int VAO, size_t indexCount, unsigned int shaderProgram, unsigned int modelLoc, unsigned int viewLoc, unsigned int projLoc, unsigned int textureId)
	{
		glUseProgram(shaderProgram);

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, textureId);

		int textLoc = glGetUniformLocation(shaderProgram, "ourTexture");
		glUniform1i(textLoc, 0);

		//1 es la cantidad de matrices y false es si la debe trasponer o no
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(globalTRS));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

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

		model.verticesCount = vertices.size() / 9;
		model.indexCount = indexes.size();

		glGenVertexArrays(1, &model.VAO);
		glBindVertexArray(model.VAO);

		glGenBuffers(1, &model.VBO);
		glBindBuffer(GL_ARRAY_BUFFER, model.VBO);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

		glGenBuffers(1, &model.EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, model.EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, model.indexCount * sizeof(unsigned int), indexes.data(), GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 9, (void*)0);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 9, (void*)(3 * sizeof(float)));

		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 9, (void*)(7 * sizeof(float)));

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

	unsigned int Renderer::CreateUniformLocation(unsigned int shader, const char name[])
	{
		return glGetUniformLocation(shader, name);
	}

	unsigned int Renderer::CreateTexture(int width, int height, ColorFormat::ColorFormat format, unsigned char* data)
	{
		unsigned int texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		if (data)
		{
			GLenum colorFormat = GL_RGBA;

			switch (format)
			{
			case ColorFormat::ColorFormat::RGB:
				colorFormat = GL_RGB;
				break;
			case ColorFormat::ColorFormat::RGBA:
				colorFormat = GL_RGBA;
				break;
			case ColorFormat::ColorFormat::RED:
				colorFormat = GL_RED;
				break;
			case ColorFormat::ColorFormat::ALPHA:
				colorFormat = GL_ALPHA;
				break;
			default:
				break;
			}

			//Permite dimensiones impares
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			glTexImage2D(GL_TEXTURE_2D, 0, colorFormat, width, height, 0, colorFormat, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}

		glBindTexture(GL_TEXTURE_2D, 0);

		return texture;
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