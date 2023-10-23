#pragma once
#include "DebuffTypeEnum.h"
#include <string>

class DebuffData
{
private:
	DebuffType debuff;
	int numOfTurnsAffected;
	int numOfTurnsLeft;
	double afflictionModifier;
public:
	DebuffData(DebuffType debuff, int NumOfTurnsAffected, 
		double AfflictionModifier): debuff(debuff), 
		numOfTurnsAffected(NumOfTurnsAffected),
		numOfTurnsLeft(NumOfTurnsAffected), 
		afflictionModifier(AfflictionModifier) {};
	int GetNumOfTurnsLeft();
	double GetAfflictionModifier();
	DebuffType GetDebuffType();
	std::string GetDebuffAsString();
	void PrintDebuffData();
	void DecreaseNumOfTurns();
	void DebuffAlreadyPresent();
};

