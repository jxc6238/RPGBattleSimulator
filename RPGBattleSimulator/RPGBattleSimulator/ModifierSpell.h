#pragma once
#include "Spell.h"

class ModifierSpell: public Spell
{
protected:
	double spellStrength;
public:
	ModifierSpell(std::string name, bool multiTarget, double spellStrength) :
		Spell(name, multiTarget), spellStrength(spellStrength) {};
};

