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

		if (worldMap.getCurrentTile()->getX() == 0 && worldMap.getCurrentTile()->getY() == 0)
			header = "WORLD - VILLAGE [0, 0]";

		TileEvent currentEvent = worldMap.getCurrentTile()->getTileEvent();
		string message = worldMap.getCurrentTile()->getTileMessage();

		switch (currentEvent)
		{
		case NOTHING:
			standardGameMenu(worldMap, player, message, header);
			break;
		case VILLAGE:
			villageEncounter(worldMap, player, message, header);
			break;
		case NPC:
			npcEncounter(worldMap, player, message, header);
			break;
		case MONEY:
			if (!worldMap.getCurrentTile()->getCondition())
			{
				worldMap.getCurrentTile()->markCondition();
				player->addGold(worldMap.getCurrentTile()->getMoney());
			}
			standardGameMenu(worldMap, player, message, header);
			break;
		case RANDOMLOOT:
			standardGameMenu(worldMap, player, message, header);
			break;
		case RANDOMBUILDING:
			buildingEncounter(worldMap, player, message, header);
			break;
		case CAT:
			if (!worldMap.getCurrentTile()->getCondition())
			{
				worldMap.getCurrentTile()->markCondition();
				player->addStamina(1);
				player->addStrength(1);
				player->addAgility(1);
				player->addIntelligence(1);
			}
			standardGameMenu(worldMap, player, message, header);
			break;
		default:
			break;
		}
	}
	
    delete player;
    return 0;
}