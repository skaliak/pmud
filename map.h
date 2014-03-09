#ifndef MAP_H
#define MAP_H

#include <vector>
#include "room.h"
#include "region.h"

class Map
{
public:
	Map();
private:
	std::vector<Room> rooms;
	std::vector<Region> regions;
};

#endif