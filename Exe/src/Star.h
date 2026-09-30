#pragma once

#include <glm/glm.hpp>

namespace Shapes {
	class Triangle;
}

namespace Renderer {
	class Renderer;
}

class Star
{
private:
	Shapes::Triangle* triangle1;
	Shapes::Triangle* triangle2;

	float speed = minSpeed;
	float speedModifier = 0.05;
	float direction = 1;
	const float minSpeed = 1;
	const float maxSpeed = 10;

public:

	Star(glm::mat4 globalTRS, Renderer::Renderer* renderer);

	void Update();

	~Star();

};


