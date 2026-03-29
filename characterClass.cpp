#include "characterClass.h"

baseCharacter* characterCreation()
{
	std::string name;
	system("cls");
	cout << "===================================" << endl;
	cout << "======= Character Creation ========" << endl;
	cout << "===================================" << endl << endl;
	cout << "Enter your character's name: ";
	cin >> name;
	cout << endl;

	baseCharacter temp;

	temp.defineName(name);
	temp.selectClass();
	temp.allocateStats();

	if (temp.getCharacterClass() == 1)
		return new classWarrior(temp);
	else if (temp.getCharacterClass() == 2)
		return new classRogue(temp);
	else
		return new classMage(temp);
}


void baseCharacter::allocateStats()
{
	system("cls");	
	cout << "===================================" << endl;
	cout << "========= Character Stats =========" << endl;
	cout << "===================================" << endl << endl;

	int statPoints = 40;
	int tstamina, tstrength, tagility, tintelligence;

	cout << "STAMINA: Determines your characters health and resistance" << endl;
	cout << "STRENGTH: Determines your characters physical strength" << endl;
	cout << "AGILITY: Determines your characters speed, evasion and critical change" << endl;
	cout << "INTELLIGENCE: Determines your characters magical power and mana pool" << endl << endl;

	cout << "Allocate your stat points (Total: 40)" << endl;

	do {
		cout << "STAMINA: ";
		cin >> tstamina;

		if (tstamina < 0 || tstamina > 20)
			cout << "Invalid input. Please enter a value between 0 and 20." << endl;
		else
			statPoints -= tstamina;

		if (statPoints < 0) {
			cout << "You dont have enough points. Please try again" << endl;
			statPoints += tstamina;
		}

	} while (tstamina < 0 || tstamina > 20 || statPoints < 0);

	do {
		cout << "STRENGTH: ";
		cin >> tstrength;

		if (tstrength < 0 || tstrength > 20)
			cout << "Invalid input. Please enter a value between 0 and 20." << endl;
		else
			statPoints -= tstrength;

		if (statPoints < 0) {
			cout << "You dont have enough points. Please try again" << endl;
			statPoints += tstrength;
		}

	} while (tstrength < 0 || tstrength > 20 || statPoints < 0);

	do {
		cout << "AGILITY: ";
		cin >> tagility;

		if (tagility < 0 || tagility > 20)
			cout << "Invalid input. Please enter a value between 0 and 20." << endl;
		else
			statPoints -= tagility;

		if (statPoints < 0) {
			cout << "You dont have enough points. Please try again" << endl;
			statPoints += tagility;
		}

	} while (tagility < 0 || tagility > 20 || statPoints < 0);

	do {
		cout << "INTELLIGENCE: ";
		cin >> tintelligence;

		if (tintelligence < 0 || tintelligence > 20)
			cout << "Invalid input. Please enter a value between 0 and 20." << endl;
		else
			statPoints -= tintelligence;

		if (statPoints < 0) {
			cout << "You dont have enough points. Please try again" << endl;
			statPoints += tintelligence;
		}

	} while (tintelligence < 0 || tintelligence > 20 || statPoints < 0);

	cout << "You have allocated your stat points as follows: " << endl;
	cout << "STAMINA: " << tstamina << endl;
	cout << "STRENGTH: " << tstrength << endl;
	cout << "AGILITY: " << tagility << endl;
	cout << "INTELLIGENCE: " << tintelligence << endl;
	cout << "Remaining stat points: " << statPoints << endl;

	cout << "This stats cannot be modified in the future, do you want to continue? [Y/N]:  ";

	char choice;

	do {
		cin >> choice;

		if (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
			cout << "Invalid input. Try again: ";
		else if (choice == 'N' || choice == 'n')
			allocateStats();
		else if (choice == 'Y' || choice == 'y')
			cout << "Creating character...." << endl;

	} while (choice != 'Y' && choice != 'y');

	stamina += tstamina;
	strength += tstrength;
	agility += tagility;
	intelligence += tintelligence;

	maxHealth = 50 + stamina;
	currentHealth = maxHealth;

	maxMana = 50 + intelligence;
	currentMana = maxMana;

	evasion = agility * 0.5f;
	criticalChance = agility * 0.65f;
	speed = 20 + agility;
}

void baseCharacter::selectClass()
{
	cout << "===================================" << endl;
	cout << "========== Select Class ===========" << endl;
	cout << "===================================" << endl << endl;

	cout << "1. WARRIOR: Strong fighter expert in close combat" << endl;
	cout << "2. ROGUE: Sneaky and deadly thief ready to kill" << endl;
	cout << "3. MAGE: Smart sorcerer capable of casting spells" << endl;

	cout << "Select your class: ";

	do
	{
		cin >> characterClass;
		if (characterClass < 1 || characterClass > 3)
			cout << "Invalid input. Please enter a valid class: ";
	} while (characterClass < 1 || characterClass > 3);
	
	switch (characterClass) {
		case 1:
			cout << "You have selected WARRIOR class --> +1 STRENGTH" << endl;
			break;
		case 2:
			cout << "You have selected ROGUE class --> +1 AGILITY" << endl;
			break;
		case 3:
			cout << "You have selected MAGE class --> 1+ INTELLIGENCE" << endl;
			break;
	}
	Sleep(2000);
}