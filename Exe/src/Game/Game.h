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
		Vec3::Vec3 direction;
		Vec3::Vec3 lastDirection;

		bool isPlayerMoving = false;
		Animation::Animation* idleAnimation = nullptr;
		Animation::Animation* upAnimation = nullptr;
		Animation::Animation* downAnimation = nullptr;
		Animation::Animation* leftAnimation = nullptr;
		Animation::Animation* rightAnimation = nullptr;

	public:
		Game();

		void OnInit() override;
		void OnUpdate(float deltaTime) override;
		void OnDeinit() override;

		void MoveEntity(Entity::Entity* entity, Vec3::Vec3 newPos);
		void HandleCollisions();
		bool CheckEntityCollision(Entity::Entity* entity);
			void PlayerInput(float deltaTime);

		~Game();
	};
}

