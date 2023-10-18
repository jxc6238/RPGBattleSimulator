#pragma once
#include "Character.h"
#include <fstream>
#include <sstream>
#include <string>
#include <nlohmann/json.hpp>
#include <fstream>
#include <unordered_map>

class InitBattle
{
private:
	const static int partySize = 3;
	const static int enemyPartySize = 4;
	Character* playerParty[partySize];
	Character* enemyParty[enemyPartySize];
	vector<Character*> availablePartyMembers;
	vector<EquippedItem*> availableEquippedItems;
public:
	void InitializeGame();
	void InitPlayerCharacters();
	void InitEquippedItems();
	void BuildItemSlotMap(unordered_map<string, ItemSlot>& itemSlotMap);
	void BuildBuffTypeMap(unordered_map<string, BuffType>& buffTypeMap);
	void AddCharacterToParty();
	void RemoveCharacterFromParty();
	void PrintAvailablePartyMembers();
	void PrintCharacterParty();
	void EquipItem();
	void UnequipItem();
	void PrintAvailableItems();
	int SelectInPartyCharacter();
};

