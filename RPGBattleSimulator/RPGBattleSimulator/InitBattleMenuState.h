#pragma once

class InitBattle;

class InitBattleMenuState
{
public:
	virtual InitBattleMenuState* InputHandler(InitBattle* initBattle, int selection) = 0;
	virtual void PrintMenuOptions() = 0;
	virtual InitBattleMenuState* Enter(InitBattle* initBattle) = 0;
	int GetUserMenuSelection();
};

