#include <iostream>
#include "characters/characterClass.h"
#include "menu/menu.h"
#include "map/worldMap.h"

using namespace std;

int main()
{
    baseCharacter* player = startMenu();
	WorldMap worldMap;

	system("cls");

	while (true)
	{
		standardGameMenu(worldMap, player, worldMap.getCurrentTileMessage());
	}
	
    delete player;
    return 0;
}