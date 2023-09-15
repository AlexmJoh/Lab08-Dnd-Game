#include "CharacterFactory.h"


#include "Wizard.h"
#include "Cleric.h"
#include "Rogue.h"
#include "Fighter.h"


CharacterFactory & CharacterFactory::GetCharacterFactory()
{
	static CharacterFactory s;
	return s;
}

//Fuction to create character give classType, raceType and name
std::shared_ptr<ICharacter> CharacterFactory::
CreateClass(classType classT, raceType raceT, string nameT)
{
	std::shared_ptr<ICharacter> retVal = nullptr;
	if (classT == WizardType)
	{
		retVal = std::make_shared<Wizard>(m_raceMap[raceT], nameT);
	}
    else if (classT == ClericType)
    {
        retVal = std::make_shared<Cleric>(m_raceMap[raceT], nameT); 
    }
	else if (classT == RogueType)
    {
        retVal = std::make_shared<Rogue>(m_raceMap[raceT], nameT); 
    }
	else if (classT == FighterType)
    {
        retVal = std::make_shared<Fighter>(m_raceMap[raceT], nameT); 
    }

	return retVal;
}

//Constructor creates race map when constructed
CharacterFactory::CharacterFactory() 
{
	//Make map for all races
	std::shared_ptr<IRace> t1 = std::make_shared<Elf>();
	std::shared_ptr<IRace> t2 = std::make_shared<Human>();
	std::shared_ptr<IRace> t3 = std::make_shared<Dwarf>();
	std::shared_ptr<IRace> t4 = std::make_shared<Halfling>();

	m_raceMap.insert(std::pair(ElfType, t1));
	m_raceMap[HumanType]= t2;
	m_raceMap[DwarfType]= t3;
	m_raceMap[HalflingType]= t4;
}

//Destructor
CharacterFactory::~CharacterFactory() 
{

}