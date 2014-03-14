#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Entity
{
public:
	//constructors
	Entity() : description("") {}
	Entity(std::string desc) : description(desc) {}

	//we (probably) shouldn't ever copy an entity -- this throws an exception if that happens:
	Entity(Entity& other) { throw("Copy constructor called on Entity! Didn't pass by reference!"); }

	//getters
	virtual std::string getDescription() { return description; }

	//should only be allowed if description is ""
	virtual void setDescription(std::string desc) { if (description == "") description = desc; }
protected:
	std::string description;
	
};
#endif