#pragma once

#include "Modules/Renderer/renderer.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "Defines/dll_define.h"

namespace Entity
{
	class ENGINE_API Entity
	{
	private:

		void UpdateTRS();

	protected:
		Renderer::Renderer* renderer = nullptr;

		Renderer::Model model;

#pragma warning(push)
#pragma warning(disable: 4251)
		glm::mat4 globalTRS = glm::mat4(1.0f);
		glm::vec3 translation = glm::vec3(0.0f);
		float rotationZ = 0.0f;
		glm::vec3 scale = glm::vec3(1.0f);

		std::vector<float> vertices;
		std::vector<unsigned int> indexes;
#pragma warning(pop)
	public:
		Entity(glm::mat4 globalTRS, Renderer::Renderer* renderer, const std::vector<float>& vertices, const std::vector<unsigned int>& indexes);

		void Translate(float x, float y, float z);
		void Rotate(float rotationZ);

		void Translation(float x, float y, float z);
		void Rotation(float rotationZ);
		void Scale(float x, float y, float z);

		virtual void Update();
		virtual void Draw() = 0;

		virtual ~Entity();
	};
}
