#include "ICharacter.h"

//Default Constructor
ICharacter :: ICharacter(std::shared_ptr<IRace> race, string name) 
: c_hitPoints(0), c_amourClass(0), c_initiative(0), c_race(race), c_name(name)
{
    c_primaryWeapon = simpleWeapon("Sword",1,8, 2);
	c_secondaryWeapon = simpleWeapon("Dagger",1,6, 2);
    c_party = "None";
}

void ICharacter::PrintInventory(std::shared_ptr<IItem>)
{

}
void ICharacter::AddItemToInventory(std::shared_ptr<IItem>)
{

}
void ICharacter::RemoveItemFromInventory(std::shared_ptr<IItem>)
{

}

ICharacter::~ICharacter(){}