#include "Game.h"

#include <iostream>

#include "Flipper.h"

namespace Game
{
	Game::Game()
	{

	}

	void Game::OnInit()
	{
		star = new Star(glm::mat4(1.0f), renderer);
		
		glm::vec3 startPos = glm::vec3(1400.0f, 300.0f, 0.0f);
		Flipper* flipper = new Flipper(glm::mat4(1.0f), startPos, renderer);
		
		flipper->Translation(1400.0f, 300.0f, 0.0f);
		flipper->Scale(300.0f, 300.0f, 1.0f);

		entities.push_back(flipper);
	}

	void Game::OnUpdate()
	{
		for (int i = 0; i < entities.size(); i++)
		{
			entities[i]->Update();
		}

		star->Update();
	}

	void Game::OnDeinit()
	{
		for (int i = 0; i < entities.size(); i++)
		{
			delete entities[i];
		}

		delete star;
	}

	Game::~Game()
	{

	}
}