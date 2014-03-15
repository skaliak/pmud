#ifndef MAP_H
#define MAP_H

#define DEFAULT_MAP_SIZE 50
//higher = more frequent
#define OBSTACLE_FREQUENCY 8 
#define REGION_COUNT 3
#define WEAPON_FREQUENCY 6
#define CRITTER_FREQUENCY 12
#define MAX_ITEMS 300
#define MAX_CRITTERS 200

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
	//vector<Region> regions;
	//vector<Item> items;  //need a function to populate this
	//vector<Critter> critters;

	Room *rooms;
	Region *regions;
	Item *weapons;
	Critter *critters;
	
};

#endif