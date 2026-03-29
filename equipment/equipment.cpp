#include "equipment.h"

weapon& weapon::operator=(const weapon& other)
{
	if (this != &other)
	{
		name = other.name;
		damage = other.damage;
		currentDurability = other.currentDurability;
		maxDurability = other.maxDurability;
		critModifier = other.critModifier;
		classRequirement = other.classRequirement;
		price = other.price;
	}
	return *this;
}

armor& armor::operator=(const armor& other)
{
	if (this != &other) // evitar autoassignació
	{
		name = other.name;
		resistance = other.resistance;
		currentDurability = other.currentDurability;
		maxDurability = other.maxDurability;
		evasionModifier = other.evasionModifier;
		classRequirement = other.classRequirement;
		price = other.price;
	}
	return *this;
}