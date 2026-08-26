#include "shapes.h"

namespace Shapes
{
	Triangle::Triangle(float vertices[],Renderer::Renderer* renderer) : Shape(renderer)
	{
		for (int i = 0; i < maxVertices; i++)
		{
			this->vertices.push_back(vertices[i]);
		}
	}

	void Triangle::Draw()
	{
		renderer->Draw(0, 3);
	}

	Triangle::~Triangle()
	{

	}
}
