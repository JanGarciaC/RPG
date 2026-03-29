#include "utilities.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void printHeader(const string& header)
{
    for (int i = 0; i < header.size() + 20; i++)
        cout << "=";
    cout << endl << "========= " << header << " =========" << endl;
    for (int i = 0; i < header.size() + 20; i++)
        cout << "=";
    cout << endl << endl;
}

void printMenu(const vector<string>& options, int selected, string header)
{
    system("cls");

	printHeader(header);

    for (int i = 0; i < options.size(); i++)
    {
        if (i == selected) cout << "> ";
        else cout << "  ";
        cout << options[i] << endl;
    }
}

int navigateMenu(const vector<string>& options, string header)
{
    int selected = 0;

    while (true)
    {
        printMenu(options, selected, header);
        int key = _getch();

        if (key == 224) // fletxes
        {
            key = _getch();
            if (key == 72) selected = (selected + options.size() - 1) % options.size(); // UP
            if (key == 80) selected = (selected + 1) % options.size(); // DOWN
        }
        else if (key == 13) // ENTER
        {
            return selected;
        }
    }
}