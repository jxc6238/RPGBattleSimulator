#include "Spell.h"

void Spell::PrintSpellData() {
	std::cout << "Spell: " << name << " Target: " << MultiTarget();
}

string Spell::MultiTarget() {
	if (multiTarget == true) {
		return "multi target";
	}
	else {
		return "single target";
	}
}

string Spell::GetSpellName() {
	return name;
}