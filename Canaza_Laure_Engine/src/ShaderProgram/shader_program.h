#pragma once

#include "Modules/Renderer/renderer.h"

namespace ShaderProgram
{
	class ShaderProgram
	{
	private:
		unsigned int id = 0;

		Renderer::Renderer* renderer = nullptr;

	public:

		ShaderProgram(Renderer::Renderer* renderer, const char* vertexShaderSource, const char* fragmentShaderSource);

		int GetId();

		~ShaderProgram();
	};
};

