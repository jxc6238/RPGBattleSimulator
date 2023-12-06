#include "Character.h"
#include <iomanip>

BuffDebuffHandler Character::buffDebuffHandler;


void Character::SetHealth(int healthValue) {
	if (healthValue <= 0) {
		health = 0;
	}
	else if (healthValue >= maxHealth) {
		health = maxHealth;
	}
	else {
		health = healthValue;
	}
}
void Character::SetMana(int manaValue) {
	if (manaValue <= 0) {
		mana = 0;
	}
	else if (manaValue >= maxMana) {
		mana = maxMana;
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
	std::cout << "Buffs: "; PrintBuffData(); std::cout << std::endl;
	std::cout << "Debuffs: "; PrintDebuffData(); std::cout << std::endl;
}

double Character::CalculateScale(double currentVal, double buffVal) {
	return (currentVal * buffVal);
}
double Character::CalculateDescale(double currentVal, double buffVal) {
	return (currentVal / buffVal);
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
		BuffType presentBuff = buffDebuffHandler.GetDebuffOpposite(debuff->GetDebuffType());
		if (BuffPresentCheck(presentBuff) == true) {
			RemoveBuff(buffs[GetBuffPosition(presentBuff)]);
		}
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

void Character::ApplyBuff(BuffData* buff) {
	bool buffPresent = false;
	unsigned int position = 0;
	for (unsigned int i = 0; i < buffs.size(); i++) {
		if (buffs[i]->GetBuffType() == buff->GetBuffType()) {
			buffPresent = true;
			position = i;
			break;
		}
	}
	if (buffPresent == false) {
		buffs.push_back(buff);
		DebuffType presentDebuff = buffDebuffHandler.GetBuffOpposite(buff->GetBuffType());
		if (DebuffPresentCheck(presentDebuff) == true) {
			RemoveDebuff(debuffs[GetDebuffPosition(presentDebuff)]);
		}
		CalculateBuff(buff->GetBuffType(), buff->GetBuffModifier());
	}
	else {
		buffs[position]->BuffAlreadyPresent();
	}
}
void Character::CalculateBuff(BuffType buff, double buffMultiplier) {
	switch (buff) {
	case BuffType::PHYSDAMAGE:
		prevPhysDamage.first = BuffType::PHYSDAMAGE;
		prevPhysDamage.second = currentPhysDamage;
		SetPhysDamage(CalculateScale(currentPhysDamage, buffMultiplier));
		break;
	case BuffType::MAGICDAMAGE:
		prevMagicDamage.first = BuffType::MAGICDAMAGE;
		prevMagicDamage.second = currentMagicDamage;
		SetMagicDamage(CalculateScale(currentMagicDamage, buffMultiplier));
		break;
	case BuffType::SPEED:
		prevSpeed.first = BuffType::SPEED;
		prevSpeed.second = currentSpeed;
		SetSpeed(CalculateScale(currentSpeed, buffMultiplier));
		break;
	case BuffType::PHYSDEFENSE:
		prevPhysDefense.first = BuffType::PHYSDEFENSE;
		prevPhysDefense.second = currentPhysDefense;
		SetPhysDefense(CalculateScale(currentPhysDefense, buffMultiplier));
		break;
	case BuffType::MAGICRESIST:
		prevMagicResist.first = BuffType::MAGICRESIST;
		prevMagicResist.second = currentMagicResist;
		SetMagicResist(CalculateScale(currentMagicResist, buffMultiplier));
	}
}
void Character::UpdateBuffs() {
	BuffData* tmp = NULL;
	for (std::vector<BuffData*>::iterator it = buffs.begin(); it != buffs.end();) {
		if ((*it)->GetNumOfTurnsLeft() == 1) {
			tmp = (*it);
			it = buffs.erase(it);
			RemoveBuff(tmp);
			tmp->DecreaseNumOfTurns();
		}
		else {
			(*it)->DecreaseNumOfTurns();
			it++;
		}
	}
}
void Character::RemoveBuff(BuffData* buff) {
	switch (buff->GetBuffType()) {
	case BuffType::PHYSDAMAGE:
		SetBasePhysDefense(prevPhysDamage.second);
	case BuffType::MAGICDAMAGE:
		SetMagicDamage(prevMagicDamage.second);
	case BuffType::SPEED:
		SetSpeed(prevSpeed.second);
	case BuffType::PHYSDEFENSE:
		SetPhysDefense(prevPhysDefense.second);
	case BuffType::MAGICRESIST:
		SetMagicResist(prevMagicResist.second);
	}
}


bool Character::BuffPresentCheck(BuffType buff) {
	for (unsigned int i = 0; i < buffs.size(); i++) {
		if (buffs[i]->GetBuffType() == buff) {
			return true;
		}
	}
	return false;
}

bool Character::DebuffPresentCheck(DebuffType debuff) {
	for (unsigned int i = 0; i < debuffs.size(); i++) {
		if (debuffs[i]->GetDebuffType() == debuff) {
			return true;
		}
	}
	return false;
}

int Character::GetDebuffPosition(DebuffType debuff) {
	for (unsigned int i = 0; i < debuffs.size(); i++) {
		if (debuffs[i]->GetDebuffType() == debuff) {
			return i;
		}
	}
	return -1;
}

int Character::GetBuffPosition(BuffType buff) {
	for (unsigned int i = 0; i < buffs.size(); i++) {
		if (buffs[i]->GetBuffType() == buff) {
			return i;
		}
	}
	return -1;
}

void Character::PrintBuffData() {
	for (auto& buff : buffs) {
		buff->PrintBuffData();
	}
}

void Character::PrintDebuffData() {
	for (auto& debuff : debuffs) {
		debuff->PrintDebuffData();
	}
}

void Character::AddSpell(Spell* spell) {
	unordered_map<string, Spell*>::iterator it;
	it = spellsMap.find(spell->GetSpellName());
	if (it == spellsMap.end()) {
		spellsVector.push_back(spell);
		spellsMap[spell->GetSpellName()] = spell;
	}
	else {
		return;
	}
}

void Character::RemoveSpell(string spellName) {
	unordered_map<string, Spell*>::iterator it;
	it = spellsMap.find(spellName);
	if (it == spellsMap.end()) {
		spellsMap.erase(it);
		for (unsigned int i = 0; i < spellsVector.size(); i++) {
			if (spellsVector[i]->GetSpellName() == spellName) {
				spellsVector.erase(spellsVector.begin() + i);
			}
		}
	}
	else {
		return;
	}
}