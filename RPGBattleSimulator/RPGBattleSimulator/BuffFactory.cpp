#include "BuffFactory.h"

BuffData* BuffFactory::GetBuffObject(BuffType buff) {
	switch (buff) {
	case BuffType::PHYSDAMAGE:
		return new BuffData(BuffType::PHYSDAMAGE, 2, 1.2);
	case BuffType::MAGICDAMAGE:
		return new BuffData(BuffType::MAGICDAMAGE, 2, 1.2);
	case BuffType::SPEED:
		return new BuffData(BuffType::SPEED, 2, 1.3);
	case BuffType::PHYSDEFENSE:
		return new BuffData(BuffType::PHYSDEFENSE, 2, 1.4);
	case BuffType::MAGICRESIST:
		return new BuffData(BuffType::MAGICRESIST, 2, 1.3);
	default:
		return NULL;
	}
}