/*
	Should player have any "attributes"?
	e.g. hit points, name, etc?  using Entity.description for name
*/


#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "entity.h"
#include "room.h"
#include "map.h"
#include "critter.h"
#include "item.h"

#define PLAYER_HP 100
#define PLAYER_STR 20

using std::string;
using std::vector;

class Player : public Critter
{
public:
	Player(){}  //probably should get rid of this
	Player(Map *m, Room *startRoom, string name);

	void showExits();  //this should get an array of room pointers or something?
	void lookAround(); //gets the current room description and list of exits
	bool move(Point::Direction dir);  //moves the player in this direction

	void fightCritter();
	//virtual from parent:
	//void takeDamage(int damage, Entity source); //override from parent... is it needed?
	void die(const Entity &source);   //definitely need to override this.
	void takeDamage(int damage, Entity &source);

protected:
	vector<Item *> inventory;
	//refactored these:
	//Room *currentRoom;
	//Room *lastRoom;
	//Map *map;	
	
};

#endif