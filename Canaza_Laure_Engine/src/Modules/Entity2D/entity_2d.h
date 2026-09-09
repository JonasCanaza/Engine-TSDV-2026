#pragma once

#include <vector>

#include "Modules/Entity/entity.h"
#include "Modules/Material/material.h"

namespace Entity2D
{
	using namespace Entity;

	class Entity2D : public Entity
	{
	protected:
		Material::Material* material = nullptr;

	public:
		Entity2D(Renderer::Renderer* renderer, const std::vector<float>& vertices, const std::vector<unsigned int>& indexes);
		Entity2D(Renderer::Renderer* renderer, const std::vector<float>& vertices, const std::vector<unsigned int>& indexes, Material::Material* material);

		virtual ~Entity2D();
	};
}
