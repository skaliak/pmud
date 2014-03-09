#ifndef REGION_H
#define REGION_H

#include "Point.h"
#include "entity.h"

class Region : public Entity
{
public:
	Region();
	Region(Point tl, Point br) : topleft(tl), bottomright(br), description("") {}
	Region(Point tl, int width, int height);
	bool isInside(const Point p);
private:
	Point topleft;
	Point bottomright;
};

#endif