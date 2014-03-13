#include "gameController.h"

GameController::GameController()
{
	//set up the player

}


void GameController::Play()
{
	/*
		This should:
		1. get commands from player  (n, s, e, w, l)
		2. process commands (move in [dir] or get descriptions)
		3. repeat
		4. allow for an exit condition
	
	*/

	bool quit = false;

	while (! quit)
	{
		char cmd = cmdPrompt.getCommand();

		quit = processCommand(cmd);  //returns true if quit was selected

	}
}

bool GameController::processCommand(char c)
{
	switch (c)
	{
	case 'l':
		player.lookAround();  //this does the output
		return false;
	case 'n':
		player.move(Point::NORTH);
		return false;
	case 's':
		player.move(Point::SOUTH);
		return false;
	case 'e':
		player.move(Point::EAST);
		return false;
	case 'w':
		player.move(Point::WEST);
		return false;
	case 'q':
		return true;
	default:
		return true;  //quit if all else fails
	}
}
