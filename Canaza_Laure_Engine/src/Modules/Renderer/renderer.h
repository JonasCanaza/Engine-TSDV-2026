#pragma once

#include <iostream>
#include <vector>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

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
		Window::Window* window = nullptr;

		static const int maxShaderSourceStringsAmount = 1;
		static const int maxShaderCreateInfoLog = 512;

		glm::mat4 view;
		glm::mat4 projection;

	public:
		Renderer(Window::Window* window);

		void Init();
		void ClearScreen();
		void Draw(glm::mat4 globalTRS, unsigned int VAO, size_t indexCount, unsigned int shaderProgram, unsigned int modelLoc, unsigned int viewLoc, unsigned int projLoc);
		Model CreateModel(const std::vector<float>& vertices, const std::vector<unsigned int>& indexes);
		unsigned int CreateShader(const char* shaderSource, GLenum shaderType);
		unsigned int CreateShaderProgram(unsigned int vertexShader, unsigned int fragmentShader);
		unsigned int CreateShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource);
		unsigned int CreateUniformLocation(unsigned int shader, const char name[]);
		void DestroyShader(unsigned int shaderProgram);
		void DestroyModel(Model& model);

		~Renderer();
	};
}

