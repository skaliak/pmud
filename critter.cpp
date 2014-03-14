#include "critter.h"
#include <string>
#include <cstdlib>

using std::string;
using std::rand;

Critter::Critter(Map *m, Room *startRoom, string name)
{
	map = m;
	currentRoom = startRoom;
	lastRoom = NULL;
	description = name;
	strength = rand() % 20 + 5;
	hitPoints = rand() % 50 + 20;
}

void Critter::move(Point::Direction dir)
{

}

//Critter* battle(Critter *c1, Critter *c2);  //this probably would work better if it were not static



/*
The below functions are all for battling.  The NPC obviously isn't going to read a message, so 
for the base version, messages aren't necessary, otoh, those messages would have to come from
overrides for the player class... so maybe it would be easier to have them here?
*/

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

void Critter::die(Entity &source)  //maybe source isn't needed?
{
	//teleport to graveyard and leave corpse struct behind
}

int Critter::attack()  //should this be renamed?
{
	return rand() % strength;
}