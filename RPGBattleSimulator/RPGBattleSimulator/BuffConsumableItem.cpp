#include "BuffConsumableItem.h"
BuffFactory* BuffConsumableItem::buffFactory = new BuffFactory();

void BuffConsumableItem::UseConsumable(Character* target) {
	target->ApplyBuff(buffFactory->GetBuffObject(buff));
}

void BuffConsumableItem::PrintItemInfo() {
	cout << "Name: " << GetName() << " " << "Buff: " << GetBuffAsString(buff) << endl;
}
