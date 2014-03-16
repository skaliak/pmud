#ifndef MAP_H
#define MAP_H

#define DEFAULT_MAP_SIZE 50
//higher = more frequent
#define OBSTACLE_FREQUENCY 8 
#define REGION_COUNT 3
#define WEAPON_FREQUENCY 12
#define CRITTER_FREQUENCY 5
#define MAX_ITEMS 200
#define MAX_CRITTERS 550

#include <vector>
#include "room.h"
#include "region.h"
#include "item.h"
#include "factory.h"

using std::vector;

class Room;
class Item;
class Factory;
class Critter;
class Region;

class Map
{
public:
	Map(int size = DEFAULT_MAP_SIZE);
	~Map();
	Room* randomRoom();  //random room from the map
protected:
	void generateRegions();
	void setExits();
	void generateRooms();
	void populateRooms();

	void loadRegion(Region &r, int index);
	void loadAllRegionData();

	int size;
	
	//maybe the should all be arrays
	vector<Room *> vrooms;  //Should this be 2D?  or an array? nope
	vector<Region *> vregions;
	vector<Item *> items;  //need a function to populate this
	vector<Critter *> vcritters;

	//Room *rooms;
	//Region *regions;
	//Item *weapons;
	//Critter *critters;
	
	template<typename T>
	void cleanUp(T v)
	{
		while (!v.empty())
		{
			delete v.back();
			v.pop_back();
		}
	}
};

#endif