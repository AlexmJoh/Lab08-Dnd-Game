#include "Cleric.h"
#include "Die.h"


Cleric::Cleric(std::shared_ptr<IRace> race, string name): ICharacter(race, name)
{
	c_hitPoints = 10;
    c_amourClass = 13;
    c_initiative = 0;
    c_speed = 25;
	c_primaryWeapon = warhammer;
	c_secondaryWeapon = handaxe;
}

int Cleric::GetHitPoints() { return c_hitPoints + c_race->GetHitPointMods(); }
int Cleric::GetAmourClass() { return c_amourClass + c_race->GetArmourClassMods(); }
int Cleric::GetInitiative() { return c_initiative + c_race->GetInitiativeMods(); }

int Cleric::AttackRoll()
{
	Die AttackRoll;
	return AttackRoll.D20() + 4;
}

void Cleric::SetParty(string party) { c_party = party; }
string Cleric::GetParty() { return c_party; }

void Cleric::SetName(string name) { c_name = name; }
string Cleric::GetName() { return c_name; }

int Cleric::AttackDamage(int weaponSlot)
{
	if (weaponSlot == 0) { return c_primaryWeapon.getDamage(); }
	else if (weaponSlot == 1) { return c_secondaryWeapon.getDamage(); }
	else { return 0; }
}

int Cleric::AttackPlayer(int weaponSlot, std::shared_ptr<ICharacter> target)
{
	int damage;

	if (weaponSlot == 0) { damage = c_primaryWeapon.getDamage(); }
	else if (weaponSlot == 1) { damage = c_secondaryWeapon.getDamage(); }
	else { damage = 0; }

	target->TakeDamage(damage);
	return damage;
}

void Cleric::TakeDamage(int damage) { c_hitPoints = c_hitPoints - damage; }

Cleric::~Cleric(){}