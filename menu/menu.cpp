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
        int choice = navigateMenu(options, "WELCOME", "");

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

    int choice = navigateMenu(options, "CLASS MENU", "");
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
    system("cls");
    const int TOTAL_POINTS = 40;
    int remainingPoints = TOTAL_POINTS;

    vector<string> statNames = { "STAMINA", "STRENGTH", "AGILITY", "INTELLIGENCE" };
    vector<int> values(4, 0);

    while (true)
    {
        vector<string> options;
        for (int i = 0; i < statNames.size(); i++)
        {
            options.push_back(statNames[i] + ": " + to_string(values[i]));
        }

        string msg = "Remaining: " + to_string(remainingPoints) +
            "\n+ / - to modify\nENTER when ready";
        int result = navigateMenuAdvanced(
            [&]()  
            {
                vector<string> options;
                for (int i = 0; i < statNames.size(); i++)
                {
                    options.push_back(statNames[i] + ": " + to_string(values[i]));
                }
                return options;
            },
            "STAT ALLOCATION",
            [&]() 
            {
                return "Remaining points: " + to_string(remainingPoints) + "\n+ / - to modify";
            },
            [&](int selected, MenuAction action)  // onAction
            {
                if (action == ACTION_PLUS)
                {
                    if (remainingPoints > 0 && values[selected] < 20)
                    {
                        values[selected]++;
                        remainingPoints--;
                    }
                }
                else if (action == ACTION_MINUS)
                {
                    if (values[selected] > 0)
                    {
                        values[selected]--;
                        remainingPoints++;
                    }
                }
            }
        );

        if (remainingPoints == 0)
            break;
    }

    character.setStamina(values[0]);
    character.setStrength(values[1]);
    character.setAgility(values[2]);
    character.setIntelligence(values[3]);

    character.calculateDerivedStats();
}

void standardGameMenu(string additionalMessage)
{
    vector<string> options = {
    "Move",
    "Check Character",
	"Check Inventory",
    "Exit"
    };

    while (true)
    {
        int choice = navigateMenu(options, "WORLD MAP", additionalMessage);

        switch (choice)
        {
        case 0:
			// Placeholder for move functionality
        case 1:
			// Placeholder for character check functionality
        case 2:
			// Placeholder for inventory check functionality
        case 3:
            cout << "Exiting game..." << endl;
            Sleep(500);
			exit(0);
        }
    }

}