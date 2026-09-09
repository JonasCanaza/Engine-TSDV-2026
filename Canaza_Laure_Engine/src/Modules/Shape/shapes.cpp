#include "Modules/Shape/shapes.h"

namespace Shapes
{
	const std::vector<float> Triangle::vertices =
	{
-0.5f, -0.f, 0.5f,
 0.5f, -0.5f, 0.0f,
 0.0f,  0.5f, 0.0f
	};

	const std::vector<unsigned int> Triangle::indexes =
	{
		0,1,2
	};

	Triangle::Triangle(Renderer::Renderer* renderer) : Shape(renderer,vertices,indexes)
	{
		
	}

	Triangle::Triangle(Renderer::Renderer* renderer, Material::Material* material) : Shape(renderer, vertices, indexes, material)
	{

	}

	void Triangle::Update()
	{
		Draw();
	}

	void Triangle::Draw()
	{
		renderer->Draw(model.VAO, model.indexCount, material->GetShader()->GetId());
	}

	Triangle::~Triangle()
	{

	}
}
