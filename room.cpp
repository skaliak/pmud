
#include "room.h"
#include "Point.h"
#include "colors.h"
#include <vector>

using std::string;
using std::vector;

string Room::getDescription(Room *r)
{
	string desc = description;
	desc += "\n";

	//on the next line, we need to check if r is NULL first, or there will be a nasty
	//runtime error when r->region is called!
	if (r == NULL || r->region != region)
	{
		//player entered a new region, so tell them about it
		desc += region->getDescription();
	}
	else
	{
		//this is just the name, to remind them where they are
		desc += region->getShortDesc();
	}
	
	desc += "\n";

	//add a random "flavor phrase" relevant to the environment
	desc += region->randEnv();

	//if there's an item, add it's description
	if (item != NULL && item->getDescription() != "")
	{
		desc += "\n\nOn the ground is a weapon:  ";
		desc += BMAGENTA( item->getDescription());
		desc += "\n (press 't' to take it)\n";
	}

	if (critter != NULL && critter->getDescription() != "")
	{
		desc += "\n\nThere is a creature here!\n";
		desc += RED(critter->getDescription());
		desc += "\n (press 'f' to fight it)\n";
	}

	return desc;
}

void Room::setExit(Room *r, Point::Direction dir)
{
	switch(dir)
	{
		case Point::Direction::NORTH:
			N = r;
			break;
		case Point::Direction::EAST:
			E = r;
			break;
		case Point::Direction::SOUTH:
			S = r;
			break;
		case Point::Direction::WEST:
			W = r;
			break;
	}
}

Room *Room::exit(Point::Direction dir)
{
	switch(dir)
	{
		case Point::Direction::NORTH:
			return N;
		case Point::Direction::EAST:
			return E;
		case Point::Direction::SOUTH:
			return S;
		case Point::Direction::WEST:
			return W;
		default:
			return NULL;
	}
}

string Room::listExits() 
{
	string obstacles = "";
	string exits = "Possible exits are: ";
	vector<string> o;

	if (N != NULL)
		exits += "North, ";
	else
		o.push_back(" the North ");

	if (S != NULL)
		exits += "South, ";
	else
		o.push_back(" the South ");

	if (E != NULL)
		exits += "East, ";
	else
		o.push_back(" the East ");

	if (W != NULL)
		exits += "West, ";
	else
		o.push_back(" the West ");

	exits += ".\n\n";

	if (o.size() > 0)
	{
		for (vector<string>::iterator i = o.begin(); i != o.end(); i++)
		{
			obstacles += "To";
			obstacles += *i;
			obstacles += "your path is blocked by ";
			obstacles += region->obstacle();
			obstacles += "\n";
		}
	}

	exits += obstacles;
	exits += "\n";


	return exits;
}

void Room::lockExits()
{
	if (exitsAreNotSet)
	{
		exits = { N, S, E, W };

		for (auto it = exits.begin(); it != exits.end(); ++it)
		{
			if (*it == NULL)
			{
				it = exits.erase(it);  //I have a bad feeling abou this
				if (it == exits.end())
				{
					break;
				}
			}
		}
	}

	exitsAreNotSet = false;
}

bool Room::enterCritter(Critter *c)
{
	if (critter != NULL)
		return false;
	else
	{
		critter = c;
		return true;
	}
}

void Room::putItem(Item *i) 
{ 
	item = i; 
	if (i != NULL)
	{
		i->setLocation(this);
	}
}