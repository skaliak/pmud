#ifndef REGION_H
#define REGION_H

#include "Point.h"
#include "entity.h"

using std::string;

class Region : public Entity
{
public:
	Region();
	Region(Point tl, Point br) : topleft(tl), bottomright(br) {}
	Region(Point tl, int width, int height);
	bool isInside(const Point p);
	virtual string obstacle() { return " an obstacle "; }
protected:
	Point topleft;
	Point bottomright;
	string entranceDesc;
	string interiorDesc;
};

#endif