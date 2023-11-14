#pragma once
#include "Spell.h"
#include "BuffTypeEnum.h"
#include "BuffFactory.h"

class BuffSpell: public Spell
{
private:
	BuffType buff;
public:
	BuffSpell(std::string name, bool multiTarget, BuffType buff) :
		Spell(name, multiTarget), buff(buff) {};

	void CastSingleTarget(Character* caster, Character* target) override;
	void CastMultiTarget(Character* caster,
		std::vector<Character*> targets) override;
};

