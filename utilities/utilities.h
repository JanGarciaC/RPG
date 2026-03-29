#pragma once

#include <vector>
#include <string>

void printHeader(const std::string& header);
void printMenu(const std::vector<std::string>& options, int selected, std::string header);
int navigateMenu(const std::vector<std::string>& options, std::string header);