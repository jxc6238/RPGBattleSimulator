#include "DebuffData.h"
#include <iostream>

int DebuffData::GetNumOfTurnsLeft() {
	return numOfTurnsLeft;
}
double DebuffData::GetAfflictionModifier() {
	return afflictionModifier;
}
DebuffType DebuffData::GetDebuffType() {
	return debuff;
}
std::string DebuffData::GetDebuffAsString() {
	switch (debuff) {
	case DebuffType::WEAK:
		return "WEAK";
	case DebuffType::WEAKWILL:
		return "WEAKWILL";
	case DebuffType::SLOW:
		return "SLOW";
	case DebuffType::FRAGILE:
		return "FRAGILE";
	case DebuffType::MAGICFRAGILE:
		return "WEAKWILL";
	default:
		return "";
	}
}
void DebuffData::DecreaseNumOfTurns() {
	numOfTurnsLeft--;
	if (numOfTurnsLeft == 0) {
		delete this;
	}
}
void DebuffData::DebuffAlreadyPresent() {
	numOfTurnsLeft = numOfTurnsAffected;
}
void DebuffData::PrintDebuffData() {
	std::cout << GetDebuffAsString() << " "
		<< "Number of turns left: " << numOfTurnsLeft << "  ";
}