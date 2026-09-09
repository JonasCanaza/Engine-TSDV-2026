#include "Modules/Entity2D/entity_2d.h"

namespace Entity2D
{
	Entity2D::Entity2D(Renderer::Renderer* renderer) : Entity(renderer)
	{
		this->material = new Material::Material(renderer);
	}

	Entity2D::Entity2D(Renderer::Renderer* renderer, Material::Material* material) : Entity(renderer)
	{
		this->material = material;
	}

	Entity2D::~Entity2D()
	{
		delete this->material;
	}
}