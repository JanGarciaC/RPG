#pragma once
#include <string>

class weapon 
{
private:
	std::string name;
	int damage;
	int currentDurability, maxDurability;
	float critModifier;
	int classRequirement; // 0 for all classes, 1 for warrior, 2 for rogue, 3 for mage
	int price;

public: 
	weapon() : name(""), damage(0),  currentDurability(100), maxDurability(100), critModifier(1), classRequirement(0), price(0) {}
	weapon(const std::string& n, int d, int dur, float cm, int cr, int p)
		: name(n), damage(d), currentDurability(dur), maxDurability(dur), critModifier(cm), classRequirement(cr), price(p) {}

	void repair() { currentDurability = maxDurability; }

	int getDamage() const { return damage; }
	int getCurrentDurability() const { return currentDurability; }
	int getMaxDurability() const { return maxDurability; }
	float getCritModifier() const { return critModifier; }
	int getPrice() const { return price; }
	bool checkClassRequirement(int characterClass) const { return classRequirement == 0 || classRequirement == characterClass;}

	weapon& operator=(const weapon& other);
};

class armor
{
private:
	std::string name;
	int resistance;
	int currentDurability, maxDurability;
	float evasionModifier;
	int classRequirement; // 0 for all classes, 1 for warrior, 2 for rogue, 3 for mage
	int price;

public:
	armor() : name(""), resistance(0), currentDurability(100), maxDurability(100), evasionModifier(1), classRequirement(0), price(0) {}
	armor(std::string n, int r, int dur, float em, int cr, int p)
		: name(n), resistance(r), currentDurability(dur), maxDurability(dur), evasionModifier(em), classRequirement(cr), price(p) {}

	void repair() { currentDurability = maxDurability; }
	int getResistance() const { return resistance; }
	int getCurrentDurability() const { return currentDurability; }
	int getMaxDurability() const { return maxDurability; }
	float getEvasionModifier() const { return evasionModifier; }
	int getPrice() const { return price; }
	bool checkClassRequirement(int characterClass) const { return classRequirement == 0 || classRequirement == characterClass; }

	armor& operator=(const armor& other);
};