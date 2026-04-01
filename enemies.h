#pragma once

#include <string>

class genericEnemy
{
private:
	std::string name;
	int currentHealth, maxHealth;
	int defense, evasion, speed;
	float criticalChance;

public:
	genericEnemy(std::string n, int mh, int def, int ev, int spd, float crit) 
		: name(n), maxHealth(mh), currentHealth(mh), defense(def), evasion(ev), speed(spd), criticalChance(crit) {}

	int getSpeed() const { return speed; }
	int getCurrentHealth() const { return currentHealth; }
	int getMaxHealth() const { return maxHealth; }
	int getDefense() const { return defense; }
	int getEvasion() const { return evasion; }
	float getCriticalChance() const { return criticalChance; }
	void takeDamage(int damage)
	{
		currentHealth -= damage;
		if (currentHealth < 0)
			currentHealth = 0;
	}
	bool isDefeated() const
	{
		return currentHealth <= 0;
	}
};

class boar : public genericEnemy
{
public:
	boar() : genericEnemy("Boar", 30, 5, 10, 20, 3) {}
};

class rabbit : public genericEnemy
{
public:
	rabbit() : genericEnemy("Rabbit", 10, 0, 20, 30, 0) {}
};

class thief : public genericEnemy
{
public: 	
	thief() : genericEnemy("Thief", 25, 3, 15, 25, 10) {}
};

class soldier : public genericEnemy
{
public:
	soldier() : genericEnemy("Soldier", 80, 12, 5, 30, 6) {}
};

class knight : public genericEnemy
{
public:
	knight() : genericEnemy("Knight", 100, 30, 10, 35, 10) {}
};

class angel : public genericEnemy
{
public:
	angel() : genericEnemy("Angel", 250, 10, 20, 40, 15) {}
};

class demon : public genericEnemy
{
public:
	demon() : genericEnemy("Angel", 250, 10, 20, 40, 15) {}
};