#include "Game.h"

#include <iostream>

#include "Modules/Input/input.h"

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

		Sprite::Sprite* sprite = new Sprite::Sprite(glm::mat4(1.0f), glm::vec4(1, 0, 0, 1), renderer, textImporter, "res/Armature_Drop_00.png", 1099, 1453, ColorFormat::ColorFormat::RGBA);

		sprite->Scale(300.0f, 300.0f, 1.0f);
		sprite->Translation(400.0f, 300.0f, 0.0f);

		idleAnimation = new Animation::Animation();
		idleAnimation->AddFrame(0.f, 0.f, 48.f, 48.f, 192, 864, 0.75f);
		idleAnimation->AddFrame(48.f, 0.f, 48.f, 48.f, 192, 864, 0.75f);
		idleAnimation->AddFrame(96.f, 0.f, 48.f, 48.f, 192, 864, 0.75f);
		idleAnimation->AddFrame(144.f, 0.f, 48.f, 48.f, 192, 864, 0.75f);

		Sprite::Sprite* anim = new Sprite::Sprite(glm::mat4(1.0f), glm::vec4(1, 0, 0, 1), renderer, textImporter, "res/Spritesheets/Wizard-sheet.png", 192, 864, ColorFormat::ColorFormat::RGBA,idleAnimation);
		anim->Scale(300.0f, 300.0f, 1.0f);
		anim->Translation(900.0f, 300.0f, 0.0f);

		downAnimation = new Animation::Animation();
		downAnimation->AddFrame(0.f, 192.f, 48.f, 48.f, 192, 864, 0.75f);
		downAnimation->AddFrame(48.f, 192.f, 48.f, 48.f, 192, 864, 0.75f);
		downAnimation->AddFrame(96.f, 192.f, 48.f, 48.f, 192, 864, 0.75f);
		downAnimation->AddFrame(144.f, 192.f, 48.f, 48.f, 192, 864, 0.75f);

		upAnimation = new Animation::Animation();
		upAnimation->AddFrame(0.f, 240.f, 48.f, 48.f, 192, 864, 0.75f);
		upAnimation->AddFrame(48.f, 240.f, 48.f, 48.f, 192, 864, 0.75f);
		upAnimation->AddFrame(96.f, 240.f, 48.f, 48.f, 192, 864, 0.75f);
		upAnimation->AddFrame(144.f, 240.f, 48.f, 48.f, 192, 864, 0.75f);

		leftAnimation = new Animation::Animation();
		leftAnimation->AddFrame(0.f, 288.f, 48.f, 48.f, 192, 864, 0.75f);
		leftAnimation->AddFrame(48.f, 288.f, 48.f, 48.f, 192, 864, 0.75f);
		leftAnimation->AddFrame(96.f, 288.f, 48.f, 48.f, 192, 864, 0.75f);
		leftAnimation->AddFrame(144.f, 288.f, 48.f, 48.f, 192, 864, 0.75f);

		rightAnimation = new Animation::Animation();
		rightAnimation->AddFrame(0.f, 336.f, 48.f, 48.f, 192, 864, 0.75f);
		rightAnimation->AddFrame(48.f, 336.f, 48.f, 48.f, 192, 864, 0.75f);
		rightAnimation->AddFrame(96.f, 336.f, 48.f, 48.f, 192, 864, 0.75f);
		rightAnimation->AddFrame(144.f, 336.f, 48.f, 48.f, 192, 864, 0.75f);

		player = anim;

		flipper->Translation(1400.0f, 300.0f, 0.0f);
		flipper->Scale(300.0f, 300.0f, 1.0f);

		this->flipper = flipper;

		entities.push_back(flipper);
		entities.push_back(sprite);
		entities.push_back(anim);
	}

	void Game::OnUpdate(float deltaTime)
	{
		for (int i = 0; i < entities.size(); i++)
		{
			entities[i]->Update(deltaTime);
		}

		star->Update();

		PlayerInput(deltaTime);
	}

	void Game::OnDeinit()
	{
		for (int i = 0; i < entities.size(); i++)
		{
			delete entities[i];
		}

		delete idleAnimation;
		delete upAnimation;
		delete downAnimation;
		delete leftAnimation;
		delete rightAnimation;
		delete star;
	}

	void Game::PlayerInput(float deltaTime)
	{
		direction.x = 0.f;
		direction.y = 0.f;
		direction.z = 0.f;

		if (input->GetIsKeyDown(EngineInputs::EngineInput::ENGINE_KEY_W))
		{
			direction.y = -1.f;
		}
		else if (input->GetIsKeyDown(EngineInputs::EngineInput::ENGINE_KEY_S))
		{
			direction.y = 1.f;
		}

		if (input->GetIsKeyDown(EngineInputs::EngineInput::ENGINE_KEY_A))
		{
			direction.x = -1.f;
		}
		else if (input->GetIsKeyDown(EngineInputs::EngineInput::ENGINE_KEY_D))
		{
			direction.x = 1.f;
		}

		if (direction.x > 0.5f)
		{
			player->ChangeAnimation(rightAnimation);
		}
		else if (direction.x < -0.5f)
		{
			player->ChangeAnimation(leftAnimation);
		}
		else if (direction.y > 0.5f)
		{
			player->ChangeAnimation(downAnimation);
		}
		else if (direction.y < -0.5f)
		{
			player->ChangeAnimation(upAnimation);
		}
		else
		{
			player->ChangeAnimation(idleAnimation);
		}

		Vec3::Vec3 movingDir = Vec3::Vec3::GetNormalized(direction) * (playerSpeed * deltaTime);
		player->Translate(movingDir.x, movingDir.y, movingDir.z);
	}

	Game::~Game()
	{

	}
}