#pragma once
#include "InitBattle.h"
#include "InitBattleMenuState.h"
#include "CharacterSelectMenuState.h"

class MainMenuState : public InitBattleMenuState
{
public:
	InitBattleMenuState* InputHandler(InitBattle* initBattle, int selection) override;
	void PrintMenuOptions() override;
	InitBattleMenuState* Enter(InitBattle* initBattle) override;
};

