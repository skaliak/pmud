#include "factory.h"
#include "room.h"
#include "item.h"
#include <cstdlib>

using std::rand;

Factory::Factory()
{
	wConditions = { "shiny", "ancient", "slippery", "stinky", "smokey", "battered", "weathered", "rusty", 
		"sparkling", "glowing", "humming", "vibrating", "singing", "dancing", "blurry", "plain", "boring" };
	wMaterials = { "titanium", "wooden", "plastic", "copper", "steel", "iron", "gold", "aluminum", "cardboard",
		"magnesium", "carbon fiber", "polyester", "nylon", "tungsten", "beryllium" };
	wKinds = { "dagger", "long sword", "broad sword", "short sword", "butter knife", "steak knife", "spatula", "fly swatter",
		"spear", "club", "shillelagh", "hammer", "mitre saw", "slingshot", "throwing rock", "pea shooter", "pointy stick", "nerf gun" };
	wQualityAdjs = { "demonic", "angelic", "chilling", "infernal", "awful", "awesome", "unspeakable", "wimpy", "weak",
		"unpredictable", "unstoppable", "glorious", "sneaky", "patient", "virtuous", "stinky", "deviant", "righteous" };
	wQualityyNouns = { "righteousness", "chaoticalness", "splendor", "smashing", "decay", "squalor", "patriotism",
		"freedom", "justice", "dispair", "calm", "silliness", "deceit", "bravery", "brilliance", "knowledge",
		"anger", "peace", "love", "patience", "itchyness", "flakiness", "annoyance", "shadows" };

	cNames = { "Jeff", "Steve", "Francis", "Frank", "Bob", "Joe", "Tom", "Fred", "Chauncy", "Harold", "Allan", "George", "Jim", "Jack" };
	cKinds = { "an orc", "a kobold", "a giant spider", "a bear", "a wolf", "a gelatinous cube", "a crocodile",
		"a land shark", "a demon", "a lawyer", "an anthropomorphic wardrobe" };

	weaponWords = { wConditions, wMaterials, wKinds, wQualityAdjs, wQualityyNouns };
}

string Factory::generateWeaponName()
{
	string weapon = "The ";

	for (auto it = weaponWords.begin(); it != weaponWords.end(); ++it)
	{
		weapon += randElement(*it);
		if (*it == wKinds)
			weapon += " of";
		ADDSP(weapon);
	}

	return weapon;
}

/* not worth the trouble
Item Factory::getWeapon()
{
	Item weapon;
	bool immobile = false;
	string wName = generateWeaponName();
	int weight = rand() % 15;

	if ((rand() % 20) == 10)
		immobile = true;

	weapon = Item(wName, immobile, weight);

	return weapon;
}
*/

string Factory::getCritterName()
{
	string name = randElement(cNames);
	string desc = randElement(cKinds);

	desc += " named ";
	desc += name;

	return desc;
}