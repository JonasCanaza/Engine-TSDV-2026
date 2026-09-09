#pragma once

#include "Modules/Renderer/renderer.h"

namespace Entity
{
	class Entity
	{
	protected:
		Renderer::Renderer* renderer = nullptr;

		Renderer::Model model;

		std::vector<float> vertices;
		std::vector<unsigned int> indexes;

	public:
		Entity(Renderer::Renderer* renderer, const std::vector<float>& vertices, const std::vector<unsigned int>& indexes);

		virtual void Update();
		virtual void Draw() = 0;

		virtual ~Entity();
	};
}
