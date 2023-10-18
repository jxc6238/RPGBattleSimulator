#include "InitBattle.h"
using json = nlohmann::json;

void InitBattle::InitPlayerCharacters() {
	std::ifstream ifs("PartyMembers.json");
	json partyMemJson = json::parse(ifs);
	for (auto& partyMember : partyMemJson["PartyMembers"]) {
		Character* tmpCharacter = new Character(partyMember["Name"],
			partyMember["Health"],
			partyMember["Mana"],
			partyMember["BaseSpeed"],
			partyMember["BasePhysDamage"],
			partyMember["BaseMagicDamage"],
			partyMember["BasePhysDefense"],
			partyMember["BaseMagicResist"]);
		availablePartyMembers.push_back(tmpCharacter);
	}
}

void InitBattle::InitializeGame() {
	InitPlayerCharacters();
	InitEquippedItems();
	AddCharacterToParty();
	EquipItem();
	UnequipItem();
}

void InitBattle::InitEquippedItems() {
	std::unordered_map<string, ItemSlot> itemSlotMap;
	BuildItemSlotMap(itemSlotMap);
	std::unordered_map<string, BuffType> buffTypeMap;
	BuildBuffTypeMap(buffTypeMap);
	std::ifstream ifs("EquippedItems.json");
	json equippedItemsJson = json::parse(ifs);
	vector<ItemBuffPair> itemBuffsVec;
	for (auto& equippedItem : equippedItemsJson["EquippedItems"]) {
		for (auto& itemBuffs : equippedItem["Buffs"]) {
			ItemBuffPair buffPair(buffTypeMap.at(itemBuffs["BuffType"]),
				itemBuffs["BuffStat"]);
			itemBuffsVec.push_back(buffPair);
		}
		EquippedItem* item = new EquippedItem(equippedItem["Name"],
			itemSlotMap.at(equippedItem["Slot"]), itemBuffsVec);
		availableEquippedItems.push_back(item);
		itemBuffsVec.clear();
	}
}

void InitBattle::BuildItemSlotMap(unordered_map<string, ItemSlot>& itemSlotMap) {
	itemSlotMap["HEAD"] = ItemSlot::HEAD;
	itemSlotMap["CHEST"] = ItemSlot::CHEST;
	itemSlotMap["HANDS"] = ItemSlot::HANDS;
	itemSlotMap["FEET"] = ItemSlot::FEET;
	itemSlotMap["TRINKET"] = ItemSlot::TRINKET;
}

void InitBattle::BuildBuffTypeMap(unordered_map<string, BuffType>& buffTypeMap) {
	buffTypeMap["PHYSDAMAGE"] = BuffType::PHYSDAMAGE;
	buffTypeMap["MAGICDAMAGE"] = BuffType::MAGICDAMAGE;
	buffTypeMap["SPEED"] = BuffType::SPEED;
	buffTypeMap["PHYSDEFENSE"] = BuffType::PHYSDEFENSE;
	buffTypeMap["MAGICRESIST"] = BuffType::MAGICRESIST;
}

void InitBattle::AddCharacterToParty() {
	unsigned int characterSelection = 0;
	unsigned int positionSelection = 0;
	for (unsigned int i = 0; i < availablePartyMembers.size(); i++) {
		std::cout << i + 1 << ": ";
		availablePartyMembers[i]->PrintCharacterStats();		
	}
	do {
		std::cout << "Select party member: ";
		std::cin >> characterSelection;
	} while (characterSelection < 1 || characterSelection > availablePartyMembers.size());
	characterSelection--;
	do {
		std::cout << "Select character position: ";
		std::cin >> positionSelection;
	} while (positionSelection < 1 || positionSelection > 3);
	std::cout << endl;
	positionSelection--;
	Character* tmpChar;
	tmpChar = availablePartyMembers[characterSelection];
	availablePartyMembers.erase(availablePartyMembers.begin() + characterSelection);
	playerParty[positionSelection] = tmpChar;
	PrintAvailablePartyMembers();
	PrintCharacterParty();
}

void InitBattle::RemoveCharacterFromParty() {
	int characterSelection = SelectInPartyCharacter();
	availablePartyMembers.push_back(playerParty[characterSelection]);
	playerParty[characterSelection] = NULL;
	PrintAvailablePartyMembers();
	PrintCharacterParty();
}

void InitBattle::PrintAvailablePartyMembers() {
	std::cout << "Available Party Members: " << std::endl;
	for (unsigned int i = 0; i < availablePartyMembers.size(); i++) {
		std::cout << i + 1 << ": ";
		availablePartyMembers[i]->PrintCharacterStats();
	}
	std::cout << endl;
}

void InitBattle::PrintCharacterParty() {
	std::cout << "Player Party: " << std::endl;
	for (unsigned int i = 0; i < partySize; i++) {
		std::cout << i + 1 << ": ";
		if (playerParty[i] != NULL) {
			playerParty[i]->PrintCharacterStats();
		}
		else {
			std::cout << "Empty" << std::endl;
		}
	}
	std::cout << endl;
}

void InitBattle::EquipItem() {
	int characterSelection = SelectInPartyCharacter();
	unsigned int itemSelection = 0;
	PrintAvailableItems();
	do {
		std::cout << "Select item: ";
		std::cin >> itemSelection;
		std::cout << std::endl;
	} while (itemSelection < 1 || itemSelection > availableEquippedItems.size());
	itemSelection--;
	std::cout << std::endl << std::endl;
	playerParty[characterSelection]->EquipItem(availableEquippedItems[itemSelection]);
	availableEquippedItems.erase(availableEquippedItems.begin() + itemSelection);
	PrintAvailableItems();
}

void InitBattle::PrintAvailableItems() {
	for (unsigned int i = 0; i < availableEquippedItems.size(); i++) {
		std::cout << i + 1 << ": ";
		availableEquippedItems[i]->PrintItemInfo();
	}
}

void InitBattle::UnequipItem() {
	int characterSelection = SelectInPartyCharacter();
	playerParty[characterSelection]->UnequipItem();
}

int InitBattle::SelectInPartyCharacter() {
	int characterSelection = 0;
	PrintCharacterParty();
	do {
		std::cout << "Select character: ";
		std::cin >> characterSelection;
		std::cout << std::endl;
	} while (characterSelection < 1 || characterSelection > partySize);
	characterSelection--;
	return characterSelection;
}