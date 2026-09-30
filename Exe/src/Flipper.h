#pragma once

#include "Modules/Shape/shapes.h"

class Flipper : public Shapes::Triangle
{
private:
	float isMovingUp = 1.0f;

	glm::vec3 pos;

public:
	Flipper(glm::mat4 globalTRS, glm::vec3 startPos, Renderer::Renderer* renderer);
	~Flipper();

	void Move(float dir);
	void Update() override;
};

	

