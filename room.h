#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include "entity.h"
#include "Point.h"

class Room : public Entity
{
public:
	Room(Point l) : loc(l) {}
	Point getLoc() { return loc; }
	void setExits(Room *e, Room *w, Room *n, Room *s);
	void setE(Room *e) { E = e; }
	void setW(Room *w) { W = w; }
	void setN(Room *n) { N = n; }
	void setS(Room *s) { S = s; }
	void findAndSetExits(std::vector<Room> &v, int mapsize);  //is this necessary?
	void setExit(Room *r, Point::Direction dir);
	*Room exit(Point::Diredtion dir);

	bool operator==(Room const& rhs) { return (loc == rhs.loc); }
protected:
	Point loc;
	Room *E;
	Room *W;
	Room *N;
	Room *S;	
};


#endif
