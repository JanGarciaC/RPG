#include "characterClass.h"
#include "../menu/menu.h"
#include "../utilities/utilities.h"
#include <iostream>
#include <windows.h>

using namespace std;

baseCharacter* initialize(baseCharacter* character)
{
    character->startEquipment();
	character->calculateDerivedStats();
    return character;
}

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

    if (temp.getCharacterClass() == 1) return initialize(new classWarrior(temp));
    if (temp.getCharacterClass() == 2) return initialize(new classRogue(temp));
    return initialize(new classMage(temp));
}

void classWarrior::startEquipment()
{
	weapon startingSword(weaponTemplates[0]);
	armor startingArmor(armorTemplates[0]);

	setEquippedArmor(startingArmor);
	setEquippedWeapon(startingSword);
}

void classRogue::startEquipment()
{
    weapon startingDagger(weaponTemplates[1]);
    armor startingArmor(armorTemplates[1]);

    setEquippedArmor(startingArmor);
    setEquippedWeapon(startingDagger);
}

void classMage::startEquipment()
{
    weapon startingStaff(weaponTemplates[2]);
    armor startingRobe(armorTemplates[2]);

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
    int damage = rand() % 4*getLevel() + getStrength() * getEquippedWeapon().getDamage();

    if (rand() % 10000 < 100*(getCriticalChance() * getEquippedWeapon().getCritModifier()))
        damage *= 2;

    return damage;
}

int classMage::baseAttack()
{
    int damage = rand() % 2*getLevel() + getStrength() * getEquippedWeapon().getDamage();

    if (rand() % 10000 < 100*(getCriticalChance() * getEquippedWeapon().getCritModifier()))
        damage *= 2;

    return damage;
}



void baseCharacter::displayCharacterInfo()
{
    cout << "Name: " << name << endl;
    cout << "Class: " << (characterClass == 1 ? "Warrior" : characterClass == 2 ? "Rogue" : characterClass == 3 ? "Mage" : "None") << endl;
    cout << "Level: " << level << endl;
	cout << "Experience: " << experience << "/" << 100 * pow(1.4, level - 1) << endl;
    cout << "Health: " << currentHealth << "/" << maxHealth << endl << endl;

    cout << "BASIC STATS:" << endl;
    if (tempStamina == 0)
    {
        cout << "Stamina: " << stamina << endl;
    }
    else
        cout << "Stamina: " << stamina << " + " << tempStamina << endl;
    if (tempStrength == 0)
    {
        cout << "Strength: " << strength << endl;
    }
    else
        cout << "Strength: " << strength << " + " << tempStrength << endl;

    if (tempAgility == 0)
    {
        cout << "Agility: " << agility << endl;
    }
    else
        cout << "Agility: " << agility << " + " << tempAgility << endl;

    if (tempIntelligence == 0)
    {
        cout << "Intelligence: " << intelligence << endl << endl;
    }
    else
        cout << "Intelligence: " << intelligence << " + " << tempIntelligence << endl;
	cout << "Stat Buff Duration: " << buffDuration << " turns" << endl << endl;

	cout << "DERIVED STATS:" << endl;
	cout << "Speed: " << speed << endl;
	cout << "Evasion: " << evasion << endl;
	cout << "Critical Chance: " << criticalChance << "%" << endl;
	cout << "Orientation Skill: " << orientationSkill << "%" << endl;
}

void classMage::displayCharacterInfo()
{
    cout << "Name: " << getName() << endl;
    cout << "Class: " << (getCharacterClass() == 1 ? "Warrior" : getCharacterClass() == 2 ? "Rogue" : getCharacterClass() == 3 ? "Mage" : "None") << endl;
    cout << "Level: " << getLevel() << endl;
    cout << "Experience" << getExperience() << "/" << 100 * pow(1.4, getLevel() - 1) << endl;
    cout << "Health: " << getCurrentHealth() << "/" << getMaxHealth() << endl;
	cout << "Mana: " << getCurrentMana() << "/" << getMaxMana() << endl << endl;

    cout << "BASIC STATS:" << endl;
    if (getTempStamina() == 0)
    {
        cout << "Stamina: " << getStamina() << endl;
    }
    else
        cout << "Stamina: " << getStamina() << " + " << getTempStamina() << endl;
    if (getTempStrength() == 0)
    {
        cout << "Strength: " << getStrength() << endl;
    }
    else
        cout << "Strength: " << getStrength() << " + " << getTempStrength() << endl;

    if (getTempAgility() == 0)
    {
        cout << "Agility: " << getAgility() << endl;
    }
    else
        cout << "Agility: " << getAgility() << " + " << getTempAgility() << endl;

    if (getTempIntelligence() == 0)
    {
        cout << "Intelligence: " << getIntelligence() << endl << endl;
    }
    else
        cout << "Intelligence: " << getIntelligence() << " + " << getTempIntelligence() << endl;
	cout << "Stat Buff Duration: " << getBuffDuration() << " turns" << endl << endl;

    cout << "DERIVED STATS:" << endl;
    cout << "Speed: " << getSpeed() << endl;
    cout << "Evasion: " << getEvasion() << endl;
    cout << "Critical Chance: " << getCriticalChance() << "%" << endl;
    cout << "Orientation Skill: " << getOrientationSkill() << "%" << endl;
}

void baseCharacter::printInventory()
{
	cout << "Gold: " << gold << endl << endl;

	cout << "////////// EQUIPPED WEAPON //////////" << endl;
	equippedWeapon.printObjectInfo();

	cout << "////////// EQUIPPED ARMOR //////////" << endl;
	equippedArmor.printObjectInfo();

	cout << "////////// INVENTORY ITEMS //////////" << endl;
    if (inventory.empty())
    {
        cout << "Your inventory is empty." << endl;
        return;
	}
    for (size_t i = 0; i < inventory.size(); i++)
    {
		inventory[i]->printObjectInfo();
        cout << endl;
    }
}