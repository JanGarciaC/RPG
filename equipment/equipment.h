#pragma once
#include <string>

class baseObject
{
private:
	std::string name;
	int classRequirement; // 0 for all classes, 1 for warrior, 2 for rogue, 3 for mage
	int price;

public:
	baseObject() : name(""), classRequirement(0), price(0) {}
	baseObject(const std::string& n, int cr, int p) : name(n), classRequirement(cr), price(p) {}

	void setName(const std::string& n) { name = n; }
	void setClassRequirement(int cr) { classRequirement = cr; }
	void setPrice(int p) { price = p; }
	
	std::string getName() const { return name; }
	int getPrice() const { return price; }
	int getClassRequirement() const { return classRequirement; }
};

class weapon : public baseObject
{
private:
	float damage;
	int currentDurability, maxDurability;
	float critModifier;
	int minLevel;

public: 
	weapon() : baseObject(), damage(0),  currentDurability(100), maxDurability(100), critModifier(1), minLevel(0) {}
	weapon(const std::string& n, float d, int dur, float cm, int cr, int p, int ml) 
		: baseObject(n, cr ,p), damage(d), currentDurability(dur), maxDurability(dur), critModifier(cm), minLevel(ml) {}

	void repair() { currentDurability = maxDurability; }

	int getDamage() const { return damage; }
	int getCurrentDurability() const { return currentDurability; }
	int getMaxDurability() const { return maxDurability; }
	float getCritModifier() const { return critModifier; }

	weapon& operator=(const weapon& other);
};

class armor : public baseObject
{
private:
	int resistance;
	int currentDurability, maxDurability;
	float evasionModifier;
	int minLevel;

public:
	armor() : baseObject(), resistance(0), currentDurability(100), maxDurability(100), evasionModifier(1), minLevel(0) {}
	armor(std::string n, int r, int dur, float em, int cr, int p, int ml) 
		: baseObject(n, cr, p), resistance(r), currentDurability(dur), maxDurability(dur), evasionModifier(em), minLevel(ml) {}

	void repair() { currentDurability = maxDurability; }
	int getResistance() const { return resistance; }
	int getCurrentDurability() const { return currentDurability; }
	int getMaxDurability() const { return maxDurability; }
	float getEvasionModifier() const { return evasionModifier; }
	
	armor& operator=(const armor& other);
};