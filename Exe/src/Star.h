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
	float speedModifier = 0.05f;
	float direction = 1.f;
	const float minSpeed = 1.f;
	const float maxSpeed = 10.f;

public:

	Star(glm::mat4 globalTRS, Renderer::Renderer* renderer);

	void Update();

	~Star();

};


