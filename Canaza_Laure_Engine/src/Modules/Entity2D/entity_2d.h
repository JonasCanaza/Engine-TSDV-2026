#pragma once

#include <vector>

#include "Modules/Entity/entity.h"
#include "Modules/Material/material.h"

namespace Entity2D
{
	using namespace Entity;

	class ENGINE_API Entity2D : public Entity
	{
	protected:
		Material::Material* material = nullptr;

	public:
		Entity2D(glm::mat4 globalTRS, glm::vec4 color, Renderer::Renderer* renderer, const std::vector<float>& vertices, const std::vector<unsigned int>& indexes);
		Entity2D(glm::mat4 globalTRS, glm::vec4 color, Renderer::Renderer* renderer, const std::vector<float>& vertices, const std::vector<unsigned int>& indexes, Material::Material* material);

		virtual ~Entity2D();
	};
}
