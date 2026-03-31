#include "items.h"

using namespace std;

baseObject& baseObject::operator=(const baseObject& other) {
	if (this != &other) {
		name = other.name;
		description = other.description;
		price = other.price;
	}
	return *this;
}
weapon& weapon::operator=(const weapon& other)
{
	if (this != &other)
	{
		setName(other.getName());
		setDescription(other.getDescription());
		classRequirement = other.classRequirement;
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
		setDescription(other.getDescription());		
		classRequirement = other.classRequirement;
		setPrice(other.getPrice());
		resistance = other.resistance;
		currentDurability = other.currentDurability;
		maxDurability = other.maxDurability;
		evasionModifier = other.evasionModifier;
		minLevel = other.minLevel;
	}
	return *this;
}


void baseObject::printObjectInfo()
{
	cout << "- Name: " << name << endl;
	cout << "- Description: " << description << endl;
	cout << "- Price: " << price << " gold" << endl;
}

void weapon::printObjectInfo()
{
	baseObject::printObjectInfo();
	cout << "- Damage Modifier: " << damage << endl;
	cout << "- Durability: " << currentDurability << "/" << maxDurability << endl;
	cout << "- Critical Modifier: " << critModifier << endl;
	cout << "- Class Requirement: " << (classRequirement == 1 ? "Warrior" : classRequirement == 2 ? "Rogue" : classRequirement == 3 ? "Mage" : "None") << endl;
	cout << "- Minimum Level: " << minLevel << endl;
}

void armor::printObjectInfo()
{
	baseObject::printObjectInfo();
	cout << "- Resistance: " << resistance << endl;
	cout << "- Durability: " << currentDurability << "/" << maxDurability << endl;
	cout << "- Evasion Modifier: " << evasionModifier << endl;
	cout << "- Class Requirement: " << (classRequirement == 1 ? "Warrior" : classRequirement == 2 ? "Rogue" : classRequirement == 3 ? "Mage" : "None") << endl;
	cout << "- Minimum Level: " << minLevel << endl;
}

void Potion::printObjectInfo()
{
	baseObject::printObjectInfo();
	cout << "- Base Healing: " << baseHealing << endl;
	cout << "- Healing Percent: " << healingPercent * 100 << "%" << endl;
	cout << "- Class Requirement: " << (classRequirement == 1 ? "Warrior" : classRequirement == 2 ? "Rogue" : classRequirement == 3 ? "Mage" : "None") << endl;
}

void Elixir::printObjectInfo()
{
	baseObject::printObjectInfo();
	cout << "- Stat Affected: " << (statAffected == Stamina ? "Stamina" : statAffected == Strength ? "Strength" : statAffected == Agility ? "Agility" : statAffected == Intellect ? "Intellect" : statAffected == Speed ? "Speed" : statAffected == Evasion ? "Evasion" : statAffected == CriticalChance ? "Critical Chance" : statAffected == OrientationSkill ? "Orientation Skill" : "Unknown") << endl;
	cout << "- Amount: " << amount << endl;
	cout << "- Permanent: " << (permanent ? "Yes" : "No") << endl;
}