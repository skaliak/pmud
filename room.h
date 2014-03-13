#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include "entity.h"
#include "Point.h"
#include "region.h"

class Room : public Entity
{
public:
	//constructor
	Room(Point l) : loc(l) {}

	//setters
	void setExits(Room *e, Room *w, Room *n, Room *s);
	void setE(Room *e) { E = e; }
	void setW(Room *w) { W = w; }
	void setN(Room *n) { N = n; }
	void setS(Room *s) { S = s; }
	void setExit(Room *r, Point::Direction dir);
	void setRegion(Region *reg) { region = reg; }

	//getters
	Point getLoc() { return loc; }
	Room *exit(Point::Direction dir);
	std::string listExits();
	std::string getDescription(Room *r);   //overload (or override?) of parent:  if r is a different env, get env desc

	//operators
	bool operator==(Room const& rhs) { return (loc == rhs.loc); }
protected:
	Point loc;
	Room *E;
	Room *W;
	Room *N;
	Room *S;	
	bool exitsAreSet;
	Region *region;
};


#endif
