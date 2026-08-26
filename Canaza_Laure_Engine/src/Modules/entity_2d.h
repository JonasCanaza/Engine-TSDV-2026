#pragma once

#include "Modules/entity.h"

namespace Entity2D
{
	using namespace Entity;

	class Entity2D : public Entity
	{
	private:

	public:
		Entity2D(Renderer::Renderer* renderer);

		virtual ~Entity2D();
	};
}
