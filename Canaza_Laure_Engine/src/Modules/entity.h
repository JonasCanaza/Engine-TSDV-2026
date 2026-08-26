#pragma once

#include "renderer.h"

namespace Entity
{
	class Entity
	{
	protected:
		Renderer::Renderer* renderer;

	public:
		Entity(Renderer::Renderer* renderer);

		virtual void Update();
		virtual void Draw() = 0;

		virtual ~Entity();
	};
}
