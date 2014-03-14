#ifndef CRITTER_H
#define CRITTER_H

#include "entity.h"
#include "room.h"
#include "map.h"
#include <string>

using std::string;

struct corpse  //a dead critter turns into this?
{
	string desc;
	Room *loc;
};

class Critter : public Entity
{
public:
	Critter(){}
	Critter(Map *m, Room *startRoom, string name);
	virtual void move(Point::Direction dir);

	bool stillAlive() { return (hitPoints > 0); }

	//need to create these functions:
	int attack();
	//static Critter* battle(Critter *c1, Critter *c2);  //this probably would work better if it were not static
	virtual void takeDamage(int damage, Entity &source); //take damage
protected:
	virtual void die(Entity &source);  //removes critter, or just turns it into a dead body?
	virtual void battle(Critter &opponent);   //since this is protected, does it ever get called by an npc?
	int hitPoints;
	int strength;
	Room *currentRoom;
	Room *lastRoom;
	Map *map;

};




#endif // !CRITTER_H
