#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

int navigateMenu(const std::vector<std::string>& options);
void printMenu(const std::vector<std::string>& options, int selected);