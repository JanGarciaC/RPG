#pragma once

#include <string>
#include <iostream>

class genericEnemy
{
private:
	std::string name;
	int currentHealth, maxHealth;
	int defense, evasion, speed;
	int intRequirement;
	int expDrop;
	float criticalChance;

public:
	genericEnemy(std::string n, int mh, int def, int ev, int spd, float crit, int ir, int exp) 
		: name(n), maxHealth(mh), currentHealth(mh), defense(def), evasion(ev), 
		speed(spd), criticalChance(crit), intRequirement(ir), expDrop(exp) {}

	void increaseSpeed(int x) { speed += x; }
	void heal(int x) { currentHealth += x; if (currentHealth > maxHealth) currentHealth = maxHealth; }
	void increaseDefense(int x) { defense += x; }
	void increaseEvasion(int x) { evasion += x; }

	int getSpeed() const { return speed; }
	int getCurrentHealth() const { return currentHealth; }
	int getMaxHealth() const { return maxHealth; }
	int getDefense() const { return defense; }
	int getEvasion() const { return evasion; }
	int getExpDrop() const { return expDrop; }
	float getCriticalChance() const { return criticalChance; }
	bool isDefeated() const
	{
		return currentHealth <= 0;
	}

	void takeDamage(int damage);

	void displayInfo(int playerInt);

	virtual int attack();
};

class boar : public genericEnemy
{
public:
	boar() : genericEnemy("Boar", 30, 5, 10, 20, 3, 6, 50) {}
	int attack() override;
};

class rabbit : public genericEnemy
{
public:
	rabbit() : genericEnemy("Rabbit", 10, 0, 20, 30, 0, 2, 25) {}
	int attack() override;
};

class thief : public genericEnemy
{
public: 	
	thief() : genericEnemy("Thief", 25, 3, 15, 25, 10, 8, 80) {}
	int attack() override;
};

class soldier : public genericEnemy
{
public:
	soldier() : genericEnemy("Soldier", 80, 12, 5, 30, 6, 12, 175) {}
	int attack() override;
};

class knight : public genericEnemy
{
public:
	knight() : genericEnemy("Knight", 100, 30, 10, 35, 10, 15, 250) {}
	int attack() override;
};

class angel : public genericEnemy
{
public:
	angel() : genericEnemy("Angel", 250, 10, 20, 40, 15, 20, 600) {}
	int attack() override;
};

class demon : public genericEnemy
{
public:
	demon() : genericEnemy("Demon", 250, 10, 20, 40, 15, 20, 600) {}
	int attack() override;
};