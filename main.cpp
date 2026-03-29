#include <iostream>
#include "characterClass/characterClass.h"
#include "menu/menu.h"

using namespace std;

int main()
{
    baseCharacter* player = startMenu();

	system("cls");

    player->baseattack();

    delete player;
    return 0;
}