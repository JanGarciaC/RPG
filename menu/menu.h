#pragma once
#include <string>
#include "../characters/characterClass.h"
#include "../map/worldMap.h"

baseCharacter* startMenu();
void classMenu(baseCharacter& character);
void defineStatMenu(baseCharacter& character);
void standardGameMenu(WorldMap& map, baseCharacter* player, std::string additionalMessage);