// tests.cpp
#include "Item.h"
#include "Die.h"
#include "IRace.h"
#include "Party.h"
#include "ICharacter.h"
#include "CharacterFactory.h"
#include "Cleric.h"
#include "Fighter.h"
#include "Rogue.h"
#include "Wizard.h"
#include <gtest/gtest.h>
#include <iostream>

	TEST(Die, D20)
	{
		Die die;;
		int roll = die.D20();
		ASSERT_TRUE(roll >= 1);
		ASSERT_TRUE(roll <= 20);
	}

	TEST(Die, roll)
	{
		Die die;;
		int roll = die.roll(1000);
		ASSERT_TRUE(roll >= 1);
		ASSERT_TRUE(roll <= 1000);
	}
		
 	TEST(simpleWeapon, getDamage)
	{
		simpleWeapon mace("Mace", 1, 12, 2);
		int damage = mace.getDamage();

		ASSERT_TRUE(damage >= 2);
		ASSERT_TRUE(damage <= 15);
	}

	TEST(simpleWeapon, getName)
	{
		simpleWeapon terraBlade("Terra Blade", 1, 12, 2);
		string name = terraBlade.GetName();

		ASSERT_EQ(name, "Terra Blade");
	}

	TEST(Elf, getStats1)
	{
		std::shared_ptr<ICharacter> val  = CharacterFactory::GetCharacterFactory().CreateClass(CharacterFactory::WizardType, CharacterFactory::ElfType, "Buddy");
		std::shared_ptr<Wizard> elf1 = std::dynamic_pointer_cast<Wizard>(val);

		ASSERT_EQ(elf1->GetAmourClass(), 12);
		ASSERT_EQ(elf1->GetHitPoints(), 8);
		ASSERT_EQ(elf1->GetInitiative(), 2);
	}

	TEST(Elf, getStats2)
	{
		std::shared_ptr<ICharacter> val  = CharacterFactory::GetCharacterFactory().CreateClass(CharacterFactory::ClericType, CharacterFactory::ElfType, "Buddy");
		std::shared_ptr<Cleric> elf1 = std::dynamic_pointer_cast<Cleric>(val);

		ASSERT_EQ(elf1->GetAmourClass(), 14);
		ASSERT_EQ(elf1->GetHitPoints(), 9);
		ASSERT_EQ(elf1->GetInitiative(), 1);
	}

	TEST(Human, getStats1)
	{
		std::shared_ptr<ICharacter> val  = CharacterFactory::GetCharacterFactory().CreateClass(CharacterFactory::WizardType, CharacterFactory::HumanType, "Patrick");
		std::shared_ptr<Wizard> elf1 = std::dynamic_pointer_cast<Wizard>(val);

		ASSERT_EQ(elf1->GetAmourClass(), 15);
		ASSERT_EQ(elf1->GetHitPoints(), 10);
		ASSERT_EQ(elf1->GetInitiative(), 0);
	}

	TEST(Human, getStats2)
	{
		std::shared_ptr<ICharacter> val  = CharacterFactory::GetCharacterFactory().CreateClass(CharacterFactory::ClericType, CharacterFactory::HumanType, "John");
		std::shared_ptr<Cleric> elf1 = std::dynamic_pointer_cast<Cleric>(val);

		ASSERT_EQ(elf1->GetAmourClass(), 17);
		ASSERT_EQ(elf1->GetHitPoints(), 11);
		ASSERT_EQ(elf1->GetInitiative(), -1);
	}

	TEST(Party, add)
	{
		Party party("Party!");
		std::shared_ptr<ICharacter> val;
		val = CharacterFactory::GetCharacterFactory().CreateClass(CharacterFactory::WizardType, CharacterFactory::ElfType, "1");
		std::shared_ptr<Wizard> wizard1 = std::dynamic_pointer_cast<Wizard>(val);
		party.AddPartyMember(wizard1);
		
		val = CharacterFactory::GetCharacterFactory().CreateClass(CharacterFactory::FighterType, CharacterFactory::HumanType, "2");
		std::shared_ptr<Fighter> fighter1 = std::dynamic_pointer_cast<Fighter>(val);
		party.AddPartyMember(fighter1);

		ASSERT_EQ(party.GetPartySize(), 2);
	}

	TEST(Party, remove)
	{
		Party party("Party!");
		std::shared_ptr<ICharacter> val;
		val = CharacterFactory::GetCharacterFactory().CreateClass(CharacterFactory::WizardType, CharacterFactory::ElfType, "1");
		std::shared_ptr<Wizard> wizard1 = std::dynamic_pointer_cast<Wizard>(val);
		party.AddPartyMember(wizard1);
		
		val = CharacterFactory::GetCharacterFactory().CreateClass(CharacterFactory::FighterType, CharacterFactory::HumanType, "2");
		std::shared_ptr<Fighter> fighter1 = std::dynamic_pointer_cast<Fighter>(val);
		party.AddPartyMember(fighter1);

		party.RemovePartyMember(fighter1);

		ASSERT_EQ(party.GetPartySize(), 1);
	}

	TEST(Party, getCharacter)
	{
		Party party("Party!");
		std::shared_ptr<ICharacter> val;
		val = CharacterFactory::GetCharacterFactory().CreateClass(CharacterFactory::WizardType, CharacterFactory::ElfType, "1");
		std::shared_ptr<Wizard> wizard1 = std::dynamic_pointer_cast<Wizard>(val);
		party.AddPartyMember(wizard1);
		
		val = CharacterFactory::GetCharacterFactory().CreateClass(CharacterFactory::FighterType, CharacterFactory::HumanType, "2");
		std::shared_ptr<Fighter> fighter1 = std::dynamic_pointer_cast<Fighter>(val);
		party.AddPartyMember(fighter1);

		ASSERT_EQ(party.GetCharSlot(0), wizard1);
	}

	TEST(Wizard, getName)
	{
		std::shared_ptr<ICharacter> val;
		val = CharacterFactory::GetCharacterFactory().CreateClass(CharacterFactory::WizardType, CharacterFactory::ElfType, "Dumbledore");
		std::shared_ptr<Wizard> wizard1 = std::dynamic_pointer_cast<Wizard>(val);
		
		ASSERT_EQ(wizard1->GetName(), "Dumbledore");
	}

	TEST(Wizard, attack)
	{
		std::shared_ptr<ICharacter> val;
		val = CharacterFactory::GetCharacterFactory().CreateClass(CharacterFactory::WizardType, CharacterFactory::ElfType, "1");
		std::shared_ptr<Wizard> wizard1 = std::dynamic_pointer_cast<Wizard>(val);

		val = CharacterFactory::GetCharacterFactory().CreateClass(CharacterFactory::WizardType, CharacterFactory::ElfType, "2");
		std::shared_ptr<Wizard> wizard2 = std::dynamic_pointer_cast<Wizard>(val);
		
		int healthBefore = wizard2->GetHitPoints();
		int damage = wizard1->AttackPlayer(0,wizard2);
		int healthAfter = wizard2->GetHitPoints();
		int diff = healthBefore - healthAfter;

		ASSERT_EQ(damage, diff);

	}

	TEST(Cleric, attackRoll)
	{
		std::shared_ptr<ICharacter> val;
		val = CharacterFactory::GetCharacterFactory().CreateClass(CharacterFactory::ClericType, CharacterFactory::DwarfType, " ");
    	std::shared_ptr<Cleric> cleric1 = std::dynamic_pointer_cast<Cleric>(val);
   		
		int attackRoll = cleric1->AttackRoll();

		ASSERT_TRUE(attackRoll >= 1);
		ASSERT_TRUE(attackRoll <= 24);
	}

	TEST(Cleric, takeDamage)
	{
		std::shared_ptr<ICharacter> val;
		val = CharacterFactory::GetCharacterFactory().CreateClass(CharacterFactory::ClericType, CharacterFactory::DwarfType, " ");
    	std::shared_ptr<Cleric> cleric1 = std::dynamic_pointer_cast<Cleric>(val);

		cleric1->TakeDamage(10);
		int HP = cleric1->GetHitPoints();

		ASSERT_EQ(HP, 1);
	}

	TEST(Fighter, partyName)
	{
		std::shared_ptr<ICharacter> val;
    	Party party("Fighters");
		val = CharacterFactory::GetCharacterFactory().CreateClass(CharacterFactory::FighterType, CharacterFactory::HumanType, "f");
    	std::shared_ptr<Fighter> fighter1 = std::dynamic_pointer_cast<Fighter>(val);

		string name = fighter1->GetParty();
		ASSERT_EQ(name,"None");

    	party.AddPartyMember(fighter1);

		name = fighter1->GetParty();
		ASSERT_EQ(name,"Fighters");
	}

	TEST(Fighter, initiative)
	{
		std::shared_ptr<ICharacter> val;
		val = CharacterFactory::GetCharacterFactory().CreateClass(CharacterFactory::FighterType, CharacterFactory::HumanType, "f");
    	std::shared_ptr<Fighter> fighter1 = std::dynamic_pointer_cast<Fighter>(val);

		int init = fighter1->GetInitiative();

		ASSERT_TRUE(init >= -1);
		ASSERT_TRUE(init <= 19);

	}

	TEST(Rogue, primaryWeapon)
	{
		std::shared_ptr<ICharacter> val;
		val = CharacterFactory::GetCharacterFactory().CreateClass(CharacterFactory::RogueType, CharacterFactory::HalflingType, "r");
		std::shared_ptr<Rogue> rougue1 = std::dynamic_pointer_cast<Rogue>(val);

		int damage = rougue1->AttackDamage(0);

		ASSERT_TRUE(damage >= 4);
		ASSERT_TRUE(damage <= 9);
	}

	TEST(Rogue, secondaryWeapon)
	{
		std::shared_ptr<ICharacter> val;
		val = CharacterFactory::GetCharacterFactory().CreateClass(CharacterFactory::RogueType, CharacterFactory::HalflingType, "r");
		std::shared_ptr<Rogue> rougue1 = std::dynamic_pointer_cast<Rogue>(val);

		int damage = rougue1->AttackDamage(1);

		ASSERT_TRUE(damage >= 4);
		ASSERT_TRUE(damage <= 9);
	}

	TEST(Rogue, noWeapon)
	{
		std::shared_ptr<ICharacter> val;
		val = CharacterFactory::GetCharacterFactory().CreateClass(CharacterFactory::RogueType, CharacterFactory::HalflingType, "r");
		std::shared_ptr<Rogue> rougue1 = std::dynamic_pointer_cast<Rogue>(val);

		int damage = rougue1->AttackDamage(2);

		ASSERT_EQ(damage, 0);
	}


 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
