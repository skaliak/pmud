#ifndef REGION_H
#define REGION_H

#include "Point.h"
#include "entity.h"
#include <vector>

#define DATAFILE "env_data.txt"

using std::string;
using std::vector;

class Region : public Entity
{
public:
	Region();
	Region(Point tl, Point br) : topleft(tl), bottomright(br), envPhraseChance(4), dataNotLoaded(true) {}
	Region(Point tl, int width, int height); 
	//add a constructor that just takes size, and generates a random region within that 

	bool isInside(const Point p);

	virtual string obstacle();  //random obstacle phrase
	//virtual string greeting() { return entranceDesc; }   //use parent member
	virtual string randEnv();  //{ return " you hear/see/smell a sound/thing/odor "; }
	//void loadData();
	void addObstacle(string s) { if (dataNotLoaded) obstacles.push_back(s); }
	void addEnvPhrase(string s) { if (dataNotLoaded) envPhrase.push_back(s); }
	void setDescription(string s) { if (dataNotLoaded) description = s; }
	void lockData() { if (dataNotLoaded) dataNotLoaded = false; }
	bool readyToLoad() { return dataNotLoaded; }
protected:
	bool dataNotLoaded;
	int envPhraseChance;  //lower is a better chance
	Point topleft;
	Point bottomright;
	//string entranceDesc;  //use parent for this
	//string interiorDesc;
	vector<string> envPhrase;
	vector<string> obstacles;
};

#endif