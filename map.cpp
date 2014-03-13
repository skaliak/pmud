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
	//generate regions here

	for (int i = 0; i < REGION_COUNT; i++)
	{
		Region r(size);
		regions.push_back(r);
	}

	//add the default region last
	regions.push_back(Region(size, true));

	//load strings from file
	loadAllRegionData();  

	//int loopcounter = 0;

	//generate all the rooms
	for (int y = 0; y < size; ++y)
	{
		for (int x = 0; x < size; ++x)
		{
			//++loopcounter;
			if ((rand() % OBSTACLE_FREQUENCY) != 1) //randomly don't add rooms.  The "empty" spots will become obstacles
			{
				Point p(x,y);
				Room r(p);

				//determine & assign region here
				for (vector<Region>::iterator curReg = regions.begin(); curReg != regions.end(); ++curReg)
				{
					if (curReg->isInside(p))   //isInside might be broken.
					{
						r.setRegion(&(*curReg));
						break;  //break because regions can overlap
					}
				}

				rooms.push_back(r);
			}
		}
	}

	vector<Room>::iterator rbeg = rooms.begin();
	vector<Room>::iterator rend = rooms.end();
	vector<Room>::iterator found;

	for (vector<Room>::iterator currentRoom = rbeg; currentRoom != rend; ++currentRoom)
	{
		//get list of neighbor points, find matching rooms with stl find, and assign pointer to nsew
		for (int direction = 0; direction < 4; ++direction)
		 {
		 	//4 directions
			Point neighbor = currentRoom->getLoc().Neighbor((Point::Direction)direction);
		 	found = std::find(rbeg, rend, Room(neighbor));
		 	if (found != rend)
		 	{
		 		currentRoom->setExit(&(*found), (Point::Direction)direction );
		 	}
		 	else
		 	{
				//currentRoom->setExit(wall(), (Point::Direction)direction);
				currentRoom->setExit(NULL, (Point::Direction)direction);
		 	}
		 } 

	}

}

void Map::loadAllRegionData()
{
	int rindex = 1;
	for (vector<Region>::iterator curReg = regions.begin(); curReg != regions.end(); ++curReg)
	{
		loadRegion(*curReg, rindex);
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
	int randint = rand() % rooms.size();

	return &rooms.at(randint);
}