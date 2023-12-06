#pragma once
#include "DamageSpell.h"
#include "Spell.h"
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <string>
#include <nlohmann/json.hpp>
#include <fstream>

class SpellHandler
{
private:
	unordered_map<string, Spell*> allSpells;
public:
	Spell* SpellFlyweightDistributor(std::string spellName);
	void InitSpells();
	void InitDamageSpells();
	void InitHealingSpells();
};

