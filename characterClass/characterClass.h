#pragma once
#include "../utilities/utilities.h"
#include <string>
#include <iostream>

class baseCharacter
{
private:
    std::string name;
    int characterClass;
    int stamina, strength, agility, intelligence;
    int maxHealth, currentHealth;
    float speed, evasion, criticalChance;

public:
    baseCharacter() : name(""), characterClass(0),
        stamina(0), strength(0), agility(0), intelligence(0),
        maxHealth(50), currentHealth(50), speed(0), evasion(0), 
        criticalChance(0) {}

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

	int getStamina() const { return stamina; }
	int getStrength() const { return strength; }
	int getAgility() const { return agility; }
	int getIntelligence() const { return intelligence; }
	int getMaxHealth() const { return maxHealth; }
	int getCurrentHealth() const { return currentHealth; }

    virtual void calculateDerivedStats()
    {
        maxHealth = 50 + stamina;
        currentHealth = maxHealth;
        evasion = agility * 0.5f;
        criticalChance = agility * 0.65f;
        speed = 20 + agility;
    }

    virtual void baseattack() {};
};

struct weapon
{
	std::string name;
	int damage;
	int durability;
	float criticalMultiplier;
};

class classWarrior : public baseCharacter
{
private:
	weapon startingWeapon = { "Sword", 10, 100, 1.3 };

public:
	classWarrior(baseCharacter& other) : baseCharacter(other) {}

	void baseattack() override 
	{
		std::cout << getName() << " swings a sword! Damage: " << getStrength() + startingWeapon.damage << std::endl;
	}
};

class classRogue : public baseCharacter
{
private:
	weapon startingWeapon = { "Dagger", 8, 100, 1.8 };

public:
	classRogue(baseCharacter& other) : baseCharacter(other) {}

	void baseattack() override 
	{
		std::cout << getName() << " strikes from the shadows! Damage: " << getAgility() + startingWeapon.damage << std::endl;
	}
};

class classMage : public baseCharacter
{
private:
	int currentMana, maxMana;
	weapon startingWeapon = { "Staff", 10, 100, 1 };

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

	void baseattack() override 
	{
		std::cout << getName() << " casts a spell! Damage: " << getIntelligence() + startingWeapon.damage << std::endl;
	}
};

baseCharacter* characterCreation();