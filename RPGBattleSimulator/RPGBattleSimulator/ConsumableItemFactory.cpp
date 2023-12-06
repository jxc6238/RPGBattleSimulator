#include "ConsumableItemFactory.h"

ConsumableItem* ConsumableItemFactory::BuildConsumableItem(string type, json itemDataJson) {
	auto it = items.find(itemDataJson["Name"]);
	if (it != items.end()) {
		return it->second;
	}
	else {
		if (type == "NonStatus") {
			return BuildNonStatusItem(itemDataJson);
		}
		else if (type == "Buff") {
			return BuildBuffItem(itemDataJson);
		}
		else if (type == "Debuff") {
			return BuildDebuffItem(itemDataJson);
		}
	}
	return NULL;
}

ConsumableItem* ConsumableItemFactory::BuildNonStatusItem(json itemDataJson) {
	items[itemDataJson["Name"]] = new NonBuffDebuffConsumableItem(itemDataJson["Name"],
		itemDataJson["HealthItem"], itemDataJson["Modifier"]);
	return items.find(itemDataJson["Name"])->second;
}

ConsumableItem* ConsumableItemFactory::BuildBuffItem(json itemDataJson) {
	BuffType buff = GetBuff(itemDataJson["Buff"]);
	items[itemDataJson["Name"]] = new BuffConsumableItem(itemDataJson["Name"], buff);
	return items.find(itemDataJson["Name"])->second;
}

ConsumableItem* ConsumableItemFactory::BuildDebuffItem(json itemDataJson) {
	DebuffType debuff = GetDebuff(itemDataJson["Debuff"]);
	items[itemDataJson["Name"]] = new DebuffConsumableItem(itemDataJson["Name"], debuff);
	return items.find(itemDataJson["Name"])->second;
}

BuffType ConsumableItemFactory::GetBuff(string Buff) {
	if (Buff == "PHYSDAMAGE") {
		return BuffType::PHYSDAMAGE;
	}
	else if (Buff == "MAGICDAMAGE") {
		return BuffType::MAGICDAMAGE;
	}
	else if (Buff == "SPEED") {
		return BuffType::SPEED;
	}
	else if (Buff == "PHYSDEFENSE") {
		return BuffType::PHYSDEFENSE;
	}
	else if (Buff == "MAGICRESIST") {
		return BuffType::MAGICRESIST;
	}
}

DebuffType ConsumableItemFactory::GetDebuff(string debuff) {
	if (debuff == "WEAK") {
		return DebuffType::WEAK;
	}
	else if (debuff == "WEAKWILL") {
		return DebuffType::WEAKWILL;
	}
	else if (debuff == "SLOW") {
		return DebuffType::SLOW;
	}
	else if (debuff == "FRAGILE") {
		return DebuffType::FRAGILE;
	}
	else if (debuff == "MAGICFRAGILE") {
		return DebuffType::MAGICFRAGILE;
	}
}