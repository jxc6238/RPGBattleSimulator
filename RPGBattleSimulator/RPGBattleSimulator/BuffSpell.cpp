#include "BuffSpell.h"

void BuffSpell::CastSingleTarget(Character* caster, Character* target) {
	BuffFactory* buffFactory = new BuffFactory();
	BuffData* buff = buffFactory->GetBuffObject(this->buff);
	target->ApplyBuff(buff);
	delete buffFactory;
}

void BuffSpell::CastMultiTarget(Character* caster, std::vector<Character*> targets) {
	BuffFactory* buffFactory = new BuffFactory();
	for (auto& target : targets) {
		BuffData* buff = buffFactory->GetBuffObject(this->buff);
		target->ApplyBuff(buff);
	}
	delete buffFactory;
}