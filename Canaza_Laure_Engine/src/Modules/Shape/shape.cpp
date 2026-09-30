#include "Modules/Shape/shape.h"

namespace Shape
{
	Shape::Shape(glm::mat4 globalTRS, Renderer::Renderer* renderer, const std::vector<float>& vertices, const std::vector<unsigned int>& indexes) : Entity2D(globalTRS, renderer, vertices, indexes)
	{
		
	}

	Shape::Shape(glm::mat4 globalTRS, Renderer::Renderer* renderer, const std::vector<float>& vertices, const std::vector<unsigned int>& indexes, Material::Material* material) : Entity2D(globalTRS, renderer, vertices, indexes, material)
	{

	}

	Shape::~Shape()
	{

	}
}