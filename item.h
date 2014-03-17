/*
Peter Lindberg
CS165 w2014
Final Project
*/
#ifndef ITEM_H
#define ITEM_H

#define GPS_FLAG 1

#include <string>
#include "entity.h"
#include "room.h"

using std::string;

class Room;

class Item : public Entity
{
public:
	Item();
	//Item(string name, bool i = false, int w = 1);

	//getters
	bool isImmobile() { return immobile; }
	int getWeight() { return weight; }
	bool isHeldByPlayer() { return heldByPlayer; }  //probably don't need this?

	//setters
	void setLocation(Entity *r) { if (location == NULL) location = r; }
	void setAttribs(string name, bool i = false, int w = 1, Room *loc = NULL);
	unsigned char getEffectsFlags() { return effectsFlags; }
	void makeGps() { effectsFlags |= GPS_FLAG; description = "a GPS";  }   //turn this item into a gps
	//need a method to "take" or "pick up" the item?
	//virtual void addEffects(Player *p){}   //base version does nothing?

protected:
	//is this necessary?  Only if we want to know where all items are, I guess
	//it would be nice if this could be an Entity instead of a room
	Entity *location;  
	int weight;
	bool immobile;
	bool heldByPlayer;  //probably don't need this?
	bool initialized;
	unsigned char effectsFlags;

};


#endif