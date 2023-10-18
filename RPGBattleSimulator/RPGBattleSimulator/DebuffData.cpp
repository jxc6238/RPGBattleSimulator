#include "DebuffData.h"

int DebuffData::GetNumOfTurnsLeft() {
	return NumOfTurnsLeft;
}
double DebuffData::GetAfflictionModifier() {
	return AfflictionModifier;
}
DebuffType DebuffData::GetDebuffType() {
	return debuff;
}
std::string DebuffData::GetDebuffAsString() {
	switch (debuff) {
	case DebuffType::WEAK:
		return "WEAK";
		break;
	case DebuffType::WEAKWILL:
		return "WEAKWILL";
		break;
	case DebuffType::SLOW:
		return "SLOW";
		break;
	case DebuffType::FRAGILE:
		return "FRAGILE";
		break;
	case DebuffType::MAGICFRAGILE:
		return "WEAKWILL";
		break;
	}
}
void DebuffData::DecreaseNumOfTurns() {
	NumOfTurnsLeft--;
	if (NumOfTurnsLeft == 0) {
		delete this;
	}
}
void DebuffData::DebuffAlreadyPresent() {
	NumOfTurnsLeft = NumOfTurnsAffected;
}