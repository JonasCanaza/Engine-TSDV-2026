#pragma once

#include <iostream>
#include <vector>

#include "Modules/Window/window.h"

typedef unsigned int GLenum;

namespace Renderer
{
	struct Model
	{
		unsigned int VAO = 0;
		unsigned int VBO = 0;
		unsigned int EBO = 0;
		size_t verticesCount = 0;
		size_t indexCount = 0;
	};

	class Renderer
	{
	private:

		static const int maxShaderSourceStringsAmount = 1;
		static const int maxShaderCreateInfoLog = 512;

	public:
		Renderer();

		void Init();
		void ClearScreen();
		void Draw(unsigned int VAO, size_t indexCount, unsigned int shaderProgram);
		Model CreateModel(const std::vector<float>& vertices, const std::vector<unsigned int>& indexes);
		unsigned int CreateShader(const char* shaderSource, GLenum shaderType);
		unsigned int CreateShaderProgram(unsigned int vertexShader, unsigned int fragmentShader);
		unsigned int CreateShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource);
		void DestroyShader(unsigned int shaderProgram);
		void DestroyModel(Model& model);

		~Renderer();
	};
}

