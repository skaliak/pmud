/*
Peter Lindberg
CS165 w2014
Final Project
*/
#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#define BANNER_FILE "banner.txt"

#include <fstream>
#include "cmdPrompt.h"
#include "map.h"
#include "player.h"


#define MAPSIZE

//all console IO will happen here
//where do parameters get read/set?  E.g. map size, number of regions, player name, etc?

class GameController
{
public:
	GameController();  //there should be some setup here...
	void Play();  //starts/plays the game
	bool processCommand(char cmd); //returns true if quit was selected
	void showGreeting();
	void timedEvent(int i);	//make stuff happen even n'th turn
private:
	CmdPrompt cmdPrompt;
	Map map;  //will there be constructor issues here?  Nope!  there's defaults
	Player player;  //does player have a default constr? 
};



#endif // !GAMECONTROLLER_H
