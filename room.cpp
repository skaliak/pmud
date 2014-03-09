
#include "room.h"
#include "Point.h"

void Room::findAndSetExits(vector<Room> &v, int mapsize)
{
	//determine neighbors 

}

void Room::setExit(Room *r, Direction dir)
{
	switch(dir)
	{
		case NORTH:
			N = r;
			break;
		case EAST:
			E = r;
			break;
		case SOUTH:
			S = r;
			break;
		case WEST:
			W = r;
			break;
	}

}