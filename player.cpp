
#include <string>
#include <iostream>
#include "player.h"
#include "colors.h"

using std::to_string;

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
	Critter *c = currentRoom->getCritter();
	if (c != NULL)
	{
		c->provoke(this);
	}
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

void Player::takeDamage(int damage, Entity &source)
{
	Critter::takeDamage(damage, source);

	string msg = "\nyou have " + to_string(hitPoints) + " hitpoints left\n";
	std::cout << RED(msg);

	if (hitPoints < 10)
	{
		msg = "\nyou are almost dead!\n";
		std::cout << BYELLOW(msg);
	}
}

void Player::die(const Entity &source)
{
	std::cout << "\n\nOh no!  You were killed by "
		<< source.getDescription() << "\n\n"
		<< "GAME OVER\n\n";

	exit(0);
	//game over?
}

void Player::fightCritter()
{
	Critter *c = currentRoom->getCritter();
	if (c != NULL)
	{
		battle(*c);
	}
	else
	{
		std::cout << "\nnothing here to fight!\n";

	}

}