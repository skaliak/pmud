#ifndef ITEM_H
#define ITEM_H

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
	bool isHeldByPlayer() { return heldByPlayer; }

	//setters
	void setLocation(Entity *r) { if (location == NULL) location = r; }
	void setAttribs(string name, bool i = false, int w = 1, Room *loc = NULL);

	//need a method to "take" or "pick up" the item?
	//virtual void addEffects(Player *p){}   //base version does nothing?

protected:
	//is this necessary?  Only if we want to know where all items are, I guess
	//it would be nice if this could be an Entity instead of a room
	Entity *location;  
	int weight;
	bool immobile;
	bool heldByPlayer;
	bool initialized;
};

#endif