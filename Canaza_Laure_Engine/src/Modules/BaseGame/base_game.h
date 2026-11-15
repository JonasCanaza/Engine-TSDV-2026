#pragma once

#pragma once

#include <iostream>
#include <vector>

#include "Defines/dll_define.h"
#include "Modules/Window/window.h"
#include "Modules/Renderer/renderer.h"
#include "Modules/TextureImporter/texture_importer.h"
#include "Modules/Input/input.h"
#include "Modules/CollisionManager/collision_manager.h"

namespace BaseGame
{
	class ENGINE_API BaseGame
	{
	private:
		bool isRunning = true;

		Window::Window* window = nullptr;
		float lastFrameTime = 0.f;

		void Loop();
		void Init(int windowWidth, int windowHeight, const char* title);
	protected:
		Renderer::Renderer* renderer = nullptr;
		TextureImporter::TextureImporter* textImporter = nullptr;
		Input::Input* input = nullptr;
		CollisionManager::CollisionManager* collisionManager = nullptr;

	public:
		BaseGame();

		void Play(int windowWidth, int windowHeight, const char* windowTitle);

		virtual void OnInit();
		virtual void OnUpdate(float deltaTime);
		virtual void OnDeinit();

		virtual ~BaseGame();
	};
}

