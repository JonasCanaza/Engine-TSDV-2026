#pragma once

#include <iostream>
#include <vector>

#include "Modules/Window/window.h"

#include "glfw3.h"
#include "glew.h"

namespace Renderer
{
	class Renderer
	{
	private:

		static const int maxVertices = 9;
		static const int maxShaderSourceStringsAmount = 1;
		static const int maxShaderCreateInfoLog = 512;

		unsigned int VAO = 0;
		unsigned int VBO = 0;

		float vertices[maxVertices] =
		{
-0.5f, -0.5f, 0.0f,
 0.5f, -0.5f, 0.0f,
 0.0f,  0.5f, 0.0f
		};

	public:
		Renderer();

		void Init();
		void ClearScreen();
		void Draw(unsigned int shaderProgram, int first, int count);
		unsigned int CreateShader(const char* shaderSource, GLenum shaderType);
		unsigned int CreateShaderProgram(unsigned int vertexShader, unsigned int fragmentShader);
		unsigned int CreateShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource);
		void DestroyShader(unsigned int shaderProgram);

		~Renderer();
	};
}

