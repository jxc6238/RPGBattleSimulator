#pragma once
#include "CurrentlyEquippedItems.h"
#include "DebuffData.h"
#include <string>
#include <iostream>
using namespace std;

class Character
{
private:
	string name;
	int health, mana;
	double baseSpeed, currentSpeed, speedMult;
	double basePhysDamage, currentPhysDamage, physDamageMult;
	double baseMagicDamage, currentMagicDamage, magicDamageMult;
	double basePhysDefense, currentPhysDefense, physDefenseMult;
	double baseMagicResist, currentMagicResist, magicResistMult;
	pair<BuffType, double> prevSpeed, prevPhysDamage, prevMagicDamage, 
		prevPhysDefense, prevMagicResist;
	CurrentlyEquippedItems equippedItems;
	vector<DebuffData*> debuffs;
public:
	Character(string name, int health, int mana, double baseSpeed,
		double basePhysDamage, double baseMagicDamage,
		double basePhysDefense, double baseMagicResist) : name(name), health(health),
		mana(mana), baseSpeed(baseSpeed), currentSpeed(baseSpeed), speedMult(1),
		basePhysDamage(basePhysDamage), currentPhysDamage(basePhysDamage),
		physDamageMult(1), baseMagicDamage(baseMagicDamage),
		currentMagicDamage(baseMagicDamage), magicDamageMult(1),
		basePhysDefense(basePhysDefense), currentPhysDefense(basePhysDefense),
		physDefenseMult(1), baseMagicResist(baseMagicResist), 
		currentMagicResist(baseMagicResist), magicResistMult(1),
		prevSpeed(BuffType::SPEED, baseSpeed), 
		prevPhysDamage(BuffType::PHYSDAMAGE, basePhysDamage),
		prevMagicDamage(BuffType::MAGICDAMAGE, baseMagicDamage),
		prevPhysDefense(BuffType::PHYSDEFENSE, basePhysDefense),
		prevMagicResist(BuffType::MAGICRESIST, baseMagicResist),
		equippedItems(), debuffs() {};

	void SetHealth(int healthValue);
	void SetMana(int manaValue);
	void SetBaseSpeed(double baseSpeedValue);
	void SetBasePhysDamage(double basePhysDamageValue);
	void SetBaseMagicDamage(double baseMagicDamageValue);
	void SetBasePhysDefense(double basePhysDefenseValue);
	void SetBaseMagicResist(double magicResistValue);

	void SetSpeed(double updatedSpeed);
	void SetPhysDamage(double updatedPhysDamage);
	void SetMagicDamage(double updatedMagicDamage);
	void SetPhysDefense(double updatedPhysefense);
	void SetMagicResist(double updatedMagicResist);

	void SetSpeedMultiplier(double speedMultValue);
	void SetPhysDamageMultiplier(double physDamageMultValue);
	void SetMagicDamageMultiplier(double magicDamageMultValue);
	void SetPhysDefenseMultiplier(double physDefenseMultValue);
	void SetMagicResistMultiplier(double magicResMultValue);

	string GetName();
	int GetHealth();
	int GetMana();
	double GetSpeed();
	double GetPhysDamage();
	double GetMagicDamage();
	double GetPhysDefense();
	double GetMagicResist();

	void EquipItem(EquippedItem* item);
	void UnequipItem();
	void EquipScale(BuffType buff, double multiplier);
	double CalculateScale(double currentVal, double buffVal);
	void UnequipDescale(const vector<ItemBuffPair>& buffs);
	double CalculateDescale(double currentVal, double buffVal);
	void PrintCharacterStats();
	void PrintItemSlots();

	void ApplyDebuff(DebuffData* debuff);
	void UpdateDebuffs();
};

