#ifndef ROOM_H
#define ROOM_H

#include <string>
#include "entity.h"

class Room : public Entity
{
public:
	Room(Point l) : loc(l) {}
	Point getLoc() { return loc; }
	void setExits(Room e, Room w, Room n, Room s);
private:
	Point loc;
	Room *E;
	Room *W;
	Room *N;
	Room *S;	
};


#endif
