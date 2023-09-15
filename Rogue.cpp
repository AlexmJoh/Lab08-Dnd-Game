#include "Rogue.h"
#include "Die.h"

Rogue::Rogue(std::shared_ptr<IRace> race, string name): ICharacter(race, name)
{
	c_hitPoints = 10;
    c_amourClass = 12;
    c_initiative = 1;
    c_speed = 25;
	c_primaryWeapon = shortSword;
	c_secondaryWeapon = shortBow;
}

int Rogue::GetHitPoints() { return c_hitPoints + c_race->GetHitPointMods(); }
int Rogue::GetAmourClass() { return c_amourClass + c_race->GetArmourClassMods(); }
int Rogue::GetInitiative() { return c_initiative + c_race->GetInitiativeMods(); }

int Rogue::AttackRoll()
{
	Die AttackRoll;
	return AttackRoll.D20() + 5;
}

void Rogue::SetParty(string party) { c_party = party; }
string Rogue::GetParty() { return c_party; }

void Rogue::SetName(string name) { c_name = name; }
string Rogue::GetName() { return c_name; }

int Rogue::AttackDamage(int weaponSlot)
{
	if (weaponSlot == 0) { return c_primaryWeapon.getDamage(); }
	else if (weaponSlot == 1) { return c_secondaryWeapon.getDamage(); }
	else { return 0; }
}

int Rogue::AttackPlayer(int weaponSlot, std::shared_ptr<ICharacter> target)
{
	int damage;

	if (weaponSlot == 0) { damage = c_primaryWeapon.getDamage(); }
	else if (weaponSlot == 1) { damage = c_secondaryWeapon.getDamage(); }
	else { damage = 0; }

	target->TakeDamage(damage);
	return damage;
}

void Rogue::TakeDamage(int damage) { c_hitPoints = c_hitPoints - damage; }

Rogue::~Rogue(){}




