#pragma 
#include "InitBattle.h"
#include "InitBattleMenuState.h"

class ItemMenuState : public InitBattleMenuState
{
public:
	InitBattleMenuState* InputHandler(InitBattle* initBattle, int selection) override;
	void PrintMenuOptions() override;
	InitBattleMenuState* Enter(InitBattle* initBattle) override;
};

