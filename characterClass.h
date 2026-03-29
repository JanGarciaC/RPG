#pragma once
#include "utilities.h"

class baseCharacter 
{
	protected:
		std::string name;
		int characterClass;
		// stats
		int maxHealth, currentHealth, maxMana, currentMana;
		int stamina, strength, agility, intelligence;
		float speed, evasion, criticalChance;

	public:
		baseCharacter() : name(""), characterClass(0), maxHealth(50), currentHealth(50), maxMana(50), currentMana(50), stamina(0), 
			strength(0), agility(0), intelligence(0), speed(0), evasion(0), criticalChance(0) {}

		baseCharacter(baseCharacter& other) : name(other.name), characterClass(other.characterClass), maxHealth(other.maxHealth), currentHealth(other.currentHealth),
			maxMana(other.maxMana), currentMana(other.currentMana), stamina(other.stamina), strength(other.strength), agility(other.agility),
			intelligence(other.intelligence), speed(other.speed), evasion(other.evasion), criticalChance(other.criticalChance) {}

		void defineName(string characterName) {name = characterName;}
		void allocateStats();
		void selectClass();

		int getCharacterClass() { return characterClass; }

		virtual void attack() {cout << "Base attack (should not happen)" << endl;}		
		virtual ~baseCharacter() {}
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

	void attack() override {
		cout << name << " swings a sword! Damage: "
			<< strength + startingWeapon.damage << endl;
	}
};

class classRogue : public baseCharacter
{
private:
	weapon startingWeapon = { "Dagger", 8, 100, 1.8 };

public:
	classRogue(baseCharacter& other) : baseCharacter(other) {}

	void attack() override {
		cout << name << " strikes from shadows! Damage: "
			<< agility + startingWeapon.damage << endl;
	}
};

class classMage : public baseCharacter
{
private:
	weapon startingWeapon = { "Staff", 10, 100, 1 };

public:
	classMage(baseCharacter& other) : baseCharacter(other) {}

	void attack() override {
		cout << name << " casts a spell! Damage: "
			<< intelligence + startingWeapon.damage << endl;
	}
};

baseCharacter* characterCreation();