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
		idleAnimation = new Animation::Animation();
		idleAnimation->AddFrame(0.f, 0.f, 35.f, 41.f, 646, 473, 10.75f, true);

		Sprite::Sprite* playerSprite = new Sprite::Sprite(glm::mat4(1.0f), glm::vec4(1, 1, 1, 1), renderer, textImporter, "res/Spritesheets/Knuckles_Sprite_Sheet.png", 646, 473, ColorFormat::ColorFormat::RGBA, idleAnimation);
		playerSprite->Scale(100.0f, 100.0f, 1.0f);
		playerSprite->Translation(900.0f, 300.0f, 0.0f);

		rockIdleAnimation = new Animation::Animation();
		rockIdleAnimation->AddFrame(75.f, 15.f, 84.f, 65.f, 244, 207, 10.75f, true);
		rockIdleAnimation->RunAnimation();

		Sprite::Sprite* rockSprite = new Sprite::Sprite(glm::mat4(1.0f), glm::vec4(1, 1, 1, 1), renderer, textImporter, "res/Spritesheets/Rock.png", 244, 207, ColorFormat::ColorFormat::RGB, rockIdleAnimation);
		rockSprite->Translation(1200.0f, 300.0f, 0.0f);

		rockSprite->Scale(100.0f, 100.0f, 1.0f);
		rockSprite->Translation(1200.0f, 300.0f, 0.0f);

		moveAnimation = new Animation::Animation();
		moveAnimation->AddFrame(335.f, 46.f, 41.f, 41.f, 646, 473, 0.75f, true);
		moveAnimation->AddFrame(376.f, 46.f, 41.f, 41.f, 646, 473, 0.75f, true);
		moveAnimation->AddFrame(416.f, 46.f, 41.f, 41.f, 646, 473, 0.75f, true);
		moveAnimation->AddFrame(454.f, 46.f, 41.f, 41.f, 646, 473, 0.75f, true);

		dashAnimation = new Animation::Animation();
		dashAnimation->AddFrame(227.f, 129.f, 31.f, 30.f, 646, 473, 0.25f, true);
		dashAnimation->AddFrame(262.f, 129.f, 31.f, 30.f, 646, 473, 0.25f, true);
		dashAnimation->AddFrame(295.f, 129.f, 31.f, 30.f, 646, 473, 0.25f, true);
		dashAnimation->AddFrame(328.f, 129.f, 31.f, 30.f, 646, 473, 0.25f, true);

		rockCollideAnimation = new Animation::Animation();
		rockCollideAnimation->AddFrame(426.f, 96.f, 32.f, 35.f, 646, 473, 1.25f, true);
		rockCollideAnimation->AddFrame(461.f, 96.f, 32.f, 35.f, 646, 473, 1.25f, true);
		rockCollideAnimation->AddFrame(499.f, 96.f, 32.f, 35.f, 646, 473, 1.25f, true);
		rockCollideAnimation->AddFrame(531.f, 96.f, 32.f, 35.f, 646, 473, 1.25f, true);

		player = playerSprite;
		rock = rockSprite;

		rockSprite->SetColliderScale(Vec3::Vec3(1, 1, 1.0f));

		idleAnimation->RunAnimation();

		entities.push_back(playerSprite);
		entities.push_back(rockSprite);
	}

	void Game::OnUpdate(float deltaTime)
	{
		if (isPlayerCollidingRock)
		{
			if (!isPlayerPushing)
			{
				if (player->GetPosition().x > rock->GetPosition().x)
				{
					player->Rotation(0.f, 180.f, 0.f, 1.f);
				}
				else
				{
					player->Rotation(0.f, 0.f, 0.f, 1.f);
				}

				player->ChangeAnimation(rockCollideAnimation);
				rockCollideAnimation->RunAnimation();
				isPlayerPushing = true;
			}
		}
		else
		{
			if (isPlayerPushing)
			{
				isPlayerPushing = false;
			}
		}

		PushRock(deltaTime);

		PlayerInput(deltaTime);

		HandleCollisions(player);

		for (int i = 0; i < entities.size(); i++)
		{
			entities[i]->Update(deltaTime);
		}
	}

	void Game::OnDeinit()
	{
		for (int i = 0; i < entities.size(); i++)
		{
			delete entities[i];
		}

		delete idleAnimation;
		delete moveAnimation;
		delete dashAnimation;
		delete rockCollideAnimation;
		delete rockIdleAnimation;
		delete rockCollideAnimation;
	}

	void Game::PushRock(float deltaTime)
	{
		Vec3::Vec3 pushDirection;
		float pushForce = 50;
		switch (collisionSide)
		{
		case CollisionManager::CollisionSide::Top:
			pushDirection = Vec3::Vec3(0.f, 1.f, 0.f);
			break;

		case CollisionManager::CollisionSide::Bottom:
			pushDirection = Vec3::Vec3(0.f, -1.f, 0.f);
			break;

		case CollisionManager::CollisionSide::Left:
			pushDirection = Vec3::Vec3(1.f, 0.f, 0.f);
			break;

		case CollisionManager::CollisionSide::Right:
			pushDirection = Vec3::Vec3(-1.f, 0.f, 0.f);
			break;

		default:
			break;
		}

		if (pushDirection.x != 0 || pushDirection.y != 0 || pushDirection.z != 0)
		{
			pushDirection = pushDirection * pushForce;
			rock->Translate(pushDirection.x * deltaTime, pushDirection.y * deltaTime, pushDirection.z * deltaTime);
		}
	}

	void Game::HandleCollisions(Entity::Entity* entity)
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
				Vec3::Vec3 entityPos = entity->GetAABBPos();
				Vec3::Vec3 colliderPos = entities[i]->GetAABBPos();

				int xDir = entityPos.x < colliderPos.x ? -1 : 1;
				int yDir = entityPos.y < colliderPos.y ? -1 : 1;

				if (intersection.x < intersection.y)
				{
					entity->Translate(intersection.x > 0.f ? intersection.x * xDir : 0.f,
						0.f,
						0.f);
				}
				else
				{
					entity->Translate(0.f,
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

			CollisionManager::CollisionSide collision = CollisionManager::CollisionSide::None;

			isPlayerCollidingRock = CheckEntityCollision(entity, collision);

			collisionSide = collision;
		}
	}

	bool Game::CheckEntityCollision(Entity::Entity* entity, CollisionManager::CollisionSide& collisionSide)
	{
		for (int i = 0; i < entities.size(); i++)
		{
			if (entities[i] == entity)
			{
				continue;
			}

			Vec3::Vec3 intersection;

			if (collisionManager->AreColliding(entity, entities[i], intersection, collisionSide))
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

		if (!isPlayerPushing)
		{
			if (input->GetIsKeyPressed(EngineInputs::EngineInput::ENGINE_KEY_SPACE))
			{
				if (!isDashing)
				{
					player->ChangeAnimation(dashAnimation);
					dashAnimation->RunAnimation();
					isDashing = true;
				}
				else
				{
					isDashing = false;
				}
			}

			if (!isDashing)
			{
				if (direction.x > 0.5f)
				{
					player->Rotation(0.f, 0.f, 0.f, 1.f);
					player->ChangeAnimation(moveAnimation);
					moveAnimation->RunAnimation();
				}
				else if (direction.x < -0.5f)
				{
					player->Rotation(0.f, 180.f, 0.f, 1.f);
					player->ChangeAnimation(moveAnimation);
					moveAnimation->RunAnimation();
				}
				else
				{
					player->ChangeAnimation(idleAnimation);
					moveAnimation->RunAnimation();
				}
			}
		}

		Vec3::Vec3 movingDir = Vec3::Vec3::GetNormalized(direction) * (playerSpeed * deltaTime);
		MoveEntity(player, movingDir);
	}

	Game::~Game()
	{

	}
}