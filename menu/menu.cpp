#include "menu.h"
#include "../utilities/utilities.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>

using namespace std;

#include <iostream>
#include <vector>
#include <string>

void printSimbols(int mode) {
     vector<string> cross = {
"                                                                                ",
"                                                                                ",
"                                                                                ",
"                                                                                ",
"                                                                                ",
"                                                                                ",
"                                                                                ",
"                                                                                ",
"                                @@@@@@@@@@@@@@@@                                ",
"                                @@@@@@@@@@@@@@@@                                ",
"                                @@@@@@@@@@@@@@@@                                ",
"                                @@@@@@@@@@@@@@@@                                ",
"                                @@@@@@@@@@@@@@@@                                ",
"                                @@@@@@@@@@@@@@@@                                ",
"                                @@@@@@@@@@@@@@@@                                ",
"                                @@@@@@@@@@@@@@@@                                ",
"                @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                ",
"                @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                ",
"                @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                ",
"                @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                ",
"                @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                ",
"                @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                ",
"                @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                ",
"                @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                ",
"                                @@@@@@@@@@@@@@@@                                ",
"                                @@@@@@@@@@@@@@@@                                ",
"                                @@@@@@@@@@@@@@@@                                ",
"                                @@@@@@@@@@@@@@@@                                ",
"                                @@@@@@@@@@@@@@@@                                ",
"                                @@@@@@@@@@@@@@@@                                ",
"                                @@@@@@@@@@@@@@@@                                ",
"                                @@@@@@@@@@@@@@@@                                ",
"                                @@@@@@@@@@@@@@@@                                ",
"                                @@@@@@@@@@@@@@@@                                ",
"                                @@@@@@@@@@@@@@@@                                ",
"                                @@@@@@@@@@@@@@@@                                ",
"                                @@@@@@@@@@@@@@@@                                ",
"                                @@@@@@@@@@@@@@@@                                ",
"                                @@@@@@@@@@@@@@@@                                ",
"                                @@@@@@@@@@@@@@@@                                ",
"                                                                                ",
"                                                                                ",
"                                                                                ",
"                                                                                ",
"                                                                                ",
"                                                                                ",
"                                                                                ",
"                                                                                "
    };

    vector<string> pentagram = {
"                                                                                ",
"                                                                                ",
"                                                                                ",
"                                                                                ",
"                                                                                ",
"                                                                                ",
"                                                                                ",
"                                                                                ",
"                                                                                ",
"                               @@@@@@@@@@@@@@@@@@@                              ",
"                          @@@@                    @@@@                          ",
"                       @@@                             @@@                      ",
"                    @@@@@                               @@@@                    ",
"                  @@  @@@@@@                         @@@@@  @@@                 ",
"                @@     @@  @@@                    @@@@  @@    @@                ",
"               @@       @@    @@@              @@@@    @@       @@              ",
"              @         @@       @@@        @@@@      @@          @             ",
"            @@           @@         @@@   @@@         @@          @@            ",
"            @             @@          @@@@@          @@             @           ",
"           @              @@        @@@@ @@@        @@              @@          ",
"          @@               @@    @@@@       @@@     @@               @          ",
"          @                 @@@@@@             @@@ @@                 @         ",
"          @                 @@@                   @@@                 @         ",
"         @@              @@@ @@                   @@@@@@              @@        ",
"         @@           @@@     @@                 @@    @@@            @@        ",
"         @@         @@@       @@                 @@      @@@@         @@        ",
"          @     @@@@           @@               @@          @@@@      @         ",
"          @@  @@@               @@             @@              @@@@  @@         ",
"          @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@          ",
"           @@                    @@           @@                    @@          ",
"            @@                    @@         @@                    @@           ",
"             @                    @@         @@                   @@            ",
"              @@                   @@       @@                   @@             ",
"               @@                   @@     @@@                  @@              ",
"                 @@                 @@     @@                 @@                ",
"                   @@                @@   @@                @@                  ",
"                     @@               @@ @@@              @@                    ",
"                        @@@           @@ @@           @@@                       ",
"                           @@@@@       @@@        @@@@                          ",
"                                 @@@@@@@@@@@@@@@                                ",
"                                                                                ",
"                                                                                ",
"                                                                                ",
"                                                                                ",
"                                                                                ",
"                                                                                ",
"                                                                                ",
"                                                                                "
    };

    if(mode == 0)
        for (size_t i = 0; i < cross.size(); ++i) {
            std::cout << cross[i] << "   " << pentagram[i] << "\n";
        }
    if(mode == 1)
        for (size_t i = 0; i < cross.size(); ++i) {
            std::cout << pentagram[i] << "   " << cross[i] << "\n";
        }
}

void moveCursor(int row, int col) {
    cout << "\033[" << row << ";" << col << "H";
}

void printRandomChar() {
    vector<string> simbols = {
        "@", "#", "$", "%", "&", "*", "+", "-", "=", "!", "?",
        "§", "¶", "Ω", "Ψ", "∆", "∞", "a", "b", "c", "d", "e",
        "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p",
        "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"
    };

    int maxRows = 47;
    int maxCols = 160;

    int row = rand() % maxRows + 1;
    int col = rand() % maxCols + 1;

    int index = rand() % simbols.size();

    moveCursor(row, col);
    cout << simbols[index] << flush;
}

void introductionSequence()
{
    printSimbols(0);
    Sleep(2500);
    system("cls");
    printSimbols(1);
    Sleep(2500);
    cout << endl << endl;
    for (int i = 0; i < 6000; i++)
    {
        printRandomChar();
    }
    system("cls");
	printHeader("INTRODUCTION");
    cout << "You wake up in a strange world, with no memory of how you got here." << endl;
    Sleep(3000);
	cout << "The only thing you remember is your name and some skills you had before." << endl;
    Sleep(3000);
	cout << "In your backpack you can find some gold coins, basic supplies and your old equipment. There is also a strange device." << endl;
    Sleep(3000);
    cout << "The device starts to glow and you can feel it connect with your mind." << endl;
	Sleep(3000);
	cout << "Your mission is to find your purpose in this world. You can try to fix it, or maybe, end it. That's up to you." << endl;
    Sleep(3000);
    cout << endl << "Press enter to continue..." << endl;
    int key = 0;
    do {
       key = _getch();
	} while (key != 13);
}

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
			eraseLastLine();
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
            "\n+ / - to modify, ENTER when ready";
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
                return "Remaining points: " + to_string(remainingPoints) + "\n+ / - to modify, ENTER when ready";
            },
            [&](int selected, MenuAction action) 
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
    character.addStrength(values[1]);
    character.addAgility(values[2]);
    character.addIntelligence(values[3]);

    character.calculateDerivedStats();
}

bool moveOnMap(WorldMap& map)
{
    system("cls");

    vector<string> options = {
        "NORTH",
        "EAST",
        "WEST",
		"SOUTH",
		"BACK TO MENU"
    };

    while (true)
    {
        int choice = navigateMenu(options, "MOVE TO", "");
        system("cls");
        printHeader("MOVING");

        switch (choice)
        {
        case 0:
            map.movePlayer(0, 1);
			cout << "Going NORTH";
			Sleep(150);
			cout << ".";
            Sleep(150);
            cout << ".";
            Sleep(150);
            cout << ".";
            Sleep(150);
            return true;
        case 1:
            map.movePlayer(1, 0);
            cout << "Going EAST";
            Sleep(150);
            cout << ".";
            Sleep(150);
            cout << ".";
            Sleep(150);
            cout << ".";
            Sleep(150);
            return true;
        case 2:
			map.movePlayer(-1, 0);
            cout << "Going WEST";
            Sleep(150);
            cout << ".";
            Sleep(150);
            cout << ".";
            Sleep(150);
            cout << ".";
            Sleep(150);
            return true;
		case 3:
			map.movePlayer(0, -1);
            cout << "Going SOUTH";
            Sleep(150);
            cout << ".";
            Sleep(150);
            cout << ".";
            Sleep(150);
            cout << ".";
            Sleep(150);
            return true;
        case 4:
            return false;
        default:
			return false;
        }
    }
}

void displayCharacterInfo(baseCharacter* character)
{
    system("cls");
	printHeader("PLAYER INFO");
    character->displayCharacterInfo();
    cout << endl << "Press any key to return..." << endl;
    _getch();
}

void displayCharacterInventory(baseCharacter* character)
{
    system("cls");
    printHeader("INVENTORY");
    while (true)
    {
        int option = navigateInventory(character);
        if (option == -1)
        {
            cout << endl << "Press any key to return..." << endl;
            _getch();
            return;
        }
        else if (option == character->getInventory().size())
        {
            return;
        }
        else
        {
            system("cls");
            printHeader(character->getInventory()[option].item->getName());
            character->getInventory()[option].item->printObjectInfo();
            cout << endl << "Press any key to return..." << endl;
            _getch();
        }
    }
}

void standardGameMenu(WorldMap& map,baseCharacter* player, const string& additionalMessage, const string& header)
{
	system("cls");
    vector<string> options = {
    "Move",
    "Check Character",
	"Check Inventory",
    "Exit"
    };

    while (true)
    {
        int choice = navigateMenu(options, header, additionalMessage);

        switch (choice)
        {
        case 0:
            if (moveOnMap(map))
            {
				system("cls");
                return;
            }
			system("cls");
            break;
        case 1:
			displayCharacterInfo(player);
			system("cls");
            break;
        case 2:
			displayCharacterInventory(player);
			system("cls");
            break;
        case 3:
            cout << "Exiting game..." << endl;
			Sleep(500);
			exit(0);
        }
    }

}

void npcEncounter(WorldMap& map, baseCharacter* player, const string& additionalMessage, const string& header)
{
    system("cls");
    vector<string> options = {
	"Fight",
    "Run Away",
    "Check Character",
    "Check Inventory",
    "Exit"
    };

    while (true)
    {
        int choice = navigateMenu(options, header, additionalMessage);

        switch (choice)
        {
        case 0:
            cout << "Combat feature coming soon!" << endl;
            Sleep(1000);
            system("cls");
			break;
        case 1:
            if (moveOnMap(map))
            {
                system("cls");
                return;
            }
            system("cls");
            break;
        case 2:
            displayCharacterInfo(player);
            system("cls");
            break;
        case 3:
            displayCharacterInventory(player);
            system("cls");
            break;
        case 4:
            cout << "Exiting game..." << endl;
            Sleep(500);
            exit(0);
        }
    }

}

void buildingEncounter(WorldMap& map, baseCharacter* player, const string& additionalMessage, const string& header)
{
    system("cls");
    vector<string> options = {
        "Enter Building",
        "Move",
        "Check Character",
        "Check Inventory",
        "Exit"
    };
    while (true)
    {
        int choice = navigateMenu(options, header, additionalMessage);
        switch (choice)
        {
        case 0:
            cout << "Building feature coming soon!" << endl;
            Sleep(1000);
            system("cls");
            break;
        case 1:
            if (moveOnMap(map))
            {
                system("cls");
                return;
            }
            system("cls");
            break;
        case 2:
            displayCharacterInfo(player);
            system("cls");
            break;
        case 3:
            displayCharacterInventory(player);
            system("cls");
            break;
        case 4:
            cout << "Exiting game..." << endl;
            Sleep(500);
            exit(0);
        }
    }
}

void villageEncounter(WorldMap& map, baseCharacter* player, const string& additionalMessage, const string& header)
{
    system("cls");
    vector<string> options = {
        "Enter Tavern",
		"Enter Blacksmith",
        "Leave Town",
        "Check Character",
        "Check Inventory",
        "Exit"
    };
    while (true)
    {
        int choice = navigateMenu(options, header, additionalMessage);
        switch (choice)
        {
        case 0:
            cout << "Tavern feature coming soon!" << endl;
            Sleep(1000);
            system("cls");
            break;
        case 1:
            cout << "Blacksmith feature coming soon!" << endl;
            Sleep(1000);
            system("cls");
            break;
        case 2:
            if (moveOnMap(map))
            {
                system("cls");
                return;
            }
            system("cls");
            break;
        case 3:
            displayCharacterInfo(player);
            system("cls");
            break;
        case 4:
            displayCharacterInventory(player);
            system("cls");
            break;
        case 5:
            cout << "Exiting game..." << endl;
            Sleep(500);
            exit(0);
        }
    }
}