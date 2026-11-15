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

		Sprite::Sprite* anim = new Sprite::Sprite(glm::mat4(1.0f), glm::vec4(1, 0, 0, 1), renderer, textImporter, "res/Spritesheets/Wizard-sheet.png", 192, 864, ColorFormat::ColorFormat::RGBA, idleAnimation);
		anim->Scale(300.0f, 300.0f, 1.0f);
		anim->Translation(900.0f, 300.0f, 0.0f);

		Sprite::Sprite* anim2 = new Sprite::Sprite(glm::mat4(1.0f), glm::vec4(1, 0, 0, 1), renderer, textImporter, "res/Spritesheets/Wizard-sheet.png", 192, 864, ColorFormat::ColorFormat::RGBA, idleAnimation);
		anim2->Scale(300.0f, 300.0f, 1.0f);
		anim2->Translation(1200.0f, 300.0f, 0.0f);

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
		player->SetColliderScale(Vec3::Vec3(13.f / 48.f, 18.f / 48.f, 1.0f));
		anim2->SetColliderScale(Vec3::Vec3(13.f / 48.f, 18.f / 48.f, 1.0f));

		flipper->Translation(1400.0f, 300.0f, 0.0f);
		flipper->Scale(300.0f, 300.0f, 1.0f);

		this->flipper = flipper;

		entities.push_back(flipper);
		entities.push_back(sprite);
		entities.push_back(anim);
		entities.push_back(anim2);
	}

	void Game::OnUpdate(float deltaTime)
	{
		for (int i = 0; i < entities.size(); i++)
		{
			entities[i]->Update(deltaTime);
		}

		star->Update();
		PlayerInput(deltaTime);

		HandleCollisions();
	}

	void Game::OnDeinit()
	{
		for (int i = 0; i < entities.size(); i++)
		{
			delete entities[i];
		}

		delete flipper;

		delete idleAnimation;
		delete upAnimation;
		delete downAnimation;
		delete leftAnimation;
		delete rightAnimation;
		delete star;
	}

	void Game::HandleCollisions()
	{
		//for (int i = 0; i < entities.size() - 1; i++)
		//{
		//	for (int j = i + 1; j < entities.size(); j++)
		//	{
		//		if (collisionManager->AreColliding(entities[i], entities[j]))
		//		{
		//			std::cout << "Collider1: " << i << " Collider2: " << j;
		//		}
		//	}
		//}

		for (int i = 0; i < entities.size(); i++)
		{
			if (entities[i] == player)
			{
				continue;
			}

			Vec3::Vec3 intersection;

			if (collisionManager->AreColliding(player, entities[i], intersection))
			{
				Vec3::Vec3 playerPos = player->GetAABBPos();
				Vec3::Vec3 colliderPos = entities[i]->GetAABBPos();

				int xDir = playerPos.x < colliderPos.x ? -1 : 1;
				int yDir = playerPos.y < colliderPos.y ? -1 : 1;

				if (intersection.x < intersection.y)
				{
					player->Translate(intersection.x > 0.f ? intersection.x * xDir : 0.f,
						0.f,
						0.f);
				}
				else
				{
					player->Translate(0.f,
						intersection.y > 0.f ? intersection.y * yDir : 0.f,
						0.f);
				}
			}
		}
	}

	void Game::MoveEntity(Entity::Entity* entity, Vec3::Vec3 addPos)
	{
		Vec3::Vec3 entityPos = entity->GetAABBPos();
		Vec3::Vec3 entityExtents = entity->GetAABBSize();

		float minExtent = std::min(entityExtents.x, entityExtents.y) * 0.5f;

		float distance = std::sqrt(addPos.x * addPos.x + addPos.y * addPos.y);

		if (distance <= 0)
		{
			return;
		}

		int steps = std::max(1, static_cast<int>(std::ceil(distance / minExtent)));

		Vec3::Vec3 stepSize = Vec3::Vec3(addPos.x / steps, addPos.y / steps, addPos.z / steps);

		for (int i = 0; i < steps; i++)
		{
			entity->Translate(stepSize.x, stepSize.y, stepSize.z);

			CheckEntityCollision(entity);
		}
	}

	bool Game::CheckEntityCollision(Entity::Entity* entity)
	{
		for (int i = 0; i < entities.size(); i++)
		{
			if (entities[i] == entity)
			{
				continue;
			}

			Vec3::Vec3 intersection;

			if (collisionManager->AreColliding(entity, entities[i], intersection))
			{
				Vec3::Vec3 playerPos = entity->GetAABBPos();
				Vec3::Vec3 colliderPos = entities[i]->GetAABBPos();

				int xDir = playerPos.x < colliderPos.x ? -1 : 1;
				int yDir = playerPos.y < colliderPos.y ? -1 : 1;

				if (intersection.x < intersection.y)
				{
					entity->Translate(intersection.x > 0.f ? intersection.x * xDir : 0.f,
						0.f,
						0.f);
					return true;
				}
				else
				{
					entity->Translate(0.f,
						intersection.y > 0.f ? intersection.y * yDir : 0.f,
						0.f);
					return true;
				}
			}
		}

		return false;
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
		MoveEntity(player, movingDir);
		//player->Translate(movingDir.x, movingDir.y, movingDir.z);
	}

	Game::~Game()
	{

	}
}