#include "InitBattleMenuState.h"
#include <iostream>

int InitBattleMenuState::GetUserMenuSelection() {
	int selection = 0;
	std::cout << "Please enter menu selection: ";
	std::cin >> selection;
	return selection;
}