#include "Modules/Entity/entity.h"

#include <cmath>

#define DEG2RAD 0.017453292519943295

namespace Entity
{
	Entity::Entity(glm::mat4 globalTRS, Renderer::Renderer* renderer, const std::vector<float>& vertices, const std::vector<unsigned int>& indexes)
	{
		this->globalTRS = globalTRS;
		this->renderer = renderer;
		this->vertices = vertices;
		this->indexes = indexes;

		model = renderer->CreateModel(vertices, indexes);
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