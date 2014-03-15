#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include "entity.h"
#include "Point.h"
#include "region.h"
#include "item.h"
#include "critter.h"

using std::string;

class Item;
class Critter;

class Room : public Entity
{
public:
	//constructor
	Room(Point l) : loc(l), item(NULL), critter(NULL) {}

	//setters
	//void setExits(Room *e, Room *w, Room *n, Room *s);
	void lockExits();  //this gets called by Map after all exits are set.
	void setE(Room *e) { E = e; }
	void setW(Room *w) { W = w; }
	void setN(Room *n) { N = n; }
	void setS(Room *s) { S = s; }
	void setExit(Room *r, Point::Direction dir);
	void setRegion(Region *reg) { region = reg; }
	void putItem(Item *i) { item = i; }
	bool enterCritter(Critter *c);  //return false if there's already a critter present

	//getters
	Point getLoc() { return loc; }
	Room *exit(Point::Direction dir);
	string listExits();
	string getDescription(Room *r);   //overload (or override?) of parent:  if r is a different env, get env desc
	Item *getItem() { return item; }

	//operators
	bool operator==(Room const& rhs) { return (loc == rhs.loc); }
protected:
	Item *item;  //only 1 item per room?  It is automatically detected and described by getDescription
	Critter *critter;
	Point loc;
	Room *E;
	Room *W;
	Room *N;
	Room *S;
	vector<Room *> exits;  //need this to enable critters to move autonomously.  But how does it get populated?  Should have been a std::map
	bool exitsAreNotSet;
	Region *region;
};


#endif
