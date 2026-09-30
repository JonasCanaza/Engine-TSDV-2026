#pragma once

#include "ShaderProgram/shader_program.h"

namespace Material
{
	class Material
	{
	private:

		static const char* basicVertexShaderSource;
		static const char* basicFragmentShaderSource;

		Renderer::Renderer* renderer = nullptr;
		ShaderProgram::ShaderProgram* shader = nullptr;

		unsigned int modelLocation = 0;
		unsigned int viewLocation = 0;
		unsigned int projectionLocation = 0;

	public:
		Material(Renderer::Renderer* renderer, const char* vertexShaderSource = basicVertexShaderSource, const char* fragmentShaderSource = basicFragmentShaderSource);

		void LoadShader(const char* vertexShaderSource, const char* fragmentShaderSource);

		ShaderProgram::ShaderProgram* GetShader();
		unsigned int GetModelLocation();
		unsigned int GetViewLocation();
		unsigned int GetProjectionLocation();

		~Material();
	};
}

