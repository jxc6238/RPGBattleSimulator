#pragma once
#include "BuffTypeEnum.h"

struct ItemBuffPair {
	BuffType buff;
	double buffStat;
	ItemBuffPair(BuffType buff, double buffStat) : buff(buff), buffStat(buffStat) {};
};
