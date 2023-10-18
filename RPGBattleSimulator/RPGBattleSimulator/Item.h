#pragma once
#include <string>
#include "ItemSlotsEnum.h"
#include "BuffTypeEnum.h"

using namespace std;

class Item
{
private:
	string name;
	
public:
	Item(string name) : name(name) {};

	string GetName();
	string GetBuffAsString(BuffType buff);
	string GetSlotAsString(ItemSlot slot);
	virtual void PrintItemInfo() = 0;
};

