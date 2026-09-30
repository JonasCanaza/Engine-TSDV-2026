#pragma once

#include <vector>
#include <iostream>

#include "Modules/Entity2D/entity_2d.h"

namespace Shape
{
	using namespace Entity2D;

	class ENGINE_API Shape : public Entity2D
	{
	private:

	protected:

	public:
		Shape(glm::mat4 globalTRS, glm::vec4 color, Renderer::Renderer* renderer, const std::vector<float>& vertices, const std::vector<unsigned int>& indexes);
		Shape(glm::mat4 globalTRS, glm::vec4 color, Renderer::Renderer* renderer, const std::vector<float>& vertices, const std::vector<unsigned int>& indexes, Material::Material* material);
																				 
		virtual ~Shape();
	};
}

