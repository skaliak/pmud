#ifndef FACTORY_H
#define FACTORY_H

#define ADDSP(x) x += " ";

#include "item.h"
#include "critter.h"
#include <vector>
#include <string>
#include <cstdlib>

using std::vector;
using std::string;
using std::rand;

class Factory
{
public:
	Factory();
	string generateWeaponName();  //this could return a struct instead...
	Item getWeapon();
	string getCritterName();   //generate a random critter -- or just it's name

	template<typename T>
	T randElement(vector<T> source)
	{
		int randIndex = rand() % source.size();
		return source.at(randIndex);
	}
private:
	vector<string> wMaterials;
	vector<string> wKinds;
	vector<string> wConditions;
	vector<string> wQualityAdjs;
	vector<string> wQualityyNouns;
	vector<string> cNames;
	vector<string> cKinds;

	vector<vector<string>> weaponWords;

	//is this going to work??

};

#endif // !FACTORY_H
