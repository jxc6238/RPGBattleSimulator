#pragma once
#include "Spell.h"
#include "DebuffTypeEnum.h"
#include "DebuffFactory.h"

class DebuffSpell: public Spell
{
private:
	DebuffType debuff;
public:
	DebuffSpell(std::string name, bool multiTarget, DebuffType debuff) :
		Spell(name, multiTarget), debuff(debuff) {};

	void CastSingleTarget(Character* caster, Character* target) override;
	void CastMultiTarget(Character* caster,
		std::vector<Character*> targets) override;
};

