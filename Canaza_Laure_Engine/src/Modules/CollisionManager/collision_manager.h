#pragma once

#include "Modules/Entity/entity.h"
#include "Defines/dll_define.h"

namespace CollisionManager
{
	class ENGINE_API CollisionManager
	{
	public:
		CollisionManager();

		bool AreColliding(Entity::Entity* a, Entity::Entity* b);
		bool AreColliding(Entity::Entity* a, Entity::Entity* b, Vec3::Vec3& interesection);

		~CollisionManager();
	};
}

