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

	bool CollisionManager::AreColliding(Entity::Entity* lhs, Entity::Entity* rhs, Vec3::Vec3& intersection)
	{
		Vec3::Vec3 leftPos = lhs->GetAABBPos();
		Vec3::Vec3 leftExtents = lhs->GetAABBSize();

		Vec3::Vec3 rightPos = rhs->GetAABBPos();
		Vec3::Vec3 rightExtents = rhs->GetAABBSize();

		intersection.x = leftExtents.x + rightExtents.x - fabs(leftPos.x - rightPos.x);
		intersection.y = leftExtents.y + rightExtents.y - fabs(leftPos.y - rightPos.y);
		intersection.z = leftExtents.z + rightExtents.z - fabs(leftPos.z - rightPos.z);

		return intersection.x >= 0.f && intersection.y >= 0.f && intersection.z >= 0.f;
	}

	CollisionManager::~CollisionManager()
	{

	}
}