#include "Modules/Entity2D/entity_2d.h"

namespace Entity2D
{
	Entity2D::Entity2D(Renderer::Renderer* renderer, const std::vector<float>& vertices, const std::vector<unsigned int>& indexes) : Entity(renderer,vertices,indexes)
	{
		this->material = new Material::Material(renderer);
		this->vertices = vertices;
		this->indexes = indexes;
	}

	Entity2D::Entity2D(Renderer::Renderer* renderer, const std::vector<float>& vertices, const std::vector<unsigned int>& indexes, Material::Material* material) : Entity(renderer,vertices,indexes)
	{
		this->material = material;
	}

	Entity2D::~Entity2D()
	{
		delete this->material;
		renderer->DestroyModel(model);
	}
}