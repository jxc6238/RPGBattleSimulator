#pragma once
#include "Character.h"
#include "PlayerCharacter.h"
#include "InitBattleMenuState.h"
#include "MainMenuState.h"
#include "DamageSpell.h"
#include "SpellHandler.h"
#include "Spell.h"
#include "ConsumableItem.h"
#include "ConsumableItemFactory.h"
#include <fstream>
#include <sstream>
#include <string>
#include <nlohmann/json.hpp>
#include <fstream>
#include <unordered_map>

class InitBattleMenuState;

class InitBattle
{
private:
	const static int partySize = 3;
	const static int enemyPartySize = 4;
	PlayerCharacter* playerParty[partySize];
	Character* enemyParty[enemyPartySize];
	vector<PlayerCharacter*> availablePartyMembers;
	vector<EquippedItem*> availableEquippedItems;
	vector<ConsumableItem*> availableConsumables;
	ConsumableItemFactory consumableFactory;
	InitBattleMenuState* menuState;
	SpellHandler spellHandler;
public:
	void InitializeGame();
	void InitPlayerCharacters();
	void InitEquippedItems();
	void InitConsumableItems();

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
	void BeginBattle();
};

