#include "item.h"
#include "factory.h"


Item::Item()
{
	description = "";
	immobile = false;
	weight = 1;
	location = NULL;
	heldByPlayer = false;
	initialized = false;
	effectsFlags = 0;
}

void Item::setAttribs(string name, bool i, int w, Room *loc)
{
	if (! initialized)
	{
		description = name;
		immobile = i;
		weight = w;
		location = loc;
		initialized = true;
	}
}