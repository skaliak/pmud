#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Entity
{
public:
	Entity() : description("") {}
	Entity(std::string desc) : description(desc) {}
	void getDescription();

	//should only be allowed if description is ""
	void setDescription(std::string desc) { if (description == "") description = desc; }
protected:
	std::string description;
	
};
#endif