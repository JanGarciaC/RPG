#include <iostream>
#include "characterClass/characterClass.h"
#include "menu/menu.h"

using namespace std;

int main()
{
    baseCharacter* player = startMenu();

	system("cls");

    cout << player->getName() << " attacked and did " << player->baseAttack() << " damage" << endl;

    delete player;
    return 0;
}