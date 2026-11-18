#include "Modules/CollisionManager/collision_manager.h"

static const float EPSILON = 1e-06f;

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

		return intersection.x >= EPSILON && intersection.y >= EPSILON;
	}

	bool CollisionManager::AreColliding(Entity::Entity* lhs, Entity::Entity* rhs, Vec3::Vec3& intersection, CollisionSide& side)
	{
		side = CollisionSide::None;

		Vec3::Vec3 leftPos = lhs->GetAABBPos();
		Vec3::Vec3 leftExtents = lhs->GetAABBSize();

		Vec3::Vec3 rightPos = rhs->GetAABBPos();
		Vec3::Vec3 rightExtents = rhs->GetAABBSize();

		float distanceX = leftPos.x - rightPos.x;
		float distanceY = leftPos.y - rightPos.y;

		intersection.x = leftExtents.x + rightExtents.x - fabs(leftPos.x - rightPos.x);
		intersection.y = leftExtents.y + rightExtents.y - fabs(leftPos.y - rightPos.y);

		if (intersection.x >= EPSILON && intersection.y >= EPSILON)
		{
			if (intersection.x < intersection.y)
			{
				side = distanceX > 0.f ? CollisionSide::Right : CollisionSide::Left;
			}
			else
			{
				side = distanceY > 0.f ? CollisionSide::Bottom : CollisionSide::Top;
			}

			return true;
		}

		return false;
	}

	CollisionManager::~CollisionManager()
	{

	}
}