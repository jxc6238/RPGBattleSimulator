#include "SpellHandler.h"
using json = nlohmann::json;

void SpellHandler::InitSpells() {
	InitDamageSpells();
	InitHealingSpells();
}

void SpellHandler::InitDamageSpells() {
	std::ifstream ifs("DamageSpells.json");
	json damageSpellsJson = json::parse(ifs);
	for (auto& spell : damageSpellsJson["DamageSpells"]) {
		DamageSpell* tmpSpell = new DamageSpell(
			spell["Name"],
			spell["MultiTarget"],
			spell["SpellStrength"]
		);
		allSpells[spell["Name"]] = tmpSpell;
	}
}

void SpellHandler::InitHealingSpells() {
	std::ifstream ifs("HealingSpells.json");
	json damageSpellsJson = json::parse(ifs);
	for (auto& spell : damageSpellsJson["HealingSpells"]) {
		DamageSpell* tmpSpell = new DamageSpell(
			spell["Name"],
			spell["MultiTarget"],
			spell["SpellStrength"]
		);
		allSpells[spell["Name"]] = tmpSpell;
	}
}

Spell* SpellHandler::SpellFlyweightDistributor(std::string spellName) {
	auto it = allSpells.find(spellName);
	if (it == allSpells.end()) {
		return NULL;
	}
	else {
		return (*it).second;
	}
}