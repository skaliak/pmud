#ifndef MAP_H
#define MAP_H

#define DEFAULT_MAP_SIZE 50

#include <vector>
#include "room.h"
#include "region.h"
#include "wall.h"

class Map
{
public:
	Map(int size = DEFAULT_MAP_SIZE);
	Wall* wall() { return &w; }  //probably don't need this
protected:
	void loadRegion(Region r, int index);
	std::vector<Room> rooms;  //Should this be 2D?  or an array?
	std::vector<Region> regions;
	Wall w;
};

#endif