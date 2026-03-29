#include "characterClass.h"
#include "utilities.h"

baseCharacter* startMenu()
{
    vector<string> options = {
        "Start New Game",
        "Load Game (Coming Soon)",
        "Exit"
    };

    while (true)
    {
        int choice = navigateMenu(options);

        switch (choice)
        {
        case 0:
            cout << "Starting new game...";
            Sleep(1000);
            return characterCreation();

        case 1:
            cout << "Load game feature coming soon!";
            Sleep(1500);
            break;

        case 2:
            cout << "Exiting game...";
            exit(0);
        }
    }
}

int main()
{
    baseCharacter* player = startMenu();
    player->attack();
    delete player;
    return 0;
}