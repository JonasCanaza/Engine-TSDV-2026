#pragma once

#include "Modules/Entity/entity.h"
#include "Defines/dll_define.h"

namespace CollisionManager
{
	enum class CollisionSide
	{
		None,
		Top,
		Bottom,
		Left,
		Right
	};

	class ENGINE_API CollisionManager
	{
	public:
		CollisionManager();

		bool AreColliding(Entity::Entity* lhs, Entity::Entity* rhs);
		bool AreColliding(Entity::Entity* lhs, Entity::Entity* rhs, Vec3::Vec3& intersection);
		bool AreColliding(Entity::Entity* lhs, Entity::Entity* rhs, Vec3::Vec3& intersection, CollisionSide& side);

		~CollisionManager();
	};
}

