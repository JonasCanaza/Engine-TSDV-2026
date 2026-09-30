#include "Game/Game.h"

#include "exceptions.h"

int main()
{
	Game::Game myGame;

	try
	{
		myGame.Play(1920, 1080, "myGame");
	}
	catch (Exceptions::EngineInitFailed excep)
	{
		std::cout << excep.What();
	}

	return 0;
}