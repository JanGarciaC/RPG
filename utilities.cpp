#include "utilities.h"

void printMenu(const vector<string>& options, int selected)
{
    system("cls");

    cout << "===================================" << endl;
    cout << "============= Welcome =============" << endl;
    cout << "===================================" << endl << endl;

    for (int i = 0; i < options.size(); i++)
    {
        if (i == selected)
            cout << "> " << options[i] << endl;
        else
            cout << "  " << options[i] << endl;
    }
}

int navigateMenu(const vector<string>& options)
{
    int selected = 0;

    while (true)
    {
        printMenu(options, selected);

        int key = _getch();

        if (key == 224)
        {
            key = _getch();

            switch (key)
            {
            case 72:
                selected--;
                if (selected < 0) selected = options.size() - 1;
                break;

            case 80:
                selected++;
                if (selected >= options.size()) selected = 0;
                break;
            }
        }
        else if (key == 13)
        {
            return selected;
        }
    }
}