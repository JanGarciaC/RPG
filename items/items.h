#pragma once

#include <string>
#include <iostream>
#include <vector>

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

struct baseObjectTemplate
{
	std::string name;
	std::string description;
	int price;
};

struct weaponTemplate
{
	std::string name;
	std::string description;
	int price;
	float damageModifier;
	int durability;
	float critModifier;
	int classRequirement;
	int minLevel;
};

struct armorTemplate
{
	std::string name;
	std::string description;
	int price;
	int resistance;
	int durability;
	float evasionModifier;
	int classRequirement;
	int minLevel;
};

struct potionTemplate
{
	std::string name;
	std::string description;
	int price;
	int baseHealing;
	float healingPercent;
	int classRequirement;
};

struct elixirTemplate
{
	std::string name;
	std::string description;
	int price;
	Stats statAffected;
	int amount;
	int duration;
	bool permanent;
};

extern std::vector<baseObjectTemplate> baseObjectTemplates;
extern std::vector<weaponTemplate> weaponTemplates;
extern std::vector<armorTemplate> armorTemplates;
extern std::vector<potionTemplate> potionTemplates;
extern std::vector<elixirTemplate> elixirTemplates;

baseObjectTemplate getRandomBaseObjectTemplate();
weaponTemplate getRandomWeaponTemplate();
armorTemplate getRandomArmorTemplate();
potionTemplate getRandomPotionTemplate();
elixirTemplate getRandomElixirTemplate();

class baseObject
{
private:
	std::string name, description;
	int price;

public:
	baseObject() : name(""), description(""), price(0) {}
	baseObject(const std::string& n, std::string desc, int p) : name(n), description(desc), price(p) {}
	baseObject(baseObjectTemplate obj) : name(obj.name), description(obj.description), price(obj.price) {}

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
	weapon(weaponTemplate obj) 
		: baseObject(obj.name, obj.description, obj.price), damage(obj.damageModifier), currentDurability(obj.durability), 
		maxDurability(obj.durability), critModifier(obj.critModifier), classRequirement(obj.classRequirement), minLevel(obj.minLevel) {}

	void repair() { currentDurability = maxDurability; }

	float getDamage() const { return damage; }
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
	armor(armorTemplate obj)
		: baseObject(obj.name, obj.description, obj.price), resistance(obj.resistance), currentDurability(obj.durability),
		maxDurability(obj.durability), evasionModifier(obj.evasionModifier), classRequirement(obj.classRequirement), minLevel(obj.minLevel) {}

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
	Potion(std::string n, std::string desc, int ha, int hp, int cr, int p)
		: baseObject(n, desc, p), baseHealing(ha), classRequirement(cr), healingPercent(hp) {}
	Potion(potionTemplate obj)
		: baseObject(obj.name, obj.description, obj.price), baseHealing(obj.baseHealing), classRequirement(obj.classRequirement), 
		healingPercent(obj.healingPercent) {}

	int getBaseHealing() const { return baseHealing; }
	float getHealingPercent() const { return healingPercent; }

	void printObjectInfo() override;

	int drinkPotion(int maxHealth) { return baseHealing + maxHealth * healingPercent; }
};

class Elixir : public baseObject
{
private:
	Stats statAffected;
	bool permanent;
	int duration;
	int amount;
public:
	Elixir() : baseObject(), statAffected(Stamina), amount(0), duration(0), permanent(false) {}
	Elixir(std::string n, std::string desc, Stats sa, int a, int dur, bool perm, int p)
		: baseObject(n, desc, p), statAffected(sa), amount(a), duration(dur), permanent(perm) {}
	Elixir(elixirTemplate obj)
		: baseObject(obj.name, obj.description, obj.price), statAffected(obj.statAffected), amount(obj.amount), 
		duration(obj.duration), permanent(obj.permanent) {}

	void printObjectInfo() override;

	Stats getStatAffected() const { return statAffected; }
	int getAmount() const { return amount; }
};