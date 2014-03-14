#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "entity.h"
#include "room.h"

class Item : public Entity
{
public:
	Item();
protected:
	Room *location;  //is this necessary?
	int weight;
	bool immobile;
};

#endif