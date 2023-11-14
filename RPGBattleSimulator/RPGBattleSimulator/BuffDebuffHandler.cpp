#include "BuffDebuffHandler.h"

DebuffType BuffDebuffHandler::GetBuffOpposite(BuffType buff) {
	switch (buff) {
	case BuffType::PHYSDAMAGE:
		return DebuffType::WEAK;
	case BuffType::MAGICDAMAGE:
		return DebuffType::WEAKWILL;
	case BuffType::SPEED:
		return DebuffType::SLOW;
	case BuffType::PHYSDEFENSE:
		return DebuffType::FRAGILE;
	case BuffType::MAGICRESIST:
		return DebuffType::MAGICFRAGILE;
	}
}
BuffType BuffDebuffHandler::GetDebuffOpposite(DebuffType debuff) {
	switch (debuff) {
	case DebuffType::WEAK:
		return BuffType::PHYSDAMAGE;
	case DebuffType::WEAKWILL:
		return BuffType::MAGICDAMAGE;
	case DebuffType::SLOW:
		return BuffType::SPEED;
	case DebuffType::FRAGILE:
		return BuffType::PHYSDEFENSE;
	case DebuffType::MAGICFRAGILE:
		return BuffType::MAGICRESIST;
	}
}