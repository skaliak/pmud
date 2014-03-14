#ifndef CRITTER_H
#define CRITTER_H

#include "entity.h"
#include "room.h"
#include "map.h"
#include <string>

using std::string;

class Critter : public Entity
{
public:
	Critter(){}
	Critter(Map *m, Room *startRoom, string name);
	virtual void move(Point::Direction dir);

	//need to create these two functions:
	int getDamage();
	static Critter* battle(Critter *c1, Critter *c2);  //this probably would work better if it were not static

protected:
	int hitPoints;
	int strength;
	Room *currentRoom;
	Room *lastRoom;
	Map *map;

};




#endif // !CRITTER_H
