#include "Modules/Material/material.h"

namespace Material
{
	const char* Material::basicVertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"layout (location = 1) in vec4 aColor;\n"
		"uniform mat4 model;\n"
		"uniform mat4 view;\n"
		"uniform mat4 projection;\n"
		"out vec4 myColor;\n"
		"void main()\n"
		"{\n"
		"    gl_Position = projection * view * model * vec4(aPos, 1.0);\n"
		"    myColor = aColor;\n"
		"}\n";

	const char* Material::basicFragmentShaderSource = "#version 330 core\n"
		"in vec4 myColor;\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"    FragColor = myColor;\n" 
		"}\n";

	Material::Material(Renderer::Renderer* renderer, const char* vertexShaderSource, const char* fragmentShaderSource)
	{
		this->renderer = renderer;
		shader = new ShaderProgram::ShaderProgram(renderer, vertexShaderSource, fragmentShaderSource);

		modelLocation = renderer->CreateUniformLocation(shader->GetId(), "model");
		viewLocation = renderer->CreateUniformLocation(shader->GetId(), "view");
		projectionLocation = renderer->CreateUniformLocation(shader->GetId(), "projection");
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

	unsigned int Material::GetModelLocation()
	{
		return modelLocation;
	}

	unsigned int Material::GetViewLocation()
	{
		return viewLocation;
	}

	unsigned int Material::GetProjectionLocation()
	{
		return projectionLocation;
	}


	Material::~Material()
	{
		delete shader;
	}
}
