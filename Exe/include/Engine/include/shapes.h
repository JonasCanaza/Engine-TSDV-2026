#pragma once

#include "Modules/Shape/shapes.h"

namespace Shapes
{
	class ENGINE_API Triangle : public Shape::Shape
	{
	private:

	public:
		Triangle(glm::mat4 globalTRS, glm::vec4 color, Renderer::Renderer* renderer);
		Triangle(glm::mat4 globalTRS, glm::vec4 color, Renderer::Renderer* renderer, Material::Material* material);

		void Update() override;
		void Draw() override;

		~Triangle();
	};
}

