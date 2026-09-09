#include "Modules/Shape/shape.h"

namespace Shape
{
	Shape::Shape(Renderer::Renderer* renderer, const std::vector<float>& vertices, const std::vector<unsigned int>& indexes) : Entity2D(renderer, vertices, indexes)
	{
		
	}

	Shape::Shape(Renderer::Renderer* renderer, const std::vector<float>& vertices, const std::vector<unsigned int>& indexes, Material::Material* material) : Entity2D(renderer, vertices, indexes, material)
	{

	}

	Shape::~Shape()
	{

	}
}