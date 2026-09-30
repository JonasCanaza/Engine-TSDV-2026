#include "Star.h"

#include "Modules/Shape/shapes.h"

Star::Star(glm::mat4 globalTRS, Renderer::Renderer* renderer)
{
	this->triangle1 = new Shapes::Triangle(globalTRS, glm::vec4(1, 0, 0, 1), renderer);
	this->triangle2 = new Shapes::Triangle(globalTRS, glm::vec4(1, 0, 0, 1), renderer);

	triangle1->Translate(300, 500, 0);
	triangle2->Translate(300, 410, 0);

	triangle1->Scale(300.0f, 300.0f, 1.0f);
	triangle2->Scale(300.0f, 300.0f, 1.0f);

	triangle2->Rotate(180.0f);
}

void Star::Update()
{
	speed += speedModifier * direction;

	if (speed >= maxSpeed)
	{
		direction = -1;
	}
	else if (speed <= minSpeed)
	{
		direction = 1;
	}

	triangle1->Rotate(speed);
	triangle2->Rotate(-speed );

	triangle1->Draw();
	triangle2->Draw();
}

Star::~Star()
{
	delete triangle1;
	delete triangle2;
}