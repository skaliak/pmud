#ifndef CRITTER_H
#define CRITTER_H

#include "entity.h"
#include "room.h"
#include "map.h"
#include <string>

using std::string;

/*
struct corpse  //a dead critter turns into this?
{
	string desc;
	Room *loc;
};
*/

class Map;
class Room;

class Critter : public Entity
{
public:
	Critter();
	//Critter(Map *m, Room *startRoom, string name);
	virtual bool move(Point::Direction dir);
	void setAttribs(Map *m, Room *startRoom, string name);
	bool stillAlive() { return (hitPoints > 0); }

	int attack();

	virtual void takeDamage(int damage, Entity &source); //take damage
protected:
	//virtual void teleport(Room *r);  //is it necessary?  How does critter get to the "graveyard" when it dies?  
	//Does graveyard even need to be a real room?
	virtual void die(Entity &source);  //removes critter, or just turns it into a dead body?
	virtual void battle(Critter &opponent);   //since this is protected, does it ever get called by an npc?
	bool initialized;
	int hitPoints;
	int strength;
	Room *currentRoom;
	Room *lastRoom;
	Map *map;

};




#endif // !CRITTER_H
