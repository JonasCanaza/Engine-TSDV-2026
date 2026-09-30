#pragma once

#include <vector>

#include "Modules/BaseGame/base_game.h"
#include "glm/geometric.hpp"
#include "Modules/Entity/entity.h"
#include "Star.h"

namespace Game
{
	class Game : public BaseGame::BaseGame
	{
	private:
		std::vector<Entity::Entity*> entities;
		Star* star;

	public:
		Game();

		void OnInit() override;
		void OnUpdate() override;
		void OnDeinit() override;

		~Game();
	};
}

