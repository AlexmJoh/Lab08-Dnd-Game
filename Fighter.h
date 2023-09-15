#pragma once

#include <iostream>
#include <memory>
#include "ICharacter.h"
#include "IRace.h"
#include "Item.h"
#include "Die.h"
using namespace std;

class Fighter : public ICharacter
{
	simpleWeapon greataxe = simpleWeapon("Greataxe", 1, 12, 3);
	simpleWeapon javelin = simpleWeapon("Javelin", 1, 6, 3);

public:

	Fighter(std::shared_ptr<IRace> race, string name);

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

	~Fighter();
};
