#include "Item.h"

string Item::GetName() {
	return name;
}

string Item::GetBuffAsString(BuffType buff) {
	string str = "";
	switch (buff) {
	case BuffType::PHYSDAMAGE:
		str = "Physical Damage";
		break;
	case BuffType::MAGICDAMAGE:
		str = "Magic Damage";
		break;
	case BuffType::SPEED:
		str = "Speed";
		break;
	case BuffType::PHYSDEFENSE:
		str = "Physical Defense";
		break;
	case BuffType::MAGICRESIST:
		str = "Magic Resist";
		break;
	}
	return str;
}

string Item::GetSlotAsString(ItemSlot slot) {
	string str = "";
	switch (slot) {
	case ItemSlot::HEAD:
		str = "Head";
		break;
	case ItemSlot::CHEST:
		str = "Chest";
		break;
	case ItemSlot::HANDS:
		str = "Hands";
		break;
	case ItemSlot::FEET:
		str = "Feet";
		break;
	case ItemSlot::TRINKET:
		str = "Trinket";
		break;
	}
	return str;
}