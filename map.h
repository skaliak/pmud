#ifndef MAP_H
#define MAP_H

#include <vector>
#include "room.h"
#include "region.h"
#include "wall.h"

class Map
{
public:
	Map(int size);
	Wall* wall() { return &w; }
protected:
	std::vector<Room> rooms;  //Should this be 2D?  or an array?
	std::vector<Region> regions;
	Wall w;
};

#endif