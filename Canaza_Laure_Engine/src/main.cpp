#include "base_game.h"

static const int windowWidth = 1920;
static const int windowHeight = 1080;
static const char* windowTitle = "Hello world";

int main()
{
	BaseGame::BaseGame baseGame;

	baseGame.Play(windowWidth, windowHeight, windowTitle);

	return 0;
}