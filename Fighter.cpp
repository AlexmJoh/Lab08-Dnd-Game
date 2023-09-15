#include "Fighter.h"
#include "Die.h"


Fighter::Fighter(std::shared_ptr<IRace> race, string name): ICharacter(race, name)
{
	c_hitPoints = 11;
    c_amourClass = 13;
    c_initiative = 0;
    c_speed = 25;
	c_primaryWeapon = greataxe;
	c_secondaryWeapon = javelin;
}

int Fighter::GetHitPoints() { return c_hitPoints + c_race->GetHitPointMods(); }
int Fighter::GetAmourClass() { return c_amourClass + c_race->GetArmourClassMods(); }
int Fighter::GetInitiative() { return c_initiative + c_race->GetInitiativeMods(); }

int Fighter::AttackRoll()
{
	Die AttackRoll;
	return AttackRoll.D20() + 5;
}

void Fighter::SetParty(string party) { c_party = party; }
string Fighter::GetParty() { return c_party; }

void Fighter::SetName(string name) { c_name = name; }
string Fighter::GetName() { return c_name; }

int Fighter::AttackDamage(int weaponSlot)
{
	if (weaponSlot == 0) { return c_primaryWeapon.getDamage(); }
	else if (weaponSlot == 1) { return c_secondaryWeapon.getDamage(); }
	else { return 0; }
}

int Fighter::AttackPlayer(int weaponSlot, std::shared_ptr<ICharacter> target)
{
	int damage;

	if (weaponSlot == 0) { damage = c_primaryWeapon.getDamage(); }
	else if (weaponSlot == 1) { damage = c_secondaryWeapon.getDamage(); }
	else { damage = 0; }

	target->TakeDamage(damage);
	return damage;
}

void Fighter::TakeDamage(int damage) { c_hitPoints = c_hitPoints - damage; }

Fighter::~Fighter(){}