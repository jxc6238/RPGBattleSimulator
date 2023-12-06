#pragma once
#include "Character.h"

class PlayerCharacter: public Character
{
private:
	CurrentlyEquippedItems equippedItems;
public:
	PlayerCharacter(string name, int health, int mana, double baseSpeed,
		double basePhysDamage, double baseMagicDamage,
		double basePhysDefense, double baseMagicResist) : Character(name, health,
			mana, baseSpeed, basePhysDamage, baseMagicDamage, basePhysDefense,
			baseMagicResist), equippedItems() {};

	void EquipItem(EquippedItem* item);
	void UnequipItem();
	void EquipScale(BuffType buff, double multiplier);
	void UnequipDescale(const vector<ItemBuffPair>& buffs);
	void PrintItemSlots();
};

