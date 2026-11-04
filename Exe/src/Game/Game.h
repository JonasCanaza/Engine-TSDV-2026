#pragma once

#include <vector>

#include "Modules/BaseGame/base_game.h"
#include "glm/geometric.hpp"
#include "Modules/Entity/entity.h"
#include "Star.h"
#include "Flipper.h"

namespace Game
{
	class Game : public BaseGame::BaseGame
	{
	private:
		std::vector<Entity::Entity*> entities;
		Star* star = nullptr;
		Flipper* flipper = nullptr;

	public:
		Game();

		void OnInit() override;
		void OnUpdate(float deltaTime) override;
		void OnDeinit() override;

		~Game();
	};
}

