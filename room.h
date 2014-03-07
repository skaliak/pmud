#ifndef ROOM_H
#define ROOM_H

#include <string>
#include "entity.h"

class Room : public Entity
{
public:
	Room();
private:
	Room *E;
	Room *W;
	Room *N;
	Room *S;	
};


#endif
