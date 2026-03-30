#include "characterClass.h"
#include "../menu/menu.h"
#include "../utilities/utilities.h"
#include <iostream>
#include <windows.h>

using namespace std;

baseCharacter* characterCreation()
{
    system("cls");

    printHeader("ENTER NAME");

    string name;
    cout << "Enter your character's name: ";
    getline(cin >> ws, name);

    baseCharacter temp;
    temp.defineName(name);

    classMenu(temp);  
    defineStatMenu(temp);

    if (temp.getCharacterClass() == 1) return new classWarrior(temp);
    if (temp.getCharacterClass() == 2) return new classRogue(temp);
    return new classMage(temp);
}

void classWarrior::startEquipment()
{
	weapon startingSword("Rusty Sword", 1.6, 50, 1.2f, 1, 5, 0);
	armor startingArmor("Rusty Chainmail", 20, 50, 1, 1, 5, 0);

	setEquippedArmor(startingArmor);
	setEquippedWeapon(startingSword);
}

void classRogue::startEquipment()
{
    weapon startingDagger("Rusty Dagger", 1.6, 50, 1.4f, 2, 5, 0);
    armor startingArmor("Old Leather Armor", 10, 50, 1.4f, 2, 5, 0);

    setEquippedArmor(startingArmor);
    setEquippedWeapon(startingDagger);
}

void classMage::startEquipment()
{
    weapon startingStaff("Old Staff", 1.3, 50, 1, 3, 5, 0);
    armor startingRobe("Old Robe", 5, 50, 1.2f, 3, 5, 0);

    setEquippedArmor(startingRobe);
    setEquippedWeapon(startingStaff);
}

int classWarrior::baseAttack()
{
    int damage = rand() % 4*getLevel() + getStrength() * getEquippedWeapon().getDamage();

    if (rand() % 10000 < 100 * (getCriticalChance() * getEquippedWeapon().getCritModifier()))
        damage *= 2;

    return damage;
}

int classRogue::baseAttack()
{
    int damage = rand() % 4*getLevel() + getAgility() * getEquippedWeapon().getDamage();

    if (rand() % 10000 < 100*(getCriticalChance() * getEquippedWeapon().getCritModifier()))
        damage *= 2;

    return damage;
}

int classMage::baseAttack()
{
    int damage = rand() % 2*getLevel() + getIntelligence() * getEquippedWeapon().getDamage();

    if (rand() % 10000 < 100*(getCriticalChance() * getEquippedWeapon().getCritModifier()))
        damage *= 2;

    return damage;
}