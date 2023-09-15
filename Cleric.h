#pragma once

#include <iostream>
#include <memory>
#include "ICharacter.h"
#include "IRace.h"
#include "Item.h"
#include "Die.h"
using namespace std;

class Cleric : public ICharacter
{
	simpleWeapon warhammer = simpleWeapon("Warhammer", 1, 8, 2);
	simpleWeapon handaxe = simpleWeapon("Handaxe", 1, 6, 2);

public:

	Cleric(std::shared_ptr<IRace> race, string name);

	virtual int GetHitPoints() override;
	virtual int GetAmourClass() override;
	virtual int GetInitiative() override;
	virtual int AttackRoll() override;
	virtual void SetParty(string party) override;
	virtual string GetParty() override;
	virtual void SetName(string name) override;
	virtual string GetName() override;
	virtual int AttackDamage(int weaponSlot) override;
	int AttackPlayer(int weaponSlot, std::shared_ptr<ICharacter> target) override;
	virtual void TakeDamage(int damage) override;

	~Cleric();
};
