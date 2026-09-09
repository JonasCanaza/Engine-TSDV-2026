#pragma once

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
		Entity2D(Renderer::Renderer* renderer);
		Entity2D(Renderer::Renderer* renderer, Material::Material* material);

		virtual void Draw() = 0;

		virtual ~Entity2D();
	};
}
