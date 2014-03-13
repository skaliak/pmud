#ifndef POINT_H
#define POINT_H

#define MAX_BOUND 500

#include <iostream>

class Point
{
protected:
	int bound, x, y;
	//static const char PIXEL = '#';
public:
	//constructors
	Point() : bound(MAX_BOUND) {}
	Point(int a, int b) : bound(MAX_BOUND), x(a), y(b) {} 
	Point(int a, int b, int boundary) : bound(boundary), x(a), y(b) {}

	static Point randP(int max);  //generate point no bigger than max
	static Point randQuadP(int max, int quad);
	static int area(Point p1, Point p2);

	enum Direction { NORTH, EAST, SOUTH, WEST };
	
	//tests
	bool isOutOfBounds(int boundary) { return ( (x < 0) | (y < 0) | (x >= boundary) | (y >= boundary) ); }

	//getters
	Point nNeighbor() { return Point(x, y - 1); }
	Point sNeighbor() { return Point(x, y + 1); }
	Point eNeighbor() { return Point(x + 1, y); }
	Point wNeighbor() { return Point(x - 1, y); }
	Point Neighbor(Direction dir);
	int getX() const { return x; }
	int getY() const { return y; }

	//operators
	Point const operator+(Point const& rhs);
	Point const operator-(Point const& rhs);
	bool operator==(Point const& rhs) { return ((x == rhs.x) && (y == rhs.y)); }
	friend std::ostream &operator<<(std::ostream &out, Point p);
};


#endif
