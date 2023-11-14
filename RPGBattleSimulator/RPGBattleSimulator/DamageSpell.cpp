#include "DamageSpell.h"

int DamageSpell::DamageCalculation(Character* caster, Character* target) {
	double damage = (caster->GetMagicDamage() * spellStrength) -
		target->GetMagicResist();
	damage = ceil(damage);
	if (damage <= 0) {
		return 0;
	}
	else {
		return int(damage);
	}
}

void DamageSpell::CastSingleTarget(Character* caster, Character* target) {
	int damage = DamageCalculation(caster, target);
	target->SetHealth(target->GetHealth() - damage);
}

void DamageSpell::CastMultiTarget(Character* caster, std::vector<Character*> targets) {
	for (auto target : targets) {
		int damage = DamageCalculation(caster, target);
		target->SetHealth(target->GetHealth() - damage);
	}
}