
#include <iostream>
#include <cstdlib>
#include "Point.h"
#include <cmath>
#include "colors.h"

using std::rand;
using std::abs;

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

Point Point::randP(int max)
{
	int x = rand() % max;
	int y = rand() % max;

	return Point(x, y);
}

int Point::area(Point p1, Point p2)
{
	Point diff = p1 - p2;
	int x = abs(diff.x);
	int y = abs(diff.y);

	return x * y;
}

Point Point::randQuadP(int max, int quad)
{
	int xOffset = 0, yOffset = 0;
	max = max / 2;

	switch (quad)
	{
	case 2:
		xOffset = max;
		break;
	case 3:
		yOffset = max;
		break;
	case 4:
		yOffset = max;
		xOffset = max;
		break;
	}

	Point p = randP(max);
	p.x += xOffset;
	p.y += yOffset;

	return p;
}

//+ and - have been simplified
Point const Point::operator+(Point const& rhs)
{
	Point p;
	p.x = this->x + rhs.x;
	p.y = this->y + rhs.y;
	return p;
}

Point const Point::operator-(Point const& rhs)
{
	Point p;
	p.x = this->x - rhs.x;
	p.y = this->y - rhs.y;
	return p;
}

std::ostream &operator<<(std::ostream &out, Point p)
{
	//it would be nice to colorize this, but it will be annoying
	out << "(" << p.x << "," << p.y << ")";
	return out;
}


