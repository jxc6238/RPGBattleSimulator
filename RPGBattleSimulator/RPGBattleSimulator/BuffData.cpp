#include "BuffData.h"
#include <iostream>

int BuffData::GetNumOfTurnsLeft() {
	return numOfTurnsLeft;
}
double BuffData::GetBuffModifier() {
	return buffModifier;
}
BuffType BuffData::GetBuffType() {
	return buff;
}
std::string BuffData::GetBuffAsString() {
	switch (buff) {
	case BuffType::PHYSDAMAGE:
		return "PHYSDAMAGE";
	case BuffType::MAGICDAMAGE:
		return "MAGICDAMAGE";
	case BuffType::SPEED:
		return "SPEED";
	case BuffType::PHYSDEFENSE:
		return "PHYSDEFENSE";
	case BuffType::MAGICRESIST:
		return "MAGICRESIST";
	default:
		return "";
	}
}
void BuffData::DecreaseNumOfTurns() {
	numOfTurnsLeft--;
	if (numOfTurnsLeft == 0) {
		delete this;
	}
}
void BuffData::BuffAlreadyPresent() {
	numOfTurnsLeft = numOfTurnsAffected;
}
void BuffData::PrintBuffData() {
	std::cout <<GetBuffAsString() << " "
		<< "Number of turns left: " << numOfTurnsLeft << "  ";
}