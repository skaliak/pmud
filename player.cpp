
#include <string>
#include <iostream>
#include "player.h"

/* refactored to class Critter
Player::Player(Map *m, Room *startRoom, std::string playername )
{
	map = m;
	currentRoom = startRoom;
	lastRoom = NULL;
	description = playername;
}
*/

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

	return result;
}