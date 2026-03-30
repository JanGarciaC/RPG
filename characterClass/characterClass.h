#pragma once
#include "../utilities/utilities.h"
#include "../equipment/equipment.h"
#include <string>
#include <iostream>

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
	// Character stats
    int stamina, strength, agility, intelligence;
    int maxHealth, currentHealth;
    float speed, evasion, criticalChance;
	// Inventory
	int gold;
	weapon equippedWeapon;
	armor equippedArmor;

public:
	baseCharacter() : name(""), characterClass(0), level(1),
        stamina(0), strength(0), agility(0), intelligence(0),
        maxHealth(50), currentHealth(50), speed(0), evasion(0), 
        criticalChance(0), gold(25){}

    void defineName(const std::string& n) { name = n; }
    void setCharacterClass(int c) { characterClass = c; }
    int getCharacterClass() const { return characterClass; }
	std::string getName() const { return name; }

    void addStrength(int x) { strength += x; }
    void addAgility(int x) { agility += x; }
    void addIntelligence(int x) { intelligence += x; }

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
	int getMaxHealth() const { return maxHealth; }
	int getCurrentHealth() const { return currentHealth; }
    int getGold() const { return gold; }
	float getSpeed() const { return speed; }
	float getEvasion() const { return evasion; }
	float getCriticalChance() const { return criticalChance; }
	armor getEquippedArmor() const { return equippedArmor; }
	weapon getEquippedWeapon() const { return equippedWeapon; }

    virtual void calculateDerivedStats()
    {
        maxHealth = 50 + stamina;
        currentHealth = maxHealth;
        evasion = agility * 0.5f;
        criticalChance = agility * 0.65f;
        speed = 20 + agility;
    }

	virtual int baseAttack() { return 0; }
	virtual void startEquipment() {}
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
	classMage(baseCharacter& other) : baseCharacter(other), currentMana(50), maxMana(50) {}

	int getMaxMana() const { return maxMana; }
	int getcurrentMana() const { return currentMana; }

	void calculateDerivedStats() override
	{
		baseCharacter::calculateDerivedStats();
		maxMana = 50 + getIntelligence() * 2;
		currentMana = maxMana;
	}

    int baseAttack() override;
    void startEquipment() override;
};

baseCharacter* characterCreation();
baseCharacter* initializeInventory(baseCharacter* character);