#pragma once
#include <string>
#include "../characters/characterClass.h"
#include "../map/worldMap.h"

baseCharacter* startMenu();
void introductionSequence();
void classMenu(baseCharacter& character);
void defineStatMenu(baseCharacter& character);
void standardGameMenu(WorldMap& map, baseCharacter* player, const std::string& additionalMessage, const std::string& header);
void npcEncounter(WorldMap& map, baseCharacter* player, const std::string& additionalMessage, const std::string& header);
void buildingEncounter(WorldMap& map, baseCharacter* player, const std::string& additionalMessage, const std::string& header);
void villageEncounter(WorldMap& map, baseCharacter* player, const std::string& additionalMessage, const std::string& header);
