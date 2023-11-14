#pragma once
#include "DebuffData.h"
#include "DebuffTypeEnum.h"

class DebuffFactory
{
public:
	DebuffData* GetDebuffObject(DebuffType debuff);
};

