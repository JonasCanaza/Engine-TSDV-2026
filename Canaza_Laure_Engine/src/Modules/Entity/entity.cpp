#include "Modules/Entity/entity.h"

#include <cmath>

#define DEG2RAD 0.017453292519943295

namespace Entity
{
	Entity::Entity(glm::mat4 globalTRS, glm::vec4 color, Renderer::Renderer* renderer, const std::vector<float>& vertices, const std::vector<unsigned int>& indexes)
	{
		this->globalTRS = globalTRS;
		this->renderer = renderer;
		this->vertices = vertices;
		this->indexes = indexes;

		for (int i = 0; i < vertices.size() / 7; i++)
		{
			this->vertices[7 * i + 3] = color.r;
			this->vertices[7 * i + 4] = color.g;
			this->vertices[7 * i + 5] = color.b;
			this->vertices[7 * i + 6] = color.a;
		}

		model = renderer->CreateModel(this->vertices, indexes);
	}

	void Entity::Translate(float x, float y, float z)
	{
		translation = glm::vec3(translation.x + x, translation.y + y, translation.z + z);
		UpdateTRS();
	}

	void Entity::Rotate(float rotation)
	{
		rotationZ += rotation;
		UpdateTRS();
	}

	void Entity::Translation(float x, float y, float z)
	{
		translation = glm::vec3(x, y, z);
		UpdateTRS();
	}

	void Entity::Rotation(float rotation)
	{
		this->rotationZ = rotation;
		UpdateTRS();
	}

	void Entity::Scale(float x, float y, float z)
	{
		scale = glm::vec3(x, y, z);
		UpdateTRS();
	}

	void Entity::UpdateTRS()
	{
		glm::mat4 identity = glm::mat4(1.0f);

		identity = glm::translate(identity, translation);
		identity = glm::rotate(identity, glm::radians(rotationZ), glm::vec3(0.0f, 0.0f, 1.0f));
		identity = glm::scale(identity, scale);

		globalTRS = identity;
	}

	void Entity::Update()
	{

	}

	Entity::~Entity()
	{

	}
}