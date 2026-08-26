#pragma once

#include "Modules/window.h"

namespace Renderer
{
	class Renderer
	{
	private:

	public:
		Renderer();
		~Renderer();

		void Init();
		void Render();
		void Draw();
	};
}

