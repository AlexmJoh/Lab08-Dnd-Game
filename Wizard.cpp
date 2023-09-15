#include "Wizard.h"
#include "Die.h"

Wizard::Wizard(std::shared_ptr<IRace> race, string name): ICharacter(race, name)
{
	c_hitPoints = 9;
    c_amourClass = 11;
    c_initiative = 1;
    c_speed = 25;
	c_primaryWeapon = magicMissile;
	c_secondaryWeapon = shortSword;
}

int Wizard::GetHitPoints() { return c_hitPoints + c_race->GetHitPointMods(); }
int Wizard::GetAmourClass() { return c_amourClass + c_race->GetArmourClassMods(); }
int Wizard::GetInitiative() { return c_initiative + c_race->GetInitiativeMods(); }

int Wizard::AttackRoll()
{
	Die AttackRoll;
	return AttackRoll.D20() + 4;
}

void Wizard::SetParty(string party) { c_party = party; }
string Wizard::GetParty() { return c_party; }

void Wizard::SetName(string name) { c_name = name; }
string Wizard::GetName() { return c_name; }

int Wizard::AttackDamage(int weaponSlot)
{
	if (weaponSlot == 0) { return c_primaryWeapon.getDamage(); }
	else if (weaponSlot == 1) { return c_secondaryWeapon.getDamage(); }
	else { return 0; }
}

int Wizard::AttackPlayer(int weaponSlot, std::shared_ptr<ICharacter> target)
{
	int damage;

	if (weaponSlot == 0) { damage = c_primaryWeapon.getDamage(); }
	else if (weaponSlot == 1) { damage = c_secondaryWeapon.getDamage(); }
	else { damage = 0; }

	target->TakeDamage(damage);
	return damage;
}

void Wizard::TakeDamage(int damage) { c_hitPoints = c_hitPoints - damage; }

Wizard::~Wizard(){}