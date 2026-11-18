#pragma once

#include "Modules/Renderer/renderer.h"

#include "Defines/dll_define.h"
#include "Vec3.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/quaternion.hpp"

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
		glm::quat rotation = glm::quat(1.f, 0.f, 0.f, 0.f);
		glm::vec3 scale = glm::vec3(1.0f);

		std::vector<float> vertices;
		std::vector<unsigned int> indexes;

		Vec3::Vec3 AABBPos;
		Vec3::Vec3 AABBExtents;
		glm::vec3 colliderScale = glm::vec3(1.f, 1.f, 1.f);

		float r = 0.f;
		float g = 0.f;
		float b = 0.f;
		float a = 0.f;
#pragma warning(pop)

	public:
		Entity(glm::mat4 globalTRS, glm::vec4 color, Renderer::Renderer* renderer, const std::vector<float>& vertices, const std::vector<unsigned int>& indexes);

		void Color(float newR, float newG, float newB, float newA);

		float GetColorR();
		float GetColorG();
		float GetColorB();
		float GetColorA();

		void Translate(float x, float y, float z);
		void Rotate(float x, float y, float z, float angle);
		void RotateZ(float angle);

		void Translation(float x, float y, float z);
		void RotationZ(float rotation);
		void Rotation(float x, float y, float z, float w);
		void Scale(float x, float y, float z);

		Vec3::Vec3 GetAABBPos();
		Vec3::Vec3 GetAABBSize();

		Vec3::Vec3 GetPosition();

		void SetColliderScale(Vec3::Vec3 scale);

		virtual void Update(float deltaTime);
		virtual void Draw() = 0;

		virtual ~Entity();
	};
}
