#pragma once

#include "Modules/shape.h"

using namespace Shape;

namespace Shapes
{
	class Triangle : public Shape
	{
	private:
		static const int maxVertices = 3;
	public:
		Triangle(float vertices[], Renderer::Renderer* renderer);

		void Update() override;
		void Draw() override;

		~Triangle();
	};
}

