#include "ItemMenuState.h"
#include "MainMenuState.h"

InitBattleMenuState* ItemMenuState::Enter(InitBattle* initBattle) {
	PrintMenuOptions();
	int selection = GetUserMenuSelection();
	return InputHandler(initBattle, selection);
}

//1. Equip Item, 2. Remove Item, 3. Return to prev menu
void ItemMenuState::PrintMenuOptions() {
	std::cout << std::setfill('-') << std::setw(30) << '-' <<
		"Item Menu" <<
		std::setfill('-') << std::setw(30) << '-' << endl
		<< "1. Equip Item" << std::endl
		<< "2. Remove Item" << std::endl
		<< "3. Return to Main Menu" << std::endl;
}

//1. Equip Item, 2. Remove Item, 3. Return to prev menu
InitBattleMenuState* ItemMenuState::InputHandler(InitBattle* initBattle, int selection) {
	switch (selection) {
	case 1:
		initBattle->EquipItem();
		return new ItemMenuState();
	case 2:
		initBattle->UnequipItem();
		return new ItemMenuState();
	case 3:
		return new MainMenuState();
	default:
		return new ItemMenuState();
	}
}