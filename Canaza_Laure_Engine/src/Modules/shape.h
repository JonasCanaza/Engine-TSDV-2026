#pragma once

#include <vector>
#include <iostream>

#include "Modules/entity_2d.h"

namespace Shape
{
	using namespace Entity2D;

	class Shape : public Entity2D
	{
	private:

	protected:
		std::vector<float> vertices;

	public:
		Shape(Renderer::Renderer* renderer);
		virtual ~Shape();
	};
}

