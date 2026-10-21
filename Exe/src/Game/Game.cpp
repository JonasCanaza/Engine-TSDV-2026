#include "Game.h"

#include <iostream>

#include "Flipper.h"
#include "Modules/Sprite/Sprite.h"

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

		Sprite::Sprite* sprite = new Sprite::Sprite(glm::mat4(1.0f), glm::vec4(1, 0, 0, 1), renderer,textImporter,"res/Armature_Drop_00.png",1099,1453,ColorFormat::ColorFormat::RGBA);
		
		sprite->Scale(300.0f, 300.0f, 1.0f);
		sprite->Translation(400.0f, 300.0f, 0.0f);

		flipper->Translation(1400.0f, 300.0f, 0.0f);
		flipper->Scale(300.0f, 300.0f, 1.0f);

		entities.push_back(flipper);
		entities.push_back(sprite);
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