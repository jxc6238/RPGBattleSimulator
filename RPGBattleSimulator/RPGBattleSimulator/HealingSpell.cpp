#include "HealingSpell.h"

int HealingSpell::CalcualteHealing(Character* caster, Character* target) {
	return int(caster->GetMagicDamage() * spellStrength);
}

void HealingSpell::CastSingleTarget(Character* caster, Character* target) {
	int healing = CalcualteHealing(caster, target);
	target->SetHealth(healing);
}

void HealingSpell::CastMultiTarget(Character* caster, std::vector<Character*> targets) {
	for (auto target : targets) {
		int healing = CalcualteHealing(caster, target);
		target->SetHealth(healing);
	}
}