#pragma once

#include <vector>

#include "Modules/BaseGame/base_game.h"

namespace Game
{
	class Game : public BaseGame::BaseGame
	{
	private:
		std::vector<Entity::Entity*> entities;

	public:
		Game();

		void OnInit() override;
		void OnUpdate() override;
		void OnDeinit() override;

		~Game();
	};
}

