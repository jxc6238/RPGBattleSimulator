#pragma once
#include "ConsumableItem.h"
#include "NonBuffDebuffConsumableItem.h"
#include "DebuffConsumableItem.h"
#include "BuffConsumableItem.h"
#include "BuffTypeEnum.h"
#include "DebuffTypeEnum.h"
#include <unordered_map>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

class ConsumableItemFactory
{
private:
	unordered_map<string, ConsumableItem*> items;
public:
	ConsumableItem* BuildConsumableItem(string type, json itemDataJson);
	ConsumableItem* BuildNonStatusItem(json itemDataJson);
	ConsumableItem* BuildBuffItem(json itemDataJson);
	ConsumableItem* BuildDebuffItem(json itemDataJson);
	BuffType GetBuff(string buff);
	DebuffType GetDebuff(string debuff);
};

