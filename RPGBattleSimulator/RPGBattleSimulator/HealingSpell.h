#pragma once
#include "ModifierSpell.h"

class HealingSpell: public ModifierSpell
{
public:
	HealingSpell(std::string name, bool multiTarget, double spellStrength) :
		ModifierSpell(name, multiTarget, spellStrength) {};

	int CalcualteHealing(Character* caster, Character* target);
	void CastSingleTarget(Character* caster, Character* target) override;
	void CastMultiTarget(Character* caster, std::vector<Character*> targets) override;
};

