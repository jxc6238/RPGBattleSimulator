#pragma once

#include "Item.h"
#include "Character.h"

class ConsumableItem : public Item
{
public:
	ConsumableItem(string name) : 
		Item(name) {};
	virtual void UseConsumable(Character* target) = 0;
};

