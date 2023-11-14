#pragma once
#include "ModifierSpell.h"

class DamageSpell: public ModifierSpell
{
public:
	DamageSpell(std::string name, bool multiTarget, double spellStrength) :
		ModifierSpell(name, multiTarget, spellStrength) {};

	int DamageCalculation(Character* caster, Character* target);
	void CastSingleTarget(Character* caster, Character* target) override;
	void CastMultiTarget(Character* caster, std::vector<Character*> targets) override;
};

