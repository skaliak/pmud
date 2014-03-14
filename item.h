#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "entity.h"
#include "room.h"

class Item : public Entity
{
public:
	Item();
	Item(string name, bool immobile = false, int weight = 1) : Entity(name), immobile(immobile), weight(weight), location(NULL) {}

	//getters
	bool isImmobile() { return immobile; }
	int getWeight() { return weight; }
	bool isHeldByPlayer() { return heldByPlayer; }

	//setters
	void setLocation(Room *r) { if (location == NULL) location = r; }

	//need a method to "take" or "pick up" the item?

protected:
	Room *location;  //is this necessary?  Only if we want to know where all items are, I guess
	int weight;
	bool immobile;
	bool heldByPlayer;
};

#endif