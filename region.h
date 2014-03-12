#ifndef REGION_H
#define REGION_H

#include "Point.h"
#include "entity.h"
#include <vector>

using std::string;
using std::vector;

class Region : public Entity
{
public:
	Region();
	Region(Point tl, Point br, string s) : topleft(tl), bottomright(br), entranceDesc(s), envPhraseChance(4) {}
	Region(Point tl, int width, int height, string s);  //need to create this constructor
	bool isInside(const Point p);
	virtual string obstacle();  //random obstacle phrase
	virtual string greeting() { return entranceDesc; }
	virtual string randEnv();  //{ return " you hear/see/smell a sound/thing/odor "; }
	void addObstacle(string s) { obstacles.push_back(s); }
	void addEnvPhrase(string s) { envPhrase.push_back(s); }
protected:
	int envPhraseChance;  //lower is a better chance
	Point topleft;
	Point bottomright;
	string entranceDesc;
	//string interiorDesc;
	vector<string> envPhrase;
	vector<string> obstacles;
};

#endif