#include "Modules/Shape/shape.h"

namespace Shape
{
	Shape::Shape(Renderer::Renderer* renderer) : Entity2D(renderer)
	{

	}

	Shape::Shape(Renderer::Renderer* renderer, Material::Material* material) : Entity2D(renderer, material)
	{

	}

	Shape::~Shape()
	{

	}
}