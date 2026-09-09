#pragma once

#include "Modules/Renderer/renderer.h"

namespace Entity
{
	class Entity
	{
	protected:
		unsigned int VBO = 0;
		unsigned int VAO = 0;

		unsigned int vertexShader = 0;
		unsigned int fragmentShader = 0;
		unsigned int shaderProgram = 0;

		Renderer::Renderer* renderer = nullptr;

	public:
		Entity(Renderer::Renderer* renderer);

		virtual void Update();

		virtual ~Entity();
	};
}
