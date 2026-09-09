#include "Modules/Entity/entity.h"

namespace Entity
{
	Entity::Entity(Renderer::Renderer* renderer, const std::vector<float>& vertices, const std::vector<unsigned int>& indexes)
	{
		this->renderer = renderer;
		this->vertices = vertices;
		this->indexes = indexes;

		model = renderer->CreateModel(vertices,indexes);
	}

	void Entity::Update()
	{

	}

	Entity::~Entity()
	{
		
	}
}