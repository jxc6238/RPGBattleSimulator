#pragma once
#include "Character.h"

class Character;

class Spell
{
protected:
	std::string name;
	bool multiTarget; //True = multitarget, false = single target
public:
	Spell(std::string name, bool multiTarget) : name(name), 
		multiTarget(multiTarget) {};
	
	virtual void PrintSpellData();
	string MultiTarget();
	virtual void CastSingleTarget(Character* caster, Character* target) = 0;
	virtual void CastMultiTarget(Character* caster, 
		std::vector<Character*> targets) = 0;
};

