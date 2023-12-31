#pragma once
#include "CurrentlyEquippedItems.h"
#include "DebuffData.h"
#include "BuffData.h"
#include "BuffDebuffHandler.h"
#include "Spell.h"
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

class Spell;

class Character
{
protected:
	string name;
	int health, mana, maxHealth, maxMana;
	double baseSpeed, currentSpeed, speedMult;
	double basePhysDamage, currentPhysDamage, physDamageMult;
	double baseMagicDamage, currentMagicDamage, magicDamageMult;
	double basePhysDefense, currentPhysDefense, physDefenseMult;
	double baseMagicResist, currentMagicResist, magicResistMult;
	pair<BuffType, double> prevSpeed, prevPhysDamage, prevMagicDamage, 
		prevPhysDefense, prevMagicResist;
	vector<DebuffData*> debuffs;
	vector<BuffData*> buffs;
	vector<Spell*> spellsVector;
	unordered_map<string, Spell*> spellsMap;
	static BuffDebuffHandler buffDebuffHandler;

public:
	Character(string name, int health, int mana, double baseSpeed,
		double basePhysDamage, double baseMagicDamage,
		double basePhysDefense, double baseMagicResist) : name(name), health(health),
		mana(mana), maxHealth(health), maxMana(mana),
		baseSpeed(baseSpeed), currentSpeed(baseSpeed), speedMult(1),
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
		debuffs(), spellsVector() {};

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

	void PrintCharacterStats();
	double CalculateScale(double currentVal, double buffVal);
	double CalculateDescale(double currentVal, double buffVal);

	void ApplyDebuff(DebuffData* debuff);
	void CalculateDebuff(DebuffType debuffType, double debuffMultiplier);
	void UpdateDebuffs();
	void RemoveDebuff(DebuffData* debuff);

	void ApplyBuff(BuffData* buff);
	void CalculateBuff(BuffType buff, double buffMultiplier);
	void UpdateBuffs();
	void RemoveBuff(BuffData* buff);

	bool BuffPresentCheck(BuffType buff);
	bool DebuffPresentCheck(DebuffType debuff);
	int GetDebuffPosition(DebuffType debuff);
	int GetBuffPosition(BuffType buff);

	void PrintBuffData();
	void PrintDebuffData();

	void AddSpell(Spell* spell);
	void RemoveSpell(string spell);
};

