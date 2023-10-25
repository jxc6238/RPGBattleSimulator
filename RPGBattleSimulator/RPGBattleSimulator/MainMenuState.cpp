#include "MainMenuState.h"
#include "ItemMenuState.h"
#include <iostream>
#include <iomanip>

InitBattleMenuState* MainMenuState::Enter(InitBattle* initBattle) {
	PrintMenuOptions();
	int selection = GetUserMenuSelection();
	return InputHandler(initBattle, selection);
}

void MainMenuState::PrintMenuOptions() {
	std::cout << std::setfill('-') << std::setw(30) << '-' <<
		"Main Menu" << std::setfill('-') << std::setw(30) << '-' << std::endl
		<< "1. Party" << std::endl
		<< "2. Items" << std::endl << "3. Start Battle" << std::endl;
}

//1.AddCharacter, 2.EquipItem, 3. BeginBattle
InitBattleMenuState* MainMenuState::InputHandler(InitBattle* initBattle, int selection) {
	switch (selection) {
	case 1:
		return new CharacterSelectMenuState();
	case 2:
		return new ItemMenuState();
	case 3:
		return NULL;
	default:
		return new MainMenuState();
	}

}