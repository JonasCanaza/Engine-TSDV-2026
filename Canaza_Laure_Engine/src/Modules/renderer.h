#pragma once

#include <iostream>
#include <vector>

#include "Modules/window.h"

namespace Renderer
{
	static const int maxVertices = 9;

	class Renderer
	{
	private:
		unsigned int VAO = 0;
		unsigned int VBO = 0;

		float vertices[maxVertices] =
		{
-0.5f, -0.5f, 0.0f,
 0.5f, -0.5f, 0.0f,
 0.0f,  0.5f, 0.0f
		};

	public:
		Renderer();

		void Init();
		void ClearScreen();
		void Draw(int first, int count);

		~Renderer();
	};
}

