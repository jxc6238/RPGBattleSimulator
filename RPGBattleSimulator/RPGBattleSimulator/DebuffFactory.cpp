#include "DebuffFactory.h"

DebuffData* DebuffFactory::GetDebuffObject(DebuffType debuff) {
	switch (debuff) {
	case DebuffType::WEAK:
		return new DebuffData(DebuffType::WEAK, 2, 0.5);
	case DebuffType::WEAKWILL:
		return new DebuffData(DebuffType::WEAKWILL, 3, 0.7);
	case DebuffType::SLOW:
		return new DebuffData(DebuffType::SLOW, 4, 0.8);
	case DebuffType::FRAGILE:
		return new DebuffData(DebuffType::FRAGILE, 5, 0.7);
	case DebuffType::MAGICFRAGILE:
		return new DebuffData(DebuffType::MAGICFRAGILE, 5, 0.6);
	default:
		return NULL;
	}
}