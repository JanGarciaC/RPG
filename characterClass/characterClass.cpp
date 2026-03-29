#include "characterClass.h"
#include "../menu/menu.h"
#include "../utilities/utilities.h"
#include <iostream>
#include <windows.h>

using namespace std;

baseCharacter* characterCreation()
{
    system("cls");

    printHeader("ENTER NAME");

    string name;
    cout << "Enter your character's name: ";
    getline(cin >> ws, name);

    baseCharacter temp;
    temp.defineName(name);

    classMenu(temp);  
    statMenu(temp);

    // Creem subclasse final
    if (temp.getCharacterClass() == 1) return new classWarrior(temp);
    if (temp.getCharacterClass() == 2) return new classRogue(temp);
    return new classMage(temp);
}