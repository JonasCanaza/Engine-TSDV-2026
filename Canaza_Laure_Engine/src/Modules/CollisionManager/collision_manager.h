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

		~CollisionManager();
	};
}

