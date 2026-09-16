#pragma once

#ifdef ENGINE_BUILD_DLL
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif

#include "Modules/Shape/shape.h"

namespace Shapes
{
	class Triangle : public Shape::Shape
	{
	private:
		
		static const std::vector<float> vertices;
		static const std::vector<unsigned int> indexes;

	public:
		Triangle(Renderer::Renderer* renderer);
		Triangle(Renderer::Renderer* renderer, Material::Material* material);

		void Update() override;
		void Draw() override;

		~Triangle();
	};
}

