#include "PlayerCharacter.h"

void PlayerCharacter::EquipItem(EquippedItem* item) {
	switch (item->GetSlot()) {
	case ItemSlot::HEAD:
		equippedItems.headSlot = item;
		break;
	case ItemSlot::CHEST:
		equippedItems.chestSlot = item;
		break;
	case ItemSlot::HANDS:
		equippedItems.handsSlot = item;
		break;
	case ItemSlot::FEET:
		equippedItems.feetSlot = item;
		break;
	case ItemSlot::TRINKET:
		equippedItems.trinketSlotLeft = item;
		break;
	}
	vector<ItemBuffPair> buffs = item->GetBuffs();
	for (auto& buff : buffs) {
		EquipScale(buff.buff, buff.buffStat);
	}
}
void PlayerCharacter::UnequipItem() {
	unsigned int choice;
	std::cout << name << " Equipped Items:" << endl;
	for (unsigned int i = 0; i < 5; i++) {
		std::cout << i + 1 << " ";
		switch (i) {
		case 0:
			if (equippedItems.headSlot != NULL) {
				equippedItems.headSlot->PrintItemInfo();
			}
			else {
				std::cout << "Empty" << std::endl;
			}
			break;
		case 1:
			if (equippedItems.chestSlot != NULL) {
				equippedItems.chestSlot->PrintItemInfo();
			}
			else {
				cout << "Empty" << std::endl;
			}
			break;
		case 2:
			if (equippedItems.handsSlot != NULL) {
				equippedItems.handsSlot->PrintItemInfo();
			}
			else {
				cout << "Empty" << std::endl;
			}
			break;
		case 3:
			if (equippedItems.feetSlot != NULL) {
				equippedItems.feetSlot->PrintItemInfo();
			}
			else {
				cout << "Empty" << std::endl;
			}
			break;
		case 4:
			if (equippedItems.trinketSlotLeft != NULL) {
				equippedItems.trinketSlotLeft->PrintItemInfo();
			}
			else {
				cout << "Empty" << std::endl;
			}
			break;
		}
	}
	cout << endl;
	cout << "Select item to unequip: ";
	cin >> choice;
	switch (choice) {
	case 1:
		UnequipDescale(equippedItems.headSlot->GetBuffs());
		equippedItems.headSlot = NULL;
		break;
	case 2:
		UnequipDescale(equippedItems.chestSlot->GetBuffs());
		equippedItems.chestSlot = NULL;
		break;
	case 3:
		UnequipDescale(equippedItems.handsSlot->GetBuffs());
		equippedItems.handsSlot = NULL;
		break;
	case 4:
		UnequipDescale(equippedItems.feetSlot->GetBuffs());
		equippedItems.feetSlot = NULL;
		break;
	case 5:
		UnequipDescale(equippedItems.trinketSlotLeft->GetBuffs());
		equippedItems.trinketSlotLeft = NULL;
		break;
	}
	PrintCharacterStats();
}

void PlayerCharacter::EquipScale(BuffType buff, double multiplier) {
	switch (buff) {
	case BuffType::PHYSDAMAGE:
		SetPhysDamage(CalculateScale(currentPhysDamage, multiplier));
		break;
	case BuffType::MAGICDAMAGE:
		SetMagicDamage(CalculateScale(currentMagicDamage, multiplier));
		break;
	case BuffType::SPEED:
		SetSpeed(CalculateScale(currentSpeed, multiplier));
		break;
	case BuffType::PHYSDEFENSE:
		SetPhysDefense(CalculateScale(currentPhysDefense, multiplier));
		break;
	case BuffType::MAGICRESIST:
		SetMagicResist(CalculateScale(currentMagicResist, multiplier));
		break;
	}
}

void PlayerCharacter::UnequipDescale(const vector<ItemBuffPair>& buffs) {
	for (auto& buff : buffs) {
		switch (buff.buff) {
		case BuffType::PHYSDAMAGE:
			SetPhysDamage(CalculateDescale(currentPhysDamage, buff.buffStat));
			break;
		case BuffType::MAGICDAMAGE:
			SetMagicDamage(CalculateDescale(currentMagicDamage, buff.buffStat));
			break;
		case BuffType::SPEED:
			SetSpeed(CalculateDescale(currentSpeed, buff.buffStat));
			break;
		case BuffType::PHYSDEFENSE:
			SetPhysDefense(CalculateDescale(currentPhysDefense, buff.buffStat));
			break;
		case BuffType::MAGICRESIST:
			SetMagicResist(CalculateDescale(currentMagicResist, buff.buffStat));
			break;
		}
	}
}

void PlayerCharacter::PrintItemSlots() {
	std::cout << "Head Slot: ";
	if (equippedItems.headSlot != NULL) {
		equippedItems.headSlot->PrintItemInfo();
	}
	else {
		std::cout << "Empty" << std::endl;
	}
	std::cout << "Chest Slot: ";
	if (equippedItems.chestSlot != NULL) {
		equippedItems.chestSlot->PrintItemInfo();
	}
	else {
		std::cout << "Empty" << std::endl;
	}
	std::cout << "Hands Slot: ";
	if (equippedItems.handsSlot != NULL) {
		equippedItems.handsSlot->PrintItemInfo();
	}
	else {
		std::cout << "Empty" << std::endl;
	}
	std::cout << "Feet Slot: ";
	if (equippedItems.feetSlot != NULL) {
		equippedItems.feetSlot->PrintItemInfo();
	}
	else {
		std::cout << "Empty" << std::endl;
	}
	std::cout << "Trinket Slot: ";
	if (equippedItems.trinketSlotRight != NULL) {
		equippedItems.trinketSlotRight->PrintItemInfo();
	}
	else {
		std::cout << "Empty" << std::endl;
	}
}