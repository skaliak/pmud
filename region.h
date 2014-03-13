#ifndef REGION_H
#define REGION_H

#include "Point.h"
#include "entity.h"
#include <vector>

#define DATAFILE "env_data.txt"
#define EPHRASE_CHANCE 4

using std::string;
using std::vector;

class Region : public Entity
{
public:
	Region();  //remove this one?
	Region(Point tl, Point br) : topleft(tl), bottomright(br), envPhraseChance(4), dataNotLoaded(true) {}
	Region(Point tl, int width, int height); 
	//constructor that just takes size (i.e. map size), and generates a random region within that area
	Region(int size, bool defaultRegion = false);

	//is the point inside the region?  We need this to associate region pointers with rooms
	bool isInside(const Point p);

	//getters
	virtual string obstacle();  //random obstacle phrase
	//virtual string greeting() { return entranceDesc; }   //use parent member
	virtual string randEnv();  //{ return " you hear/see/smell a sound/thing/odor "; }
	bool readyToLoad() { return dataNotLoaded; }
	int getArea() { return area; }

	//setters
	void addObstacle(string s) { if (dataNotLoaded) obstacles.push_back(s); }
	void addEnvPhrase(string s) { if (dataNotLoaded) envPhrase.push_back(s); }
	void setDescription(string s) { if (dataNotLoaded) description = s; }
	void lockData() { if (dataNotLoaded) dataNotLoaded = false; }
protected:
	bool dataNotLoaded;
	int envPhraseChance;  //lower is a better chance
	int area;
	Point topleft;
	Point bottomright;
	//string entranceDesc;  //use parent for this
	//string interiorDesc;
	vector<string> envPhrase;
	vector<string> obstacles;

};

#endif