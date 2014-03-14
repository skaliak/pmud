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

using std::string;
using std::vector;

class Player : public Critter
{
public:
	Player(){}
	Player(Map *m, Room *startRoom, string name) : Critter(m, startRoom, name) {}
	void showExits();  //this should get an array of room pointers or something?
	void lookAround(); //gets the current room description and list of exits
	void move(Point::Direction dir);  //moves the player in this direction
protected:
	vector<Item *> inventory;
	//refactored these:
	//Room *currentRoom;
	//Room *lastRoom;
	//Map *map;	
	
};

#endif