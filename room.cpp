
#include "room.h"
#include "Point.h"
#include <vector>

using std::string;
using std::vector;

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

	exits += ".\n";

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

	return ;
}