#include "map.h"
#include <vector>

using std::vector;

Map::Map(int size)
{
	Room **tmpArr;
	tmpArr = new Room[size][size];

	//generate all the rooms
	for (int y = 0; y < size; ++y)
	{
		for (int x = 0; x < size; ++x)
		{
			Point p(x,y);
			Room r(p);
			tmpArr[x][y] = r;
			//rooms.push_back(r);
		}
	}

	//iterate through rooms and set exits
	for (int y = 0; y < size; ++y)
	{
		for (int x = 0; x < size; ++x)
		{
			
		}
	}
	



}