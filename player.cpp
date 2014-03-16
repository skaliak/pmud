
#include <string>
#include <iostream>
#include "player.h"
#include "colors.h"


Player::Player(Map *m, Room *startRoom, std::string playername )
{
	map = m;
	currentRoom = startRoom;
	lastRoom = NULL;
	description = playername;
	strength = PLAYER_STR;
	hitPoints = PLAYER_HP;
	hasGps = true;
}


//gets the current room description and list of exits
void Player::lookAround()
{

	//get the description of the room, at least
	std::string roomDesc = currentRoom->getDescription(lastRoom);
	std::cout << "\n\n" << roomDesc << "\n\n";
	if (hasGps)
	{
		std::cout << "Your GPS shows that your coordinates are: " <<
			currentRoom->getLoc() << "\n";
	}

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

	string msg = "\nyou have " + tos(hitPoints) + " hitpoints left\n";
	std::cout << RED(msg);

	if (hitPoints < 10)
	{
		msg = "\nyou are almost dead!\n";
		std::cout << BYELLOW(msg);
	}
}

void Player::die(const Entity &source)
{
	string msg = "\n\nOh no!  You were killed by " +
		source.getDescription() + "\n\n";
	std::cout << BYELLOW(msg);
	msg = "GAME OVER\n\n";
	std::cout << BRED(msg);

	exit(0);
	//game over?
}

void Player::fightCritter()
{
	Critter *c = currentRoom->getCritter();
	if (c != NULL && c->stillAlive())
	{
		battle(*c);
	}
	else
	{
		std::cout << "\nnothing here to fight!\n";

	}

}

void Player::showInventory()
{
	std::cout << "\nYour inventory: \n";
	for (auto it = inventory.begin(); it != inventory.end(); ++it)
	{
		std::cout << BMAGENTA((*it)->getDescription()) << "\n";
	}
}

void Player::takeItem()
{
	Item *i = currentRoom->getItem();
	if (i != NULL)
	{
		string idesc = i->getDescription();
		std::cout << "\nYou add " << BMAGENTA(idesc) <<
			" to your inventory.\n(press 'i' to show inventory)\n\n";
		inventory.push_back(i);
		currentRoom->putItem(NULL);
	}
	else
	{
		std::cout << "\nThere's nothing here to take!\n";
	}
}