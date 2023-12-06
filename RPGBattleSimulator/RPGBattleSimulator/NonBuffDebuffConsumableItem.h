#pragma once
#include "ConsumableItem.h"

class NonBuffDebuffConsumableItem : public ConsumableItem
{
private:
	bool healthItem;
	int modifierAmount;
public:
	NonBuffDebuffConsumableItem(string name, bool healthItem, int modifierAmount) :
		ConsumableItem(name), healthItem(healthItem), modifierAmount(modifierAmount) {};
	void UseConsumable(Character* target) override;
	void PrintItemInfo() override;
};

