#include "EquippedItem.h"
#include <iostream>
#include <iomanip>

const vector<ItemBuffPair>& EquippedItem::GetBuffs() {
	return buffs;
}

const ItemSlot& EquippedItem::GetSlot() {
	return slot;
}

void EquippedItem::PrintItemInfo() {
	string str = "";
	cout << GetName() <<
		" " << "Slot: " << GetSlotAsString(slot);
	for (unsigned int i = 0; i < buffs.size(); i++) {
		cout <<
			" Buff Type: " << GetBuffAsString(buffs[i].buff) << " " <<
			" Modifier: " << buffs[i].buffStat;
	}
	std::cout << std::endl;
}