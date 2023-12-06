#include "DebuffConsumableItem.h"
DebuffFactory* DebuffConsumableItem::debuffFactory = new DebuffFactory();

void DebuffConsumableItem::UseConsumable(Character* target) {
	target->ApplyDebuff(debuffFactory->GetDebuffObject(debuff));
}

void DebuffConsumableItem::PrintItemInfo() {
	cout << "Name: " << GetName() << " " << "Debuff: " << GetDebuffAsString(debuff) << endl;
}

string DebuffConsumableItem::GetDebuffAsString(DebuffType debuff) {
	switch (debuff) {
	case DebuffType::WEAK:
		return "WEAK";
	case DebuffType::WEAKWILL:
		return "WEAKWILL";
	case DebuffType::SLOW:
		return "SLOW";
	case DebuffType::FRAGILE:
		return "FRAGILE";
	case DebuffType::MAGICFRAGILE:
		return "MAGICFRAGILE";
	}
}