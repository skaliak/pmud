#ifndef WALL_H
#define WALL_H

#include "room.h"

class Wall : public Room
{
public:
	Wall() : Room(Point(-1,-1)) { E = 0; W = 0; N = 0; S = 0; }

	
};

#endif