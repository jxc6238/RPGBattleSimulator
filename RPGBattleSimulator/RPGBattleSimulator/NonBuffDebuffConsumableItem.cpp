#include "NonBuffDebuffConsumableItem.h"

void NonBuffDebuffConsumableItem::UseConsumable(Character* target) {
	if (healthItem == true) {
		target->SetHealth(target->GetHealth() + modifierAmount);
	}
	else {
		target->SetMana(target->GetMana() + modifierAmount);
	}
}

void NonBuffDebuffConsumableItem::PrintItemInfo() {
	cout << "Name: " << GetName() << " " << "Amount: " << modifierAmount << endl;
}