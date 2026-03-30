#include "equipment.h"

weapon& weapon::operator=(const weapon& other)
{
	if (this != &other)
	{
		setName(other.getName());
		setClassRequirement(other.getClassRequirement());
		setPrice(other.getPrice());
		damage = other.damage;
		currentDurability = other.currentDurability;
		maxDurability = other.maxDurability;
		critModifier = other.critModifier;
		minLevel = other.minLevel;
	}
	return *this;
}

armor& armor::operator=(const armor& other)
{
	if (this != &other)
	{
		setName(other.getName());
		setClassRequirement(other.getClassRequirement());
		setPrice(other.getPrice());
		resistance = other.resistance;
		currentDurability = other.currentDurability;
		maxDurability = other.maxDurability;
		evasionModifier = other.evasionModifier;
		minLevel = other.minLevel;
	}
	return *this;
}