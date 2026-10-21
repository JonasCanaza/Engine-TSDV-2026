#include "Modules/Entity2D/entity_2d.h"

namespace Entity2D
{
	Entity2D::Entity2D(glm::mat4 globalTRS, glm::vec4 color, Renderer::Renderer* renderer, const std::vector<float>& vertices, const std::vector<unsigned int>& indexes, const char* vertexShaderSource, const char* fragmentShaderSource) : Entity(globalTRS, color, renderer, vertices, indexes)
	{
		if (vertexShaderSource != nullptr && fragmentShaderSource != nullptr)
		{
			this->material = new Material::Material(renderer, vertexShaderSource, fragmentShaderSource);
		}
		else
		{
			this->material = new Material::Material(renderer);
		}

		this->vertices = vertices;
		this->indexes = indexes;
	}

	Entity2D::Entity2D(glm::mat4 globalTRS, glm::vec4 color, Renderer::Renderer* renderer, const std::vector<float>& vertices, const std::vector<unsigned int>& indexes, Material::Material* material) : Entity(globalTRS, color, renderer, vertices, indexes)
	{
		this->material = material;
	}

	Entity2D::~Entity2D()
	{
		delete this->material;
		renderer->DestroyModel(model);
	}
}