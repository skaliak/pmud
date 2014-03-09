
#include <iostream>
#include "Point.h"
//#include <curses.h>

/*
Point const Point::operator+(Point const& rhs)
{
	//need to rethink wrap around
	Point p;
	p.bound = (this->bound < rhs.bound) ? this->bound :
		rhs.bound;
	p.x = this->x + rhs.x;
	p.y = this->y + rhs.y;

	//if x or y are negative, add them to the bound
	p.x += ( p.x < 0) ? p.bound : 0;
	p.x -= ( p.x >= p.bound ) ? p.bound : 0;
	p.y += ( p.y < 0) ? p.bound : 0;
	p.y -= ( p.y >= p.bound ) ? p.bound : 0;
	return p;
}
*/

Point Point::Neighbor(Direction dir)
{
	switch(dir)
	{
		case NORTH:
			return nNeighbor();
		case EAST:
			return eNeighbor();
		case SOUTH:
			return sNeighbor();
		case WEST:
			return wNeighbor();
	}
}


//+ and - have been simplified
Point const Point::operator+(Point const& rhs)
{
	Point p;
	//p.bound = (this->bound < rhs.bound) ? this->bound : rhs.bound;
	p.x = this->x + rhs.x;
	p.y = this->y + rhs.y;
	return p;
}

Point const Point::operator-(Point const& rhs)
{
	Point p;
	//p.bound = (this->bound < rhs.bound) ? this->bound : rhs.bound;
	p.x = this->x - rhs.x;
	p.y = this->y - rhs.y;
	return p;
}

std::ostream &operator<<(std::ostream &out, Point p)
{
	out << p.x << "," << p.y << ":" << p.bound;
	return out;
}

/*
bool Point::operator==(Point const& rhs)
{
	if ( (this->x == rhs.x) && (this->y == rhs.y) )
	{
		return true;
	}

	return false;
}

void Point::cPrint()
{
	if(ANIMATE)
		mvaddch(this->y, this->x, PIXEL);
	else
		std::cout << " " << *this;
}
*/
