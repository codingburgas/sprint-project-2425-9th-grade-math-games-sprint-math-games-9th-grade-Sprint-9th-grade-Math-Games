#include "gameManager.h"

int main()
{    
	GameManager* game = new GameManager();

	game->drawMainLoop();

	delete game;
}