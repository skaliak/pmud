#include "region.h"
#include <cstdlib>

using std::rand;


Region::Region(Point tl, int width, int height)
{
	envPhraseChance = EPHRASE_CHANCE;
	topleft = tl;
	bottomright = tl + Point(width, height);
	dataNotLoaded = false;
}

Region::Region(int size)  //make a new region within the given map size
{
	int startQuad, endQuad;
	startQuad = rand() % 3 + 1;

	if (startQuad == 1)
		endQuad = rand() % 4 + 2;
	else
		endQuad = 4;

	topleft = Point::randQuadP(size, startQuad);  //top left point
	bottomright = Point::randQuadP(size, endQuad);    //bottom right point

	envPhraseChance = EPHRASE_CHANCE;
	dataNotLoaded = false;
}

bool Region::isInside(const Point p)
{
	int xlow = topleft.getX();
	int xhigh = bottomright.getX();
	int ylow = topleft.getY();
	int yhigh = bottomright.getY();
	int x = p.getX();
	int y = p.getY();

	return ( (xlow <= x) && (x <= xhigh) && (ylow <= y) && (y <= yhigh) );
}

string Region::obstacle()
{
	int randint = rand() % obstacles.size();
	return obstacles[randint];
}

string Region::randEnv()
{
	if ((rand() % envPhraseChance) == 1)
	{
		int randint = rand() % envPhrase.size();
		return envPhrase[randint];
	}
	return "";
}

