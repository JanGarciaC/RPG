#include "utilities.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void eraseLastLine()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) return;

    COORD coord;
    coord.X = 0;
    coord.Y = csbi.dwCursorPosition.Y - 1;
    SetConsoleCursorPosition(hConsole, coord);

    DWORD written;
    FillConsoleOutputCharacter(hConsole, ' ', csbi.dwSize.X, coord, &written);

    SetConsoleCursorPosition(hConsole, coord);
}

void moveCursorToTop()
{
    COORD coord = { 0, 0 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

MenuAction getMenuInput()
{
    int key = _getch();

    if (key == 224)
    {
        key = _getch();
        if (key == 72) return ACTION_UP;
        if (key == 80) return ACTION_DOWN;
    }
    else
    {
        if (key == 13) return ACTION_SELECT;
        if (key == '+') return ACTION_PLUS;
        if (key == '-') return ACTION_MINUS;
    }

    return ACTION_NONE;
}

void printHeader(const string& header)
{
    for (int i = 0; i < header.size() + 20; i++)
        cout << "=";
    cout << endl << "========= " << header << " =========" << endl;
    for (int i = 0; i < header.size() + 20; i++)
        cout << "=";
    cout << endl << endl;
}

void printMenu(const vector<string>& options, int selected, string header, string additionalMessage)
{
    moveCursorToTop();
    printHeader(header);

    if (!additionalMessage.empty())
    {
        cout << "\r" << string(80, ' ') << "\r";
        cout << additionalMessage << endl;
    }

    for (int i = 0; i < options.size(); i++)    
    {
        cout << "\r" << string(80, ' ') << "\r";
        cout << (i == selected ? "> " : "  ") << options[i] << endl;
    }
}

int navigateMenu(const vector<string>& options, string header, string additionalMessage)
{
    int selected = 0;

    while (true)
    {
        printMenu(options, selected, header, additionalMessage);

        MenuAction action = getMenuInput();

        switch (action)
        {
        case ACTION_UP:
            selected = (selected - 1 + options.size()) % options.size();
            break;

        case ACTION_DOWN:
            selected = (selected + 1) % options.size();
            break;

        case ACTION_SELECT:
            return selected;

        default:
            break;
        }
    }
}

int navigateInventory(baseCharacter* player)
{
    int selected = 0;

    vector<string> options;

    for (size_t i = 0; i < player->getInventory().size(); i++)
    {
        options.push_back('"' + player->getInventory()[i].item->getName() + '"' + " - amount: " + to_string(player->getInventory()[i].quantity));
	}

	options.push_back("return to main menu....");

    if (options.size() > 1)
    {
    while (true)
    {
        moveCursorToTop();
        printHeader("INVENTORY");

        cout << "\r" << string(80, ' ') << "\r";
		cout << "Gold: " << player->getGold() << endl << endl;

        cout << "\r" << string(80, ' ') << "\r";
		cout << "////////// EQUIPPED WEAPON //////////" << endl;
		player->getEquippedWeapon().printObjectInfo();
        cout << endl;

		cout << "\r" << string(80, ' ') << "\r";
		cout << "////////// EQUIPPED ARMOR //////////" << endl;
		player->getEquippedArmor().printObjectInfo();
        cout << endl;

        cout << "\r" << string(80, ' ') << "\r";
		cout << "////////// INVENTORY ITEMS //////////" << endl;
        for (int i = 0; i < options.size(); i++)
        {
            cout << "\r" << string(80, ' ') << "\r";
            cout << (i == selected ? "> " : "  ") << options[i] << endl;
        }

        MenuAction action = getMenuInput();

        switch (action)
        {
        case ACTION_UP:
            selected = (selected - 1 + options.size()) % options.size();
            break;

        case ACTION_DOWN:
            selected = (selected + 1) % options.size();
            break;

        case ACTION_SELECT:
            return selected;

        default:
            break;
        }
    }
    }
    else
    {
        moveCursorToTop();
        printHeader("INVENTORY");

        cout << "\r" << string(80, ' ') << "\r";
        cout << "Gold: " << player->getGold() << endl << endl;

        cout << "\r" << string(80, ' ') << "\r";
        cout << "////////// EQUIPPED WEAPON //////////" << endl;
        player->getEquippedWeapon().printObjectInfo();
        cout << endl;

        cout << "\r" << string(80, ' ') << "\r";
        cout << "////////// EQUIPPED ARMOR //////////" << endl;
        player->getEquippedArmor().printObjectInfo();
        cout << endl;

        cout << "\r" << string(80, ' ') << "\r";
        cout << "////////// INVENTORY ITEMS //////////" << endl;
        cout << "\r" << string(80, ' ') << "\r" << "Your inventory is empty." << endl;
        return -1;
    }
}

int navigateMenuAdvanced(function<vector<string>()> getOptions, string header, function<string()> getMessage, function<void(int, MenuAction)> onAction)
{
    int selected = 0;

    while (true)
    {
        printMenu(getOptions(), selected, header, getMessage());

        MenuAction action = getMenuInput();

        switch (action)
        {
        case ACTION_UP:
            selected = (selected + getOptions().size() - 1) % getOptions().size();
            break;

        case ACTION_DOWN:
            selected = (selected + 1) % getOptions().size();
            break;

        case ACTION_SELECT:
            return selected;

        default:
            if (action != ACTION_NONE)
                onAction(selected, action);
            break;
        }
    }
}