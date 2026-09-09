#include "Modules/Material/material.h"

namespace Material
{
	const char*  Material::basicVertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"layout (location = 1) in vec4 aColor;\n"

		"out vec4 myColor;\n"

		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"   myColor = aColor;\n"
		"}\0";

	const char* Material::basicFragmentShaderSource = "#version 330 core\n"
		"in vec4 myColor;\n"

		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = myColor;\n"
		"}\n\0";

	Material::Material(Renderer::Renderer* renderer, const char* vertexShaderSource, const char* fragmentShaderSource)
	{
		this->renderer = renderer;
		shader = new ShaderProgram::ShaderProgram(renderer, vertexShaderSource, fragmentShaderSource);
	}

	void Material::LoadShader(const char* vertexShaderSource, const char* fragmentShaderSource)
	{
		if (shader != nullptr)
		{
			delete shader;
		}

		shader = new ShaderProgram::ShaderProgram(renderer,vertexShaderSource, fragmentShaderSource);
	}

	ShaderProgram::ShaderProgram* Material::GetShader()
	{
		return shader;
	}


	Material::~Material()
	{
		delete shader;
	}
}
