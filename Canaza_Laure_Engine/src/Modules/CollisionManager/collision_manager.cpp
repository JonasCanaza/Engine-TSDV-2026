#include "Modules/CollisionManager/collision_manager.h"

namespace CollisionManager
{
	CollisionManager::CollisionManager()
	{

	}

	bool CollisionManager::AreColliding(Entity::Entity* lhs, Entity::Entity* rhs)
	{
		Vec3::Vec3 leftPos = lhs->GetAABBPos();
		Vec3::Vec3 leftExtents = lhs->GetAABBSize();

		Vec3::Vec3 rightPos = rhs->GetAABBPos();
		Vec3::Vec3 rightExtents = rhs->GetAABBSize();

		return leftPos.x + leftExtents.x >= rightPos.x - rightExtents.x &&
			leftPos.x - leftExtents.x <= rightPos.x + rightExtents.x &&
			leftPos.y + leftExtents.y >= rightPos.y - rightExtents.y &&
			leftPos.y - leftExtents.y <= rightPos.y + rightExtents.y &&
			leftPos.z + leftExtents.z >= rightPos.z - rightExtents.z &&
			leftPos.z - leftExtents.z <= rightPos.z + rightExtents.z;
	}

	CollisionManager::~CollisionManager()
	{

	}
}