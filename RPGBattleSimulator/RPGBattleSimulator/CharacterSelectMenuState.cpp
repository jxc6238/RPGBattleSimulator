#include "CharacterSelectMenuState.h"
#include "InitBattle.h"
#include "MainMenuState.h"
#include <iostream>
#include <iomanip>

InitBattleMenuState* CharacterSelectMenuState::Enter(InitBattle* initBattle) {
	PrintMenuOptions();
	int selection = GetUserMenuSelection();
	return InputHandler(initBattle, selection);
}

//1. AddCharacter, 2. RemoveCharacter
void CharacterSelectMenuState::PrintMenuOptions() {
	std::cout << std::setfill('-') << std::setw(30) << '-' <<
		"Character Select" <<
		std::setfill('-') << std::setw(30) << '-' << std::endl
		<< "1. Add Character" << std::endl
		<< "2. Remove Character" << std::endl
		<< "3. Return to Main Menu" << std::endl;
}

InitBattleMenuState* CharacterSelectMenuState::InputHandler(InitBattle* initBattle, int selection) {
	switch (selection) {
	case 1:
		initBattle->AddCharacterToParty();
		return new CharacterSelectMenuState();
	case 2:
		initBattle->RemoveCharacterFromParty();
		return new CharacterSelectMenuState();
	case 3:
		return new MainMenuState();
	default:
		return new CharacterSelectMenuState();
	}
}