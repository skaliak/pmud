/*
	Should player have any "attributes"?
	e.g. hit points, name, etc?  using Entity.description for name
*/


#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "entity.h"
#include "room.h"
#include "map.h"

class Player : public Entity
{
public:
	Player();
	Player(Map *m, Room *startRoom, std::string playername);
	void showExits();  //this should get an array of room pointers or something?
	void lookAround(); //gets the current room description and list of exits
	void move(Point::Direction dir);  //moves the player in this direction
protected:
	std::string name;  //can this just be description from parent class?
	Room *currentRoom;
	Room *lastRoom;
	Map *map;	
	
};

#endif