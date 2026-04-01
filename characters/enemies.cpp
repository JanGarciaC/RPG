#include "enemies.h"

using namespace std;

void genericEnemy::displayInfo(int playerInt)
{
	if (playerInt < intRequirement)
		cout << "Your inteligence is to low to analize this opponent." << endl;
	else
	{
		cout << "Name: " << name << endl;
		cout << "Health: " << currentHealth << "/" << maxHealth << endl;
		cout << "Defense: " << defense << endl;
		cout << "Evasion: " << evasion << endl;
		cout << "Speed: " << speed << endl;
		cout << "Critical Chance: " << criticalChance << endl;
	}
}

int boar::attack()
{
	int r = rand() % 100;
	if (r < 75)
	{
		cout << "The boar charges at you with its tusks!" << endl;
		int damage = 25 + rand() % 11;
		r = rand() % 100;
		if (r < getCriticalChance())
		{
			cout << "It's a critical hit!!" << endl;
			damage *= 2;
		}
		return damage;
	}
	cout << "The boar gets angry. It's speed increases!" << endl;
	increaseSpeed(rand() % 3 + 1);
	return 0;
}

int rabbit::attack()
{
	int r = rand() % 100;
	if (r < 75)
	{
		cout << "The rabbit bites you!" << endl;
		int damage = 16 + rand() % 11;
		r = rand() % 100;
		if (r < getCriticalChance())
		{
			cout << "It's a critical hit!!" << endl;
			damage *= 2;
		}
		return damage;
	}
	cout << "The rabbit is scared. It's speed and evasion increases!" << endl;
	increaseSpeed(rand() % 3);
	increaseEvasion(rand() % 3);
	return 0;
}

int thief::attack()
{
	int r = rand() % 100;
	if (r < 75)
	{
		cout << "The thief stabs you!" << endl;
		int damage = 30 + rand() % 26;
		r = rand() % 100;
		if (r < getCriticalChance())
		{
			cout << "It's a critical hit!!" << endl;
			damage *= 2;
		}
		return damage;
	}
	cout << "The thief throws a knife at your head!" << endl;
	int damage = 40 + rand() % 11;
	r = rand() % 100;
	if (r < getCriticalChance())
	{
		cout << "It's a critical hit!!" << endl;
		damage *= 2;
	}
	return damage;
}

int soldier::attack()
{
	int r = rand() % 100;
	if (r < 75)
	{
		cout << "The soldier strikes with his lance!" << endl;
		int damage = 45 + rand() % 26;
		r = rand() % 100;
		if (r < getCriticalChance())
		{
			cout << "It's a critical hit!!" << endl;
			damage *= 2;
		}
		return damage;
	}
	cout << "The soldier charges at you! It's speed increases!" << endl;
	int damage = 50 + rand() % 11;
	r = rand() % 100;
	if (r < getCriticalChance())
	{
		cout << "It's a critical hit!!" << endl;
		damage *= 2;
	}
	increaseSpeed(3 + rand() % 5);
	return damage;
}

int knight::attack()
{
	int r = rand() % 100;
	if (r < 75)
	{
		cout << "The knigth swings it's sword!" << endl;
		int damage = 55 + rand() % 21;
		r = rand() % 100;
		if (r < getCriticalChance())
		{
			cout << "It's a critical hit!!" << endl;
			damage *= 2;
		}
		return damage;
	}
	cout << "The knigth rises it's shield. It gets a protection increase!" << endl;
	increaseDefense(3 + rand() % 4);
	return 0;
}

int angel::attack()
{
	int r = rand() % 100;
	if (r < 75)
	{
		cout << "The angel calls god's power to strike you!" << endl;
		int damage = 60 + rand() % 51;
		r = rand() % 100;
		if (r < getCriticalChance())
		{
			cout << "It's a critical hit!!" << endl;
			damage *= 2;
		}
		return damage;
	}
	cout << "The angel casts a divine ligth on itself. It's healing itself!" << endl;
	heal(25 + rand() % 26);
	return 0;
}

int demon::attack()
{
	int r = rand() % 100;
	if (r < 75)
	{
		cout << "The demon calls the devil's power to strike you!" << endl;
		int damage = 60 + rand() % 51;
		r = rand() % 100;
		if (r < getCriticalChance())
		{
			cout << "It's a critical hit!!" << endl;
			damage *= 2;
		}
		return damage;
	}
	cout << "The demon steals your vital energy!" << endl;
	int damage = 15 + rand() % 11;
	r = rand() % 100;
	if (r < getCriticalChance())
	{
		cout << "It's a critical hit!!" << endl;
		damage *= 2;
	}
	heal(damage);
	return damage;
}