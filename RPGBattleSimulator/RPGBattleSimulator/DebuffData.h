#pragma once
#include "DebuffTypeEnum.h"
#include <string>

class DebuffData
{
private:
	int NumOfTurnsAffected;
	int NumOfTurnsLeft;
	double AfflictionModifier;
	DebuffType debuff;
public:
	DebuffData(int NumOfTurnsAffected, double AfflictionModifier,
		DebuffType debuff): NumOfTurnsAffected(NumOfTurnsAffected),
		NumOfTurnsLeft(NumOfTurnsAffected), AfflictionModifier(AfflictionModifier),
		debuff(debuff) {};
	int GetNumOfTurnsLeft();
	double GetAfflictionModifier();
	DebuffType GetDebuffType();
	std::string GetDebuffAsString();
	void DecreaseNumOfTurns();
	void DebuffAlreadyPresent();
};

