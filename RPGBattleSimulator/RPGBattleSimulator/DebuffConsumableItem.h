#pragma once

#include "ConsumableItem.h"
#include "DebuffTypeEnum.h"
#include "DebuffFactory.h"

class DebuffConsumableItem: public ConsumableItem
{
private:
	DebuffType debuff;
	static DebuffFactory* debuffFactory;
public:
	DebuffConsumableItem(string name, DebuffType debuff) : ConsumableItem(name),
		debuff(debuff) {};
	void UseConsumable(Character* target) override;
	void PrintItemInfo() override;
	string GetDebuffAsString(DebuffType debuff);
};

