#include "InitBattle.h"
using json = nlohmann::json;

void InitBattle::InitPlayerCharacters() {
	std::ifstream ifs("PartyMembers.json");
	json partyMemJson = json::parse(ifs);
	for (auto& partyMember : partyMemJson["PartyMembers"]) {
		PlayerCharacter* tmpCharacter = new PlayerCharacter(partyMember["Name"],
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
	spellHandler.InitSpells();
	InitConsumableItems();
	AddCharacterToParty();
	menuState = new MainMenuState();
	do {
		InitBattleMenuState* tmp = menuState;
		menuState = menuState->Enter(this);
		delete tmp;
	} while (menuState != NULL);
	std::cout << "Done!" << std::endl;
/**
	//AddCharacterToParty();
	playerParty[0]->ApplyDebuff(new DebuffData(DebuffType::WEAK, 3, 0.9));
	playerParty[0]->PrintCharacterStats();
	std::cout << std::endl;
	playerParty[0]->ApplyDebuff(new DebuffData(DebuffType::SLOW, 2, 0.9));
	playerParty[0]->ApplyBuff(new BuffData(BuffType::PHYSDAMAGE, 2, 1.1));
	playerParty[0]->PrintCharacterStats();
	std::cout << std::endl;
	playerParty[0]->UpdateDebuffs();
	playerParty[0]->UpdateBuffs();
	playerParty[0]->PrintCharacterStats();
	std::cout << std::endl;
	playerParty[0]->UpdateDebuffs();
	playerParty[0]->UpdateBuffs();
	std::cout << std::endl;
	playerParty[0]->PrintCharacterStats();
	//EquipItem();
	//UnequipItem();
**/
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

void InitBattle::InitConsumableItems() {
	std::ifstream ifs("ConsumableItems.json");
	json consumables = json::parse(ifs);
	ConsumableItem* consumable;
	for (auto& item : consumables["ConsumableItems"]) {
		consumable = consumableFactory.BuildConsumableItem(item["Type"], item);
		availableConsumables.push_back(consumable);
	}
}

void InitBattle::AddCharacterToParty() {
	unsigned int characterSelection = 0;
	unsigned int positionSelection = 0;
	PrintAvailablePartyMembers();
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
	PlayerCharacter* tmpChar;
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
	std::cout << std::setfill('-') << std::setw(30) << '-' <<
		"Available Party members" <<
		std::setfill('-') << std::setw(30) << '-' << std::endl;
	for (unsigned int i = 0; i < availablePartyMembers.size(); i++) {
		std::cout << i + 1 << ": ";
		availablePartyMembers[i]->PrintCharacterStats();
	}
}

void InitBattle::PrintCharacterParty() {
	std::cout << std::setfill('-') << std::setw(30) << '-' <<
		"Current Party" <<
		std::setfill('-') << std::setw(30) << '-' << std::endl;
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
	playerParty[characterSelection]->EquipItem(availableEquippedItems[itemSelection]);
	availableEquippedItems.erase(availableEquippedItems.begin() + itemSelection);
}

void InitBattle::PrintAvailableItems() {
	std::cout << std::setfill('-') << std::setw(30) << '-' <<
		"Available Items" <<
		std::setfill('-') << std::setw(30) << '-' << std::endl;
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

void InitBattle::BeginBattle() {

}