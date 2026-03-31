#pragma once
#include "../utilities/utilities.h"
#include "../items/items.h"
#include <string>
#include <iostream>
#include <cmath>

/////////////////////////////////
// Base class Definition
/////////////////////////////////
class baseCharacter
{
private:
	// Basic character info
    std::string name;
    int characterClass;
	int level;	
	int experience;
	// Character stats
    int stamina, strength, agility, intelligence;
    int maxHealth, currentHealth;
    float speed, evasion, criticalChance, orientationSkill;
	// Temporary stats
	int tempStamina, tempStrength, tempAgility, tempIntelligence;
	int buffDuration;
	// Inventory
	int gold;
	weapon equippedWeapon;
	armor equippedArmor;
	std::vector<baseObject> inventory;

public:
	baseCharacter() : name(""), characterClass(0), level(1),
        stamina(0), strength(0), agility(0), intelligence(0),
        maxHealth(50), currentHealth(50), speed(0), evasion(0), 
        criticalChance(0), gold(25), experience(0), orientationSkill(0),
		tempStamina(0), tempStrength(0), tempAgility(0), tempIntelligence(0), buffDuration(0) {}

    void defineName(const std::string& n) { name = n; }
    void setCharacterClass(int c) { characterClass = c; }
    int getCharacterClass() const { return characterClass; }
	std::string getName() const { return name; }

	void addStamina(int x) { stamina += x; }
    void addStrength(int x) { strength += x; }
    void addAgility(int x) { agility += x; }
    void addIntelligence(int x) { intelligence += x; }
	void addExperience(int x) { experience += x; if (experience >= 100 * pow(1.4, level - 1)) { do { experience -= 100 * pow(1.4, level - 1); levelUp(); } while (experience >= 100 * pow(1.4, level - 1)); } }
	void addItemToInventory(const baseObject& item) { inventory.push_back(item); }
	void removeItemFromInventory(int index) { if (index >= 0 && index < inventory.size()) inventory.erase(inventory.begin() + index); }

	void setOrientationSkill(float x) { orientationSkill = x; }
    void setStamina(int x) { stamina = x; }
    void setStrength(int x) { strength = x; }
    void setAgility(int x) { agility = x; }
    void setIntelligence(int x) { intelligence = x; }
    void modifyHealth(int x) { currentHealth += x; if (currentHealth > maxHealth) currentHealth = maxHealth; if (currentHealth < 0) currentHealth = 0; }
	void setEquippedWeapon(const weapon& w) { equippedWeapon = w; }
	void setEquippedArmor(const armor& a) { equippedArmor = a; }
	void addGold(int x) { gold += x; }

	int getLevel() const { return level; }
	int getStamina() const { return stamina; }
	int getStrength() const { return strength; }
	int getAgility() const { return agility; }
	int getIntelligence() const { return intelligence; }
	int getTempStamina() const { return tempStamina; }
	int getTempStrength() const { return tempStrength; }
	int getTempAgility() const { return tempAgility; }
	int getTempIntelligence() const { return tempIntelligence; }
	int getBuffDuration() const { return buffDuration; }
	int getMaxHealth() const { return maxHealth; }
	int getCurrentHealth() const { return currentHealth; }
    int getGold() const { return gold; }
	int getExperience() const { return experience; }
	float getOrientationSkill() const { return orientationSkill; }
	float getSpeed() const { return speed; }
	float getEvasion() const { return evasion; }
	float getCriticalChance() const { return criticalChance; }
	armor getEquippedArmor() const { return equippedArmor; }
	weapon getEquippedWeapon() const { return equippedWeapon; }
	baseObject getInventoryItem(int index) const { if (index >= 0 && index < inventory.size()) return inventory[index]; return baseObject(); }

	void printInventory();

    virtual void calculateDerivedStats()
    {
        maxHealth = 50 + stamina;
        currentHealth = maxHealth;
        evasion = agility * 0.5f;
        criticalChance = agility * 0.65f;
        speed = 20 + agility;
		orientationSkill = 25 + intelligence * 2.5f;
    }

	virtual int baseAttack() { return 0; }
	virtual void startEquipment() {}
	virtual void displayCharacterInfo();
	virtual void levelUp() {}
	virtual ~baseCharacter() {}
};

/////////////////////////////////
// classWarrior Definition
/////////////////////////////////
class classWarrior : public baseCharacter
{
private:

public:
	classWarrior(baseCharacter& other) : baseCharacter(other) {}

    int baseAttack() override;
	void startEquipment() override;
};

/////////////////////////////////
// classRogue Definition
/////////////////////////////////
class classRogue : public baseCharacter
{
private:

public:
	classRogue(baseCharacter& other) : baseCharacter(other) {}

    int baseAttack() override;
    void startEquipment() override;
};

/////////////////////////////////
// classMage Definition
/////////////////////////////////
class classMage : public baseCharacter
{
private:
	int currentMana, maxMana;

public:
	classMage(baseCharacter& other) : baseCharacter(other), currentMana(100), maxMana(100) {}

	int getMaxMana() const { return maxMana; }
	int getCurrentMana() const { return currentMana; }

	void calculateDerivedStats() override
	{
		baseCharacter::calculateDerivedStats();
		maxMana = 100 + getIntelligence() * 2;
		currentMana = maxMana;
	}

    int baseAttack() override;
    void startEquipment() override;
	void displayCharacterInfo() override;
};

baseCharacter* characterCreation();
baseCharacter* initialize(baseCharacter* character);