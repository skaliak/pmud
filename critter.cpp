#include "critter.h"
#include <string>
#include <cstdlib>

using std::string;
using std::rand;



Critter::Critter()
{
	map = NULL;
	currentRoom = NULL;
	lastRoom = NULL;
	description = "";
	strength = rand() % 20 + 5;
	hitPoints = rand() % 50 + 20;
	passiveness = rand() % 10;
	initialized = false;
	willAttack = false;
}

string Critter::getDescription(Critter *c)
{
	string desc = Entity::getDescription();
	if (rand() % passiveness == 1)
	{
		//set willAttack so when provoke is called, it will attack
		willAttack = true;
	}
	return desc;
}

bool Critter::move(Point::Direction dir)
{
	//need to check if it's possible to move in that direction, then
	lastRoom = currentRoom;
	currentRoom = currentRoom->exit(dir);
	if (currentRoom == NULL)
	{
		//std::cout << "\n\nYou can't go that way!\n\n";
		currentRoom = lastRoom;
		return false;
	}

	return true;
}

void Critter::setAttribs(Map *m, Room *startRoom, string name)
{
	if (! initialized)
	{
		map = m;
		currentRoom = startRoom;
		description = name;
		initialized = true;
	}
}


/*
The below functions are all for battling.  The NPC obviously isn't going to read a message, so 
for the base version, messages aren't necessary, otoh, those messages would have to come from
overrides for the player class... so maybe it would be easier to have them here?
*/

void Critter::provoke(Critter *c)
{
	//c is probably the player, but it probably really matter.
	if (willAttack)
	{
		battle(*c);
	}
}

void Critter::battle(Critter &opponent)  //maybe should return a bool for live/die?
{
	int myAttack, theirAttack;
	//fight to the death!  Ideally there should be a retreat option...
	while (stillAlive() && opponent.stillAlive())
	{
		myAttack = attack();  
		theirAttack = opponent.attack();

		takeDamage(theirAttack, opponent);
		opponent.takeDamage(myAttack, *this);
	}

	//need to know who won?
}

void Critter::takeDamage(int damage, Entity &source)  //maybe source isn't needed here either?
{
	hitPoints -= damage;

	if (hitPoints <= 0)
	{
		die(source);
	}
}

void Critter::die(const Entity &source)  //maybe source isn't needed?
{
	//teleport to graveyard and leave corpse struct behind?

	description = "a dead body";
}

int Critter::attack()  //should this be renamed?
{
	return rand() % strength;
}