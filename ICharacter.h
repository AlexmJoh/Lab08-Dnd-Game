#pragma once

#include <memory>
#include <vector>
#include "IRace.h"
#include "Item.h"

class ICharacter
{
public:

	ICharacter(std::shared_ptr<IRace> race, string name);
	
	virtual int GetHitPoints() = 0;
	virtual int GetAmourClass() = 0;
	virtual int GetInitiative() = 0;

	virtual void SetParty(string party) = 0;
	virtual string GetParty() = 0;
	virtual void SetName(string name) = 0;
	virtual string GetName() = 0;

	virtual int AttackDamage(int weaponSlot) = 0;
	virtual int AttackPlayer(int weaponSlot, std::shared_ptr<ICharacter> target) = 0;
	virtual void TakeDamage(int damage) = 0;
	virtual int AttackRoll() = 0;

	void PrintInventory(std::shared_ptr<IItem>);
	void AddItemToInventory(std::shared_ptr<IItem>);
	void RemoveItemFromInventory(std::shared_ptr<IItem>);
	
	virtual ~ICharacter();


	protected:
		int c_hitPoints, c_amourClass, c_initiative, c_speed;

		string c_party, c_name;

		simpleWeapon c_primaryWeapon, c_secondaryWeapon;

		std::shared_ptr<IRace> c_race;

		int c_strength, c_dexterity, c_constitution;
		int c_intelligencem, c_wisdom, c_charisma;

		vector<std::shared_ptr<IItem>> c_inventory;

		int c_level, c_XP;
};
