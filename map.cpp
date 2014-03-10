#include "map.h"
#include <vector>

using std::vector;

Map::Map(int size)
{
	//Room **tmpArr;
	//tmpArr = new Room[size][size];

	//generate all the rooms
	for (int y = 0; y < size; ++y)
	{
		for (int x = 0; x < size; ++x)
		{
			Point p(x,y);
			Room r(p);
			//tmpArr[x][y] = r;
			rooms.push_back(r);
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
		 	Point neighbor = currentRoom->getLoc().Neighbor(direction);
		 	found = find(rbeg, rend, Room(neighbor));
		 	if (found != rend)
		 	{
		 		currentRoom->setExit(&(*found), direction );
		 	}
		 	else
		 	{
		 		currentRoom->setExit(wall(), direction);
		 	}
		 } 

	}
	



}