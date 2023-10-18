#pragma once
#include "Item.h"
#include "ItemBuffPairs.h"
#include "ItemSlotsEnum.h"
#include <vector>
#include <string>
using namespace std;

class EquippedItem : public Item
{
private:
	ItemSlot slot;
	vector<ItemBuffPair> buffs;
	bool equipped;
	static const int WORDSPACING = 10;
public:
	EquippedItem(string name, ItemSlot slot, vector<ItemBuffPair> const &buffs) : 
		slot(slot), equipped(false), buffs(), Item(name) {
		this->buffs = buffs;
	}

	const vector<ItemBuffPair>& GetBuffs();
	const ItemSlot& GetSlot();
	void PrintItemInfo() override;
};

