#include "DebuffSpell.h"

void DebuffSpell::CastSingleTarget(Character* caster, Character* target) {
	DebuffFactory* debuffFactory = new DebuffFactory();
	DebuffData* debuff = debuffFactory->GetDebuffObject(this->debuff);
	target->ApplyDebuff(debuff);
	delete debuffFactory;
}

void DebuffSpell::CastMultiTarget(Character* caster, std::vector<Character*> targets) {
	DebuffFactory* debuffFactory = new DebuffFactory();
	for (auto target : targets) {
		DebuffData* debuff = debuffFactory->GetDebuffObject(this->debuff);
		target->ApplyDebuff(debuff);
	}
	delete debuffFactory;
}