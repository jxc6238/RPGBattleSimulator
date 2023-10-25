#include "Character.h"
#include <iomanip>

void Character::SetHealth(int healthValue) {
	if (healthValue <= 0) {
		health = 0;
	}
	else {
		health = healthValue;
	}
}
void Character::SetMana(int manaValue) {
	if (manaValue <= 0) {
		mana = 0;
	}
	else {
		mana = manaValue;
	}
}
void Character::SetBaseSpeed(double baseSpeedValue) {
	baseSpeed = baseSpeedValue;
}
void Character::SetBasePhysDamage(double basePhysDamageValue) {
	basePhysDamage = basePhysDamageValue;
}
void Character::SetBaseMagicDamage(double baseMagicDamageValue) {
	baseMagicDamage = baseMagicDamageValue;
}
void Character::SetBasePhysDefense(double basePhysDefenseValue) {
	basePhysDefense = basePhysDefenseValue;
}
void Character::SetBaseMagicResist(double magicResistValue) {
	baseMagicResist = magicResistValue;
}

void Character::SetSpeed(double updatedSpeed) {
	currentSpeed = updatedSpeed;
}
void Character::SetPhysDamage(double updatedPhysDamage) {
	currentPhysDamage = updatedPhysDamage;
}
void Character::SetMagicDamage(double updatedMagicDamage) {
	currentMagicDamage = updatedMagicDamage;
}
void Character::SetPhysDefense(double updatedPhysefense) {
	currentPhysDefense = updatedPhysefense;
}
void Character::SetMagicResist(double updatedMagicResist) {
	currentMagicResist = updatedMagicResist;
}

void Character::SetSpeedMultiplier(double speedMultValue) {
	speedMult = speedMultValue;
	//SetSpeed();
}
void Character::SetPhysDamageMultiplier(double physDamageMultValue) {
	physDamageMult = physDamageMultValue;
	//SetDamage();
}
void Character::SetMagicDamageMultiplier(double magicDamageMultValue) {
	magicDamageMult = magicDamageMultValue;
	//SetMagicDamage();
}
void Character::SetPhysDefenseMultiplier(double physDefenseMultValue) {
	physDefenseMult = physDefenseMultValue;
	//SetDefense();
}
void Character::SetMagicResistMultiplier(double magicResMultValue) {
	magicResistMult = magicResMultValue;
	//SetMagicResist();
}

string Character::GetName() {
	return name;
}
int Character::GetHealth() {
	return health;
}
int Character::GetMana() {
	return mana;
}
double Character::GetSpeed() {
	return currentSpeed;
}
double Character::GetPhysDamage() {
	return currentPhysDamage;
}
double Character::GetMagicDamage() {
	return currentMagicDamage;
}
double Character::GetPhysDefense() {
	return currentPhysDefense;
}
double Character::GetMagicResist() {
	return currentMagicResist;
}

void Character::PrintCharacterStats() {
	std::cout << "Name: " << name <<  "  " <<
		"Health: " << health << "  " <<
		"Mana: " << mana << "  " <<
		"Speed: " << currentSpeed << "  " <<
		"Damage: " << currentPhysDamage << "  " <<
		"Magic Damage: " << currentMagicDamage << "  " <<
		"Defense: " << currentPhysDefense << "  " <<
		"Magic Resist: " << currentMagicResist << std::endl;
}

void Character::EquipItem(EquippedItem* item) {
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
void Character::UnequipItem() {
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

void Character::EquipScale(BuffType buff, double multiplier) {
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

double Character::CalculateScale(double currentVal, double buffVal) {
	return (currentVal * buffVal);
}

void Character::UnequipDescale(const vector<ItemBuffPair>& buffs) {
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

double Character::CalculateDescale(double currentVal, double buffVal) {
	return (currentVal / buffVal);
}

void Character::PrintItemSlots() {
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

void Character::ApplyDebuff(DebuffData* debuff) {
	bool debuffPresent = false;
	unsigned int position = 0;
	for (unsigned int i = 0; i < debuffs.size(); i++) {
		if (debuffs[i]->GetDebuffType() == debuff->GetDebuffType()) {
			debuffPresent = true;
			position = i;
		}
	}
	if (debuffPresent == false) {
		debuffs.push_back(debuff);
		CalculateDebuff(debuff->GetDebuffType(), debuff->GetAfflictionModifier());
	}
	else {
		debuffs[position]->DebuffAlreadyPresent();
	}
}

/**
corresponding pairs
physdamage, magicdamage, speed, physdefense, magicdefense
weak, weakwill, slow, fragile, magicfragile
**/
void Character::CalculateDebuff(DebuffType debuffType, double debuffMultiplier) {
	switch (debuffType) {
	case DebuffType::WEAK:
		prevPhysDamage.first = BuffType::PHYSDAMAGE;
		prevPhysDamage.second = currentPhysDamage;
		SetPhysDamage(CalculateScale(currentPhysDamage, debuffMultiplier));
		break;
	case DebuffType::WEAKWILL:
		prevMagicDamage.first = BuffType::MAGICDAMAGE;
		prevMagicDamage.second = currentMagicDamage;
		SetMagicDamage(CalculateScale(currentMagicDamage, debuffMultiplier));
		break;
	case DebuffType::SLOW:
		prevSpeed.first = BuffType::SPEED;
		prevSpeed.second = currentSpeed;
		SetSpeed(CalculateScale(currentSpeed, debuffMultiplier));
		break;
	case DebuffType::FRAGILE:
		prevPhysDefense.first = BuffType::PHYSDEFENSE;
		prevPhysDefense.second = currentPhysDefense;
		SetPhysDefense(CalculateScale(currentPhysDefense, debuffMultiplier));
		break;
	case DebuffType::MAGICFRAGILE:
		prevMagicResist.first = BuffType::MAGICRESIST;
		prevMagicResist.second = currentMagicResist;
		SetMagicResist(CalculateScale(currentMagicResist, debuffMultiplier));
	}
}

void Character::UpdateDebuffs() {
	DebuffData* tmp = NULL;
	for (std::vector<DebuffData*>::iterator it = debuffs.begin(); it != debuffs.end();) {
		if ((*it)->GetNumOfTurnsLeft() == 1) {
			tmp = (*it);
			it = debuffs.erase(it);
			RemoveDebuff(tmp);
			tmp->DecreaseNumOfTurns();
		}
		else {
			(*it)->DecreaseNumOfTurns();
			it++;
		}
	}
	for (auto& debuff : debuffs) {
		debuff->PrintDebuffData();
	}
}

void Character::RemoveDebuff(DebuffData* debuff) {
	switch (debuff->GetDebuffType()) {
	case DebuffType::WEAK:
		SetPhysDamage(prevPhysDamage.second);
		break;
	case DebuffType::WEAKWILL:
		SetMagicDamage(prevMagicDamage.second);
		break;
	case DebuffType::SLOW:
		SetSpeed(prevSpeed.second);
		break;
	case DebuffType::FRAGILE:
		SetPhysDefense(prevPhysDefense.second);
		break;
	case DebuffType::MAGICFRAGILE:
		SetMagicResist(prevMagicResist.second);
		break;
	}
}

