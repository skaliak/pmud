
#include <string>
#include <iostream>
#include "player.h"


Player::Player(Map *m, Room *startRoom, std::string playername )
{
	map = m;
	currentRoom = startRoom;
	lastRoom = NULL;
	description = playername;
	strength = PLAYER_STR;
	hitPoints = PLAYER_HP;
}


//gets the current room description and list of exits
void Player::lookAround()
{
	//get the description of the room, at least
	std::string roomDesc = currentRoom->getDescription(lastRoom);
	std::cout << "\n\n" << roomDesc << "\n\n";
	std::cout << currentRoom->listExits() << "\n\n";
}

//moves the player in this direction
bool Player::move(Point::Direction dir)
{
	bool result = Critter::move(dir);
	if (!result)
	{
		std::cout << "\n\nYou can't go that way!\n\n";
	}
	else
	{
		lookAround();
	}

	return result;
}