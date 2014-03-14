#ifndef MAP_H
#define MAP_H

#define DEFAULT_MAP_SIZE 50
//higher = more frequent
#define OBSTACLE_FREQUENCY 8 
#define REGION_COUNT 3

#include <vector>
#include "room.h"
#include "region.h"
#include "wall.h"
#include "item.h"

using std::vector;

class Map
{
public:
	Map(int size = DEFAULT_MAP_SIZE);
	//Wall* wall() { return &w; }  //probably don't need this
	Room* randomRoom();  //random room from the map
protected:
	void loadRegion(Region &r, int index);
	void loadAllRegionData();
	vector<Room> rooms;  //Should this be 2D?  or an array? nope
	vector<Region> regions;
	vector<Item> items;  //need a function to populate this

	//Wall w;
};

#endif