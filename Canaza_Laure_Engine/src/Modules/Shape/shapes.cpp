#include "Modules/Shape/shapes.h"

namespace Shapes
{
	//equilatero
	//static const std::vector<float> verticesObj =
	//{
	//	0.0f,  0.577f, 0.0f,  1.0f, 0.0f, 0.0f, 1.0f,  
	//	-0.5f, -0.289f, 0.0f,  0.0f, 1.0f, 0.0f, 1.0f, 
	//	 0.5f, -0.289f, 0.0f,  0.0f, 0.0f, 1.0f, 1.0f
	//};

	static const std::vector<float> verticesObj =
	{
		0.0f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
			-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
			0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f
	};

	static const std::vector<unsigned int> indexesObj =
	{
0,1,2
	};

	Triangle::Triangle(glm::mat4 globalTRS, glm::vec4 color, Renderer::Renderer* renderer) : Shape(globalTRS, color, renderer, verticesObj, indexesObj)
	{

	}

	Triangle::Triangle(glm::mat4 globalTRS, glm::vec4 color, Renderer::Renderer* renderer, Material::Material* material) : Shape(globalTRS, color, renderer, verticesObj, indexesObj, material)
	{
	
	}

	void Triangle::Update()
	{
		Draw();
	}

	void Triangle::Draw()
	{
		renderer->Draw(globalTRS, model.VAO, model.indexCount, material->GetShader()->GetId(), material->GetModelLocation(), material->GetViewLocation(), material->GetProjectionLocation());
	}

	Triangle::~Triangle()
	{

	}
}
