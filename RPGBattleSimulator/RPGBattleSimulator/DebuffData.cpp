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
	numOfTurnsLeft--;
	if (numOfTurnsLeft == 0) {
		delete this;
	}
}
void DebuffData::DebuffAlreadyPresent() {
	numOfTurnsLeft = numOfTurnsAffected;
}
void DebuffData::PrintDebuffData() {
	std::cout << "Debuff: " << GetDebuffAsString() << " "
		<< "Number of turns left: " << numOfTurnsLeft << std::endl;
}