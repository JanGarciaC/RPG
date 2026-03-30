#include <iostream>
#include "characterClass/characterClass.h"
#include "menu/menu.h"

using namespace std;

int main()
{
    baseCharacter* player = startMenu();

	system("cls");

	standardGameMenu(player, "Welcome to the world of RPG! Your adventure begins now...");

    delete player;
    return 0;
}