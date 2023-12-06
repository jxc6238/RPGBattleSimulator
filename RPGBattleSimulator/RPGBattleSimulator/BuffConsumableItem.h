#pragma once
#include "ConsumableItem.h"
#include "BuffFactory.h"

class BuffConsumableItem: public ConsumableItem
{
private:
	BuffType buff;
	static BuffFactory* buffFactory;
public:
	BuffConsumableItem(string name, BuffType buff) : ConsumableItem(name),
		buff(buff) {};
	void UseConsumable(Character* target) override;
	void PrintItemInfo() override;
};

