#include "Flipper.h"

glm::vec4 flipperColor = glm::vec4(1.0f, 0.68f, 0.0f, 1.0f);

Flipper::Flipper(glm::mat4 globalTRS, glm::vec3 startPos, Renderer::Renderer* renderer) : Shapes::Triangle(globalTRS, flipperColor, renderer)
{
	this->pos = startPos;
}

void Flipper::Move(float dir)
{
	pos.y += 30.0f * dir;
	Translate(0.0f, 30 * dir, 0.0f);
}

void Flipper::Update()
{
	Move(isMovingUp);

	if (pos.y <= 0)
	{
		isMovingUp = 1.0f;
		Rotate(180);
	}

	if (pos.y >= 1080)
	{
		isMovingUp = -1.0f;
		Rotate(180);
	}

	Draw();
}

Flipper::~Flipper()
{

}