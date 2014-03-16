#include "map.h"
#include "colors.h"
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
using std::cout;

Map::Map(int size)
{
	this->size = size;
	//these three operations used to all happen here...
	//needed some Functional Decomposition treatment!
	
	//critters = new Critter[MAX_CRITTERS];
	//weapons = new Item[MAX_ITEMS];

	for (int i = 0; i < MAX_CRITTERS; ++i)
	{
		vcritters.push_back(new Critter());
	}
	
	for (int i = 0; i < MAX_ITEMS; ++i)
	{
		items.push_back(new Item());
	}

	generateRegions();
	generateRooms();
	populateRooms();
	setExits();

	cout << "\n\n\n";
}

void Map::generateRegions()
{
	string msg = "\nloading regions ";
	cout << BLUE(msg);
	for (int i = 0; i < REGION_COUNT; i++)
	{
		vregions.push_back(new Region(size));
	}

	//add the default region last
	vregions.push_back(new Region(size, true));

	//load strings from file
	loadAllRegionData();
	
	/*
	regions = new Region[REGION_COUNT];

	for (int i = 0; i < REGION_COUNT; ++i)
	{
		loadRegion(regions[i], i + 1);
	}
	*/
}

 //old vector version
void Map::setExits()
{
	string msg = "\nsetting room exits";
	cout << BLUE(msg);
	vector<Room *>::iterator rbeg = vrooms.begin();
	vector<Room *>::iterator rend = vrooms.end();
	vector<Room *>::iterator found;
	int dotcounter = 0;
	//determine and set exits for all the rooms!
	for (vector<Room *>::iterator currentRoom = rbeg; currentRoom != rend; ++currentRoom)
	{
		//get list of neighbor points, find matching rooms with stl find, and assign pointer to nsew
		for (int direction = 0; direction < 4; ++direction)
		{
			//4 directions
			Point neighbor = (*currentRoom)->getLoc().Neighbor((Point::Direction)direction);

			//this is a problem, because vrooms is now pointers
			//solution:  don't use find, compare manually!  
			//found = std::find(rbeg, rend, Room(neighbor));
			//this is sloooow
			for (found = rbeg; found != rend; ++found)
			{
				if (**found == Room(neighbor))
				{
					break;
				}
			}

			if (found != rend)
			{
				(*currentRoom)->setExit(*found, (Point::Direction)direction);
			}
			else
			{
				(*currentRoom)->setExit(NULL, (Point::Direction)direction);
			}
		}

		if(dotcounter % 100 == 0) cout << ".";

		++dotcounter;
		//currentRoom->lockExits();  //see if this works now
	}
}

/* new version that isn't so great after all
void Map::setExits()
{
	int rcount = (size * size);

	//determine and set exits for all the rooms!
	for (int i = 0; i < rcount; ++i)
	{
		//get list of neighbor points, find matching rooms with stl find, and assign pointer to nsew
		for (int direction = 0; direction < 4; ++direction)
		{
			//4 directions
			Point neighbor = rooms[i].getLoc().Neighbor((Point::Direction)direction);

			//this is a problem, because vrooms is now pointers
			Room *found = std::find(rooms, rooms + rcount -1, Room(neighbor));
			if (found != rooms + rcount)
			{
				rooms[i].setExit(found, (Point::Direction)direction);
			}
			else
			{
				rooms[i].setExit(NULL, (Point::Direction)direction);
			}
		}

		//currentRoom->lockExits();
	}
}
*/

void Map::generateRooms()
{
	string msg = "\ngenerating rooms ";
	cout << BLUE(msg);
	//int aSize = (size * size) + 1;
	//rooms = new Room[aSize];

	//int rcount = 0;
	//generate all the rooms
	for (int y = 0; y < size; ++y)
	{
		for (int x = 0; x < size; ++x)
		{

			if ((rand() % OBSTACLE_FREQUENCY) != 1) //randomly don't add rooms.  The "empty" spots will become obstacles
			{
				Point p(x, y);
				//Room r(p);
				//rooms[rcount] = r;
				//vrooms.push_back(&rooms[rcount]);
				//++rcount;
				vrooms.push_back(new Room(p));
			}
		}
	}
}

void Map::populateRooms()
{
	string msg = "\npopulating rooms ";
	cout << BLUE(msg);
	int aSize = (size * size) + 1;
	int windex = 0;
	int cindex = 0;
	Factory factory;
	vector<Room *>::iterator rbeg = vrooms.begin();
	vector<Room *>::iterator rend = vrooms.end();
	auto witerator = items.begin();
	auto wend = items.end();
	auto criterator = vcritters.begin();
	auto crend = vcritters.end();

	for (auto currentRoom = rbeg; currentRoom != rend; ++currentRoom)
	{
		//all this needs to be done after r is added to the vector:

		//randomly create and put a item (a weapon) in the room
		if (rand() % WEAPON_FREQUENCY == 1 && witerator != wend)
		{
			string name = factory.generateWeaponName();
			//weapons[windex].setAttribs(name);
			(*witerator)->setAttribs(name);
			//Item i = factory.getWeapon();
			//items.push_back(i);
			//(*currentRoom)->putItem(&weapons[windex]);
			(*currentRoom)->putItem(*witerator);
			//currentRoom->putItem(&i);
			//++windex;
			++witerator;
		}

		//randomly create and put a critter in the room
		if (rand() % CRITTER_FREQUENCY == 1 && criterator != crend)
		{
			string name = factory.getCritterName();
			//critters[cindex].setDescription(name);
			(*criterator)->setDescription(name);
			//Critter c(this, &(*currentRoom), name);
			//critters.push_back(c);
			//(*currentRoom)->enterCritter(&critters[cindex]);
			(*currentRoom)->enterCritter(*criterator);
			//currentRoom->enterCritter(&c);
			//++cindex;
			++criterator;
		}

		/*//determine & assign region here
		for (int i = 0; i < REGION_COUNT; ++i)
		{
			Point p = (*currentRoom)->getLoc();
			if ((*vregions[i]).isInside(p))
			{
				(*currentRoom)->setRegion(vregions[i]);
				break;
			}
		}
		*/

		for (auto it = vregions.begin(); it != vregions.end(); ++it)
		{
			Point p = (*currentRoom)->getLoc();
			if ((*it)->isInside(p))
			{
				(*currentRoom)->setRegion(*it);
				break;
			}
		}

		if ((*currentRoom)->getRegion() == NULL)
		{
			throw("error! region not set!");
		}
	}
}


void Map::loadAllRegionData()
{
	string msg = "\nloading region strings from file ";
	cout << BLUE(msg);
	int rindex = 1;
	for (auto curReg = vregions.begin(); curReg != vregions.end(); ++curReg)
	{
		loadRegion(**curReg, rindex);
		rindex++;
	}
}


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
			string shortDesc = currentLine.substr(1, string::npos);
			r.setShortDesc(shortDesc);
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




Map::~Map()
{
	cleanUp(vregions);
	cleanUp(vcritters);
	cleanUp(items);
	cleanUp(vrooms);
}
