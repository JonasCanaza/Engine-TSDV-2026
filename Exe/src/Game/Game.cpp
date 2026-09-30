#include "Game.h"

#include <iostream>

namespace Game
{
	Game::Game()
	{

	}

	void Game::OnInit()
	{
		Shapes::Triangle* triangle1 = new Shapes::Triangle(glm::mat4(1.0f), renderer);
		triangle1->Translation(300.0f, 300.0f, 0.0f);
		triangle1->Scale(300.0f, 300.0f, 1.0f);
		entities.push_back(triangle1);
	}

	void Game::OnUpdate()
	{
		for (int i = 0; i < entities.size(); i++)
		{
			entities[i]->Update();
			entities[i]->Rotate(1.0f);
			//entities[i]->Translate(10.0f,0.0f,0.0f);
		}
		//std::cout << "lo logre";
	}

	void Game::OnDeinit()
	{
		for (int i = 0; i < entities.size(); i++)
		{
			delete entities[i];
		}
	}

	Game::~Game()
	{

	}
}