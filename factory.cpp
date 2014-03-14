#include "factory.h"

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