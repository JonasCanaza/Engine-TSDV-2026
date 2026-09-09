#pragma once

#include "Modules/Shape/shape.h"

namespace Shapes
{
	class Triangle : public Shape::Shape
	{
	private:
		static const int maxVertices = 3;
	public:
		Triangle(float vertices[], Renderer::Renderer* renderer);
		Triangle(float vertices[], Renderer::Renderer* renderer, Material::Material* material);

		void Update() override;
		void Draw() override;

		~Triangle();
	};
}

