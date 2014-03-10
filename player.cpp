
#include <string>
#include "player.h"

Player::Player()
{
	//?
}

//this should get an array of room pointers or something?
void Player::showExits()
{

}

//gets the current room description and list of exits
void Player::lookAround()
{
	//get the description of the room, at least
	std::string roomDesc = currentRoom->getDescription();
}

//moves the player in this direction
void Player::move(Point::Direction dir)
{
	//need to check if it's possible to move in that direction, then
	//lastRoom = currentRoom and
	//currentRoom = currentRoom->direction
}