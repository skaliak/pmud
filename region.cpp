#include "region.h"
#include <cstdlib>

using std::rand;


Region::Region(Point tl, int width, int height)
{
	envPhraseChance = 4;
	topleft = tl;
	bottomright = tl + Point(width, height);
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

