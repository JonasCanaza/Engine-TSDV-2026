#include "Modules/Entity/entity.h"

#include <cmath>
#include <vector>
#include <limits>

#define DEG2RAD 0.017453292519943295
#define EPSILON 0.0001f

namespace Entity
{
	Entity::Entity(glm::mat4 globalTRS, glm::vec4 color, Renderer::Renderer* renderer, const std::vector<float>& vertices, const std::vector<unsigned int>& indexes)
	{
		this->globalTRS = globalTRS;
		this->renderer = renderer;
		this->vertices = vertices;
		this->indexes = indexes;

		r = color.x;
		g = color.y;
		b = color.z;
		a = color.w;

		for (int i = 0; i < vertices.size() / 9; i++)
		{
			this->vertices[9 * i + 3] = color.r;
			this->vertices[9 * i + 4] = color.g;
			this->vertices[9 * i + 5] = color.b;
			this->vertices[9 * i + 6] = color.a;
		}

		model = renderer->CreateModel(this->vertices, indexes);

		UpdateTRS();
	}

	float Entity::GetColorR()
	{
		return r;
	}

	float Entity::GetColorG()
	{
		return g;
	}

	float Entity::GetColorB()
	{
		return b;
	}

	float Entity::GetColorA()
	{
		return a;
	}

	void Entity::Color(float newR, float newG, float newB, float newA)
	{
		this->r = newR;
		this->g = newG;
		this->b = newB;
		this->a = newA;

		for (int i = 0; i < vertices.size() / 9; i++)
		{
			this->vertices[9 * i + 3] = r;
			this->vertices[9 * i + 4] = g;
			this->vertices[9 * i + 5] = b;
			this->vertices[9 * i + 6] = a;
		}

		renderer->UpdateVBO(model.VBO, vertices);
	}

	void Entity::Translate(float x, float y, float z)
	{
		translation = glm::vec3(translation.x + x, translation.y + y, translation.z + z);
		UpdateTRS();
	}

	void Entity::Rotate(float x, float y, float z, float angle)
	{
		glm::vec3 axis(x, y, z);
		if (glm::length(axis) > EPSILON)
		{
			glm::quat quat = glm::angleAxis(static_cast<float>(angle * DEG2RAD), glm::normalize(axis));
			rotation = glm::normalize(quat * rotation);
			UpdateTRS();
		}
	}

	void Entity::RotateZ(float angle)
	{
		glm::quat quat = glm::angleAxis(static_cast<float>(angle * DEG2RAD), glm::vec3(0.f, 0.f, 1.f));
		rotation = glm::normalize(quat * rotation);
		UpdateTRS();
	}

	void Entity::Translation(float x, float y, float z)
	{
		translation = glm::vec3(x, y, z);
		UpdateTRS();
	}

	void Entity::Rotation(float x, float y, float z, float w)
	{
		glm::quat quat(w, x, y, z);

		if (glm::length(quat) > EPSILON)
		{
			rotation = glm::normalize(quat);
			UpdateTRS();
		}
	}

	//Overrides every other axis rotation
	void Entity::RotationZ(float angle)
	{
		rotation = glm::angleAxis(static_cast<float>(angle * DEG2RAD), glm::vec3(0.f, 0.f, 1.f));
		UpdateTRS();
	}

	void Entity::Scale(float x, float y, float z)
	{
		scale = glm::vec3(x, y, z);
		UpdateTRS();
	}

	Vec3::Vec3 Entity::GetAABBPos()
	{
		return AABBPos;
	}

	Vec3::Vec3 Entity::GetAABBSize()
	{
		return AABBExtents;
	}

	Vec3::Vec3 Entity::GetPosition()
	{
		return Vec3::Vec3(translation.x, translation.y, translation.z);
	}

	void Entity::SetColliderScale(Vec3::Vec3 newScale)
	{
		colliderScale = glm::vec3(newScale.x, newScale.y, newScale.z);
		UpdateTRS();
	}

	void Entity::UpdateTRS()
	{
		glm::mat4 identity = glm::mat4(1.0f);

		identity = glm::translate(identity, translation);
		identity = identity * glm::mat4_cast(rotation);
		identity = glm::scale(identity, scale);

		globalTRS = identity;

		float minX = std::numeric_limits<float>().max();
		float minY = std::numeric_limits<float>().max();
		float minZ = std::numeric_limits<float>().max();

		float maxX = std::numeric_limits<float>().lowest();
		float maxY = std::numeric_limits<float>().lowest();
		float maxZ = std::numeric_limits<float>().lowest();

		for (int i = 0; i < vertices.size() / 9; i++)
		{
			glm::vec3 currentVertex = glm::vec3(vertices[9 * i], vertices[9 * i + 1], vertices[9 * i + 2]);

			currentVertex *= colliderScale;

			currentVertex = globalTRS * glm::vec4(currentVertex, 1.0f);

			minX = glm::min(minX, currentVertex.x);
			minY = glm::min(minY, currentVertex.y);
			minZ = glm::min(minZ, currentVertex.z);

			maxX = glm::max(maxX, currentVertex.x);
			maxY = glm::max(maxY, currentVertex.y);
			maxZ = glm::max(maxZ, currentVertex.z);
		}
		AABBPos = Vec3::Vec3((minX + maxX) * 0.5f, (minY + maxY) * 0.5f, (minZ + maxZ) * 0.5f);
		AABBExtents = Vec3::Vec3((maxX - minX) * 0.5f, (maxY - minY) * 0.5f, (maxZ - minZ) * 0.5f);
	}

	void Entity::Update(float deltaTime)
	{
		deltaTime;
	}

	Entity::~Entity()
	{

	}
}