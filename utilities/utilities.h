#pragma once

#include <vector>
#include <string>
#include <functional>

enum MenuAction
{
    ACTION_NONE,
    ACTION_UP,
    ACTION_DOWN,
    ACTION_SELECT,
    ACTION_PLUS,
    ACTION_MINUS
};

void eraseLastLine();
void printHeader(const std::string& header);
void printMenu(const std::vector<std::string>& options, int selected, std::string header, std::string additionalMessage);
int navigateMenu(const std::vector<std::string>& options, std::string header, std::string additionalMessage);
int navigateMenuAdvanced(std::function<std::vector<std::string>()> getOptions, std::string header, std::function<std::string()> getMessage, std::function<void(int, MenuAction)> onAction);