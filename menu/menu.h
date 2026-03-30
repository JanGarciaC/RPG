#pragma once
#include <string>
#include "../characterClass/characterClass.h"

baseCharacter* startMenu();
void classMenu(baseCharacter& character);
void defineStatMenu(baseCharacter& character);
void standardGameMenu(std::string additionalMessage);