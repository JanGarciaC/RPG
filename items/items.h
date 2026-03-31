#pragma once

#pragma once
#include <string>
#include <iostream>

class baseObject
{
private:
	std::string name, description;
	int price;

public:
	baseObject() : name(""), description(""), price(0) {}
	baseObject(const std::string& n, std::string desc, int p) : name(n), description(desc), price(p) {}

	void setName(const std::string& n) { name = n; }
	void setPrice(int p) { price = p; }
	void setDescription(const std::string& desc) { description = desc; }

	std::string getName() const { return name; }
	std::string getDescription() const { return description; }
	int getPrice() const { return price; }

	virtual void printObjectInfo();

	baseObject& operator=(const baseObject& other);
};

class weapon : public baseObject
{
private:
	float damage;
	int currentDurability, maxDurability;
	float critModifier;
	int minLevel;
	int classRequirement;

public:
	weapon() : baseObject(), damage(0), currentDurability(100), maxDurability(100), critModifier(1), minLevel(0), classRequirement(0) {}
	weapon(const std::string& n, std::string desc, float d, int dur, float cm, int cr, int p, int ml)
		: baseObject(n, desc, p), damage(d), currentDurability(dur), classRequirement(cr), maxDurability(dur), critModifier(cm), minLevel(ml) {}

	void repair() { currentDurability = maxDurability; }

	int getDamage() const { return damage; }
	int getCurrentDurability() const { return currentDurability; }
	int getMaxDurability() const { return maxDurability; }
	float getCritModifier() const { return critModifier; }

	void printObjectInfo() override;

	weapon& operator=(const weapon& other);
};

class armor : public baseObject
{
private:
	int resistance;
	int currentDurability, maxDurability;
	float evasionModifier;
	int minLevel;
	int classRequirement;

public:
	armor() : baseObject(), resistance(0), currentDurability(100), maxDurability(100), evasionModifier(1), minLevel(0), classRequirement(0) {}
	armor(std::string n, std::string desc, int r, int dur, float em, int cr, int p, int ml)
		: baseObject(n, desc, p), resistance(r), currentDurability(dur), maxDurability(dur), classRequirement(cr), evasionModifier(em), minLevel(ml) {}

	void repair() { currentDurability = maxDurability; }
	int getResistance() const { return resistance; }
	int getCurrentDurability() const { return currentDurability; }
	int getMaxDurability() const { return maxDurability; }
	float getEvasionModifier() const { return evasionModifier; }

	void printObjectInfo() override;

	armor& operator=(const armor& other);
};

class Potion : public baseObject
{
private:
	float healingPercent;
	int baseHealing;
	int classRequirement;
public:
	Potion() : baseObject(), classRequirement(0), baseHealing(0), healingPercent(0) {}
	Potion(int cr, int ha, int hp) : baseObject(), classRequirement(0), baseHealing(ha), healingPercent(hp) {}
	Potion(std::string n, std::string desc, int ha, int hp, int cr, int p)
		: baseObject(n, desc, p), baseHealing(ha), classRequirement(cr), healingPercent(hp) {}

	int getBaseHealing() const { return baseHealing; }
	float getHealingPercent() const { return healingPercent; }

	void printObjectInfo() override;

	int drinkPotion(int maxHealth) { return baseHealing + maxHealth * healingPercent; }
};

enum Stats
{
	Stamina,
	Strength,
	Agility,
	Intellect,
	Speed,
	Evasion,
	CriticalChance,
	OrientationSkill
};

class Elixir : public baseObject
{
private:
	Stats statAffected;
	bool permanent;
	int amount;
public:
	Elixir() : baseObject(), statAffected(Stamina), amount(0), permanent(false) {}
	Elixir(Stats sa, int a, bool permanent) : baseObject(), statAffected(sa), amount(a) {}
	Elixir(std::string n, std::string desc, Stats sa, int a, bool perm, int p)
		: baseObject(n, desc, p), statAffected(sa), amount(a), permanent(perm) {}

	void printObjectInfo() override;

	Stats getStatAffected() const { return statAffected; }
	int getAmount() const { return amount; }
};