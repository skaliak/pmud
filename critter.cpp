#include "critter.h"
#include <string>

using std::string;

Critter::Critter(Map *m, Room *startRoom, string name)
{
	map = m;
	currentRoom = startRoom;
	lastRoom = NULL;
	description = name;
}

void Critter::move(Point::Direction dir)
{

}