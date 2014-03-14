#ifndef FACTORY_H
#define FACTORY_H

#include "item.h"
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
	string generateWeapon();
private:
	vector<string> wMaterials;
	vector<string> wKinds;
	vector<string> wConditions;
	vector<string> wQualityAdjs;
	vector<string> wQualityyNouns;

	vector<vector<string>> weaponWords;

	//is this going to work??
	template<typename T>
	T randElement(vector<T> source)
	{
		int randIndex = rand() % source.size();
		return source.at(randIndex);
	}
};




#endif // !FACTORY_H
