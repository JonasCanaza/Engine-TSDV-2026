#include "Modules/Shape/shapes.h"

namespace Shapes
{
	Triangle::Triangle(float vertices[], Renderer::Renderer* renderer) : Shape(renderer)
	{
		for (int i = 0; i < maxVertices; i++)
		{
			this->vertices.push_back(vertices[i]);
		}
	}

	Triangle::Triangle(float vertices[], Renderer::Renderer* renderer, Material::Material* material) : Shape(renderer, material)
	{
		for (int i = 0; i < maxVertices; i++)
		{
			this->vertices.push_back(vertices[i]);
		}
	}

	void Triangle::Update()
	{
		Draw();
	}

	void Triangle::Draw()
	{
		renderer->Draw(material->GetShader()->GetId(), 0, 3);
	}

	Triangle::~Triangle()
	{

	}
}
