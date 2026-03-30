#include "menu.h"
#include "../utilities/utilities.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>

using namespace std;

baseCharacter* startMenu()
{
    vector<string> options = {
        "Start New Game",
        "Load Game (Coming Soon)",
        "Exit"
    };

    while (true)
    {
        int choice = navigateMenu(options, "WELCOME");

        switch (choice)
        {
        case 0:
            cout << "Starting new game..." << endl;
            Sleep(500);
            return characterCreation();
        case 1:
            cout << "Load game feature coming soon!" << endl;
            Sleep(1000);
            break;
        case 2:
            cout << "Exiting game..." << endl;
            Sleep(500);
            exit(0);
        }
    }
}

void classMenu(baseCharacter& character)
{
    vector<string> options = {
        "Warrior: Strong fighter in close combat (+1 Strength)",
        "Rogue: Sneaky thief ready to kill (+1 Agility)",
        "Mage: Smart sorcerer capable of casting spells (+1 Intelligence)"
    };

    int choice = navigateMenu(options, "CLASS MENU");
    character.setCharacterClass(choice + 1);

    system("cls");

    switch (character.getCharacterClass())
    {
    case 1: character.addStrength(1); break;
    case 2: character.addAgility(1); break;
    case 3: character.addIntelligence(1); break;
    }
}

void defineStatMenu(baseCharacter& character)
{
    const int TOTAL_POINTS = 40;
    int remainingPoints = TOTAL_POINTS;

    int tempStamina = 0, tempStrength = 0, tempAgility = 0, tempIntelligence = 0;
    vector<string> stats = { "STAMINA", "STRENGTH", "AGILITY", "INTELLIGENCE" };
    int* values[4] = { &tempStamina, &tempStrength, &tempAgility, &tempIntelligence };

    int selected = 0;

    while (true)
    {
        system("cls");

		printHeader("STAT ALLOCATION");

        cout << "Allocate your stat points (Remaining: " << remainingPoints << ")" << endl << endl;
        for (int i = 0; i < 4; i++)
            cout << (i == selected ? "> " : "  ") << stats[i] << ": " << *values[i] << endl;

        cout << endl << "UP/DOWN to select, +/- to adjust, ENTER to confirm when all points assigned." << endl;

        int key = _getch();
        if (key == 224)
        {
            key = _getch();
            if (key == 72) selected = (selected + 3) % 4; // UP
            if (key == 80) selected = (selected + 1) % 4; // DOWN
        }
        else if (key == '+')
        {
            if (remainingPoints > 0 && *values[selected] < 20)
            {
                (*values[selected])++;
                remainingPoints--;
            }
        }
        else if (key == '-')
        {
            if (*values[selected] > 0)
            {
                (*values[selected])--;
                remainingPoints++;
            }
        }
        else if (key == 13 && remainingPoints == 0)
        {
            break; 
        }
    }

    character.setStamina(tempStamina);
    character.setStrength(tempStrength);
    character.setAgility(tempAgility);
    character.setIntelligence(tempIntelligence);

    character.calculateDerivedStats();
}