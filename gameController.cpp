#include "gameController.h"

GameController::GameController()
{
	//set up the player
	//if we get setup data for player (e.g. name) should cmdPrompt be used for input validation?

	string name = "John Doe";
	name = cmdPrompt.askPlayerName();

	player = Player(&map, map.randomRoom(), name);   //passing reference to map could be a problem, since it's private...
}


void GameController::Play()
{
	/*
		This should:
		i. show some kind of intro?
		ii. greet player by name?
		1. get commands from player  (n, s, e, w, l)
		2. process commands (move in [dir] or get descriptions)
		3. repeat
		4. allow for an exit condition yep
	
	*/

	bool quit = false;

	//initial look around
	player.lookAround();

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
	case 'f':
		//player.;
		return false;
	case 'q':
		return true;
	case 'h':
		cmdPrompt.showHelp();
		return false;
	default:
		cmdPrompt.showHelp();
		return false;  //show help if all else fails
	}


}
