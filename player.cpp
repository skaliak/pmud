
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
void Player::move(Point::Direction dir)
{
	//need to check if it's possible to move in that direction, then
	lastRoom = currentRoom;
	currentRoom = currentRoom->exit(dir);
	if (currentRoom == NULL)
	{
		std::cout << "\n\nYou can't go that way!\n\n";
		currentRoom = lastRoom;
	}
	else
	{
		lookAround();
	}
}