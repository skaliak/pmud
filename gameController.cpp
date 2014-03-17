#include "gameController.h"

using std::fstream;

GameController::GameController()
{
	//set up the player
	//if we get setup data for player (e.g. name) should cmdPrompt be used for input validation?

	showGreeting();

	string name = "John Doe";
	name = cmdPrompt.askPlayerName();

	player = Player(&map, map.randomRoom(), name);   //passing reference to map could be a problem, since it's private...

	//here's where we want to make the GPS appear on the ground by the player...
}


void GameController::Play()
{
	/*
		This should:
		i. show some kind of intro? -- that happens in the ctor 
		ii. greet player by name? - yep
		1. get commands from player  (n, s, e, w, l) - yep
		2. process commands (move in [dir] or get descriptions) - yep
		3. repeat - yep
		4. allow for an exit condition yep
	*/

	bool quit = false;
	int turnCounter = 0;

	//initial look around
	player.lookAround();

	while (! quit)
	{
		std::cout << turnCounter << "\n";
		//mechanism for timed events
		timedEvent(turnCounter++);
	
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
		player.fightCritter();
		return false;
	case 't':
		player.takeItem();
		return false;
	case 'i':
		player.showInventory();
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

void GameController::showGreeting()
{
	fstream fin(BANNER_FILE, fstream::in);
	string banner, line;

	banner = "\n\n";

	while (!fin.eof())
	{
		getline(fin, line);
		banner += line + "\n";
	}
	fin.close();

	std::cout << banner << "\n\n\n";
}

void GameController::timedEvent(int i)
{
	int n = 10;
	if (i % n == 0)
	{
		//something happens every n turns
	}

	if (i == 2)
	{
		//make something happen once on turn 3
		//this ideally should happen after the move, but before the lookaround
		//make a GPS appear in the player's room so he/she can pick it up
		if (player.currentRoom->getItem() != NULL)
		{
			player.currentRoom->getItem()->makeGps();
			player.lookAround();
		}
		else
		{
			player.currentRoom->putItem(new Item());
			player.currentRoom->getItem()->makeGps();
			player.lookAround();
		}
	}

}