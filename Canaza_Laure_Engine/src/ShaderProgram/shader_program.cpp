#include "ShaderProgram/shader_program.h"

namespace ShaderProgram
{
	ShaderProgram::ShaderProgram(Renderer::Renderer* renderer, const char* vertexShaderSource, const char* fragmentShaderSource)
	{
		this->renderer = renderer;

		id = renderer->CreateShaderProgram(vertexShaderSource, fragmentShaderSource);
	}

	int ShaderProgram::GetId()
	{
		return id;
	}

	ShaderProgram::~ShaderProgram()
	{
		renderer->DestroyShader(id);
	}
}
