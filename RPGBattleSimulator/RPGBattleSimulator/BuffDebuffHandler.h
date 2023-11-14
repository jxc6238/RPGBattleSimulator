#pragma once
#include "BuffTypeEnum.h"
#include "DebuffTypeEnum.h"

class BuffDebuffHandler
{
public:
	BuffType GetDebuffOpposite(DebuffType debuff);
	DebuffType GetBuffOpposite(BuffType buff);
};

