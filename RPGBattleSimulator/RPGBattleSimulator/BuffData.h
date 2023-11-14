#pragma once
#include "BuffTypeEnum.h"
#include <string>

class BuffData
{
private:
	BuffType buff;
	int numOfTurnsAffected;
	int numOfTurnsLeft;
	double buffModifier;
public:
	BuffData(BuffType buff, int numOfTurnsAffected, double buffModifier) :
		buff(buff), numOfTurnsAffected(numOfTurnsAffected),
		numOfTurnsLeft(numOfTurnsAffected), buffModifier(buffModifier) {};
	int GetNumOfTurnsLeft();
	double GetBuffModifier();
	BuffType GetBuffType();
	std::string GetBuffAsString();
	void PrintBuffData();
	void DecreaseNumOfTurns();
	void BuffAlreadyPresent();

};

