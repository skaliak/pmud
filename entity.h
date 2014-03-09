#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Entity
{
public:
	Entity();
	getDescription();

	//should only be allowed if description is ""
	setDescription(string desc) { if (description == "") description = desc; }
private:
	std::string description;
	
};
#endif