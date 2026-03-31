#include <iostream>
#include <ctime>
#include "characters/characterClass.h"
#include "menu/menu.h"
#include "map/worldMap.h"

using namespace std;

int main()
{
	srand(time(0));
    baseCharacter* player = startMenu();
	WorldMap worldMap;

	system("cls");

	introductionSequence();

	while (true)
	{
		string header;
		int r = rand() % 100;
		if (r < player->getOrientationSkill())
			header = "WORLD - OUTSIDE [" + to_string(worldMap.getCurrentTile()->getX()) + ", " + to_string(worldMap.getCurrentTile()->getY()) + "]";
		else
			header = "WORLD - OUTSIDE [?, ?]";

		standardGameMenu(worldMap, player, worldMap.getCurrentTileMessage(), header);
	}
	
    delete player;
    return 0;
}