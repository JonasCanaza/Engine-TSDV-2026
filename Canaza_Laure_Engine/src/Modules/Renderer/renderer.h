#pragma once

#include <iostream>
#include <vector>

#include "Modules/window.h"

namespace Renderer
{
	class Renderer
	{
	private:

		static const int maxVertices = 9;
		static const int maxShaderSourceStringsAmount = 1;
		static const int maxShaderCreateInfoLog = 512;

		const char* vertexShaderSourceD = "#version 330 core\n"
			"layout (location = 0) in vec3 aPos;\n"
			"void main()\n"
			"{\n"
			"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
			"}\0";
		const char* fragmentShaderSourceD = "#version 330 core\n"
			"out vec4 FragColor;\n"
			"void main()\n"
			"{\n"
			"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
			"}\n\0";

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
		unsigned int CreateShader(const char* shaderSource);
		unsigned int CreateShaderProgram(unsigned int vertexShader, unsigned int fragmentShader);
		unsigned int CreateShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource);
		void DestroyShader(unsigned int shaderProgram);

		~Renderer();
	};
}

