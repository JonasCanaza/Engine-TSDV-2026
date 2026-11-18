#pragma once

#include <vector>

#include "Modules/BaseGame/base_game.h"
#include "glm/geometric.hpp"
#include "Modules/Entity/entity.h"
#include "Star.h"
#include "Flipper.h"
#include "Modules/Animation/animation.h"
#include "Modules/Sprite/Sprite.h"
#include "Vec3.h"

namespace Game
{
	class Game : public BaseGame::BaseGame
	{
	private:
		std::vector<Entity::Entity*> entities;
		Star* star = nullptr;
		Flipper* flipper = nullptr;

		const float playerSpeed = 300;

		Sprite::Sprite* player;
		Sprite::Sprite* rock;

		Vec3::Vec3 direction;
		Vec3::Vec3 lastDirection;

		bool isPlayerMoving = false;
		bool isPlayerPushing = false;
		bool isPlayerCollidingRock = false;
		CollisionManager::CollisionSide collisionSide = CollisionManager::CollisionSide::None;
		Animation::Animation* idleAnimation = nullptr;
		Animation::Animation* moveAnimation = nullptr;
		Animation::Animation* dashAnimation = nullptr;
		Animation::Animation* rockCollideAnimation = nullptr;

		Animation::Animation* rockIdleAnimation = nullptr;

		bool isDashing = false;

	public:
		Game();

		void OnInit() override;
		void OnUpdate(float deltaTime) override;
		void OnDeinit() override;

		void MoveEntity(Entity::Entity* entity, Vec3::Vec3 newPos);
		void PushRock(float deltaTime);
		void HandleCollisions(Entity::Entity* entity);
		bool CheckEntityCollision(Entity::Entity* entity, CollisionManager::CollisionSide& collisionSide);
		void PlayerInput(float deltaTime);

		~Game();
	};
}

