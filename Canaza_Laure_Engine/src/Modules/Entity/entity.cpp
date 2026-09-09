#include "entity.h"

namespace Entity
{
	Entity::Entity(Renderer::Renderer* renderer)
	{
		this->renderer = renderer;
	}

	void Entity::Update()
	{

	}

	Entity::~Entity()
	{
		renderer->DestroyShader(shaderProgram);
	}
}