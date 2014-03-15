#include "map.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstdlib>

using std::fstream;
using std::vector;
using std::size_t;
using std::string;
using std::rand;

Map::Map(int size)
{
	this->size = size;
	//these three operations used to all happen here...
	//needed some Functional Decomposition treatment!
	critters = new Critter[MAX_CRITTERS];
	weapons = new Item[MAX_ITEMS];

	generateRegions();
	generateRooms();
	populateRooms();
	setExits();
}

void Map::generateRegions()
{
	/*
	for (int i = 0; i < REGION_COUNT; i++)
	{
		Region r(size);
		regions.push_back(r);
	}

	//add the default region last
	regions.push_back(Region(size, true));

	//load strings from file
	loadAllRegionData();
	*/

	regions = new Region[REGION_COUNT];

	for (int i = 0; i < REGION_COUNT; ++i)
	{
		loadRegion(regions[i], i + 1);
	}
}

void Map::setExits()
{
	vector<Room *>::iterator rbeg = vrooms.begin();
	vector<Room *>::iterator rend = vrooms.end();
	vector<Room *>::iterator found;

	//determine and set exits for all the rooms!
	for (vector<Room *>::iterator currentRoom = rbeg; currentRoom != rend; ++currentRoom)
	{
		//get list of neighbor points, find matching rooms with stl find, and assign pointer to nsew
		for (int direction = 0; direction < 4; ++direction)
		{
			//4 directions
			Point neighbor = (*currentRoom)->getLoc().Neighbor((Point::Direction)direction);

			//this is a problem, because vrooms is now pointers
			found = std::find(rbeg, rend, Room(neighbor));
			if (found != rend)
			{
				(*currentRoom)->setExit(*found, (Point::Direction)direction);
			}
			else
			{
				(*currentRoom)->setExit(NULL, (Point::Direction)direction);
			}
		}

		//currentRoom->lockExits();
	}
}


void Map::generateRooms()
{
	int aSize = (size * size) + 1;
	rooms = new Room[aSize];

	int rcount = 0;
	//generate all the rooms
	for (int y = 0; y < size; ++y)
	{
		for (int x = 0; x < size; ++x)
		{

			if ((rand() % OBSTACLE_FREQUENCY) != 1) //randomly don't add rooms.  The "empty" spots will become obstacles
			{
				Point p(x, y);
				Room r(p);
				rooms[rcount] = r;
				vrooms.push_back(&rooms[rcount]);
				++rcount;
			}
		}
	}
}

void Map::populateRooms()
{
	int aSize = (size * size) + 1;
	int windex = 0;
	int cindex = 0;
	Factory factory;
	vector<Room *>::iterator rbeg = vrooms.begin();
	vector<Room *>::iterator rend = vrooms.end();

	for (auto currentRoom = rbeg; currentRoom != rend; ++currentRoom)
	{
		//all this needs to be done after r is added to the vector:

		//randomly create and put a item (a weapon) in the room
		if (rand() % WEAPON_FREQUENCY == 1 && windex != MAX_ITEMS - 1)
		{
			string name = factory.generateWeaponName();
			weapons[windex].setAttribs(name);
			//Item i = factory.getWeapon();
			//items.push_back(i);
			(*currentRoom)->putItem(&weapons[windex]);
			//currentRoom->putItem(&i);
			++windex;
		}

		//randomly create and put a critter in the room
		if (rand() % CRITTER_FREQUENCY == 1 && cindex != MAX_CRITTERS - 1)
		{
			string name = factory.getCritterName();
			critters[cindex].setDescription(name);
			//Critter c(this, &(*currentRoom), name);
			//critters.push_back(c);
			(*currentRoom)->enterCritter(&critters[cindex]);
			//currentRoom->enterCritter(&c);
			++cindex;
		}

		//determine & assign region here
		for (int i = 0; i < REGION_COUNT; ++i)
		{
			Point p = (*currentRoom)->getLoc();
			if (regions[i].isInside(p))
			{
				(*currentRoom)->setRegion(&regions[i]);
				break;
			}
		}

	}
}

/*This is obsolete
void Map::loadAllRegionData()
{
	int rindex = 1;
	for (vector<Region>::iterator curReg = regions.begin(); curReg != regions.end(); ++curReg)
	{
		loadRegion(*curReg, rindex);
		rindex++;
	}
}
*/

//read the data file and load the region data
void Map::loadRegion(Region &r, int index)
{
	string currentLine, assembledString;
	string rMarker = "$";
	string pMarker = "@";
	int count = 0;
	fstream fin(DATAFILE, fstream::in);
	size_t found;

	//find the right region to load
	while (!fin.eof() && count < index)
	{
		getline(fin, currentLine);
		found = currentLine.find(rMarker);
		if (found != string::npos)
		{
			++count;
		}
	}

	assembledString = "";

	//load the description
	while (!fin.eof())
	{
		getline(fin, currentLine);
		found = currentLine.find(pMarker);
		if (found != string::npos)
		{
			break;
		}
		else
		{
			assembledString += currentLine;
			assembledString += "\n"; //might not be necessary
		}
	}

	r.setDescription(assembledString);

	//load the random environmental phrases
	while (!fin.eof())
	{
		getline(fin, currentLine);
		found = currentLine.find(pMarker);
		if (found != string::npos)
		{
			break;
		}
		else
		{
			r.addEnvPhrase(currentLine);
		}
	}

	//load the obstacles
	while (!fin.eof())
	{
		getline(fin, currentLine);
		found = currentLine.find(pMarker);
		if (found != string::npos)
		{
			break;
		}
		else
		{
			r.addObstacle(currentLine);
		}
	}

	r.lockData();
	fin.close();
}

Room* Map::randomRoom()
{
	//return a random room on the map, for the player starting position, etc.
	int randint = rand() % vrooms.size();

	return vrooms.at(randint);
}