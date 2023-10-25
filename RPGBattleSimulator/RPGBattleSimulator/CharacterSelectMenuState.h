#pragma once
#include "InitBattleMenuState.h"

class CharacterSelectMenuState : public InitBattleMenuState
{
public:
	InitBattleMenuState* InputHandler(InitBattle* initBattle, int selection) override;
	void PrintMenuOptions() override;
	InitBattleMenuState* Enter(InitBattle* initBattle) override;
};

