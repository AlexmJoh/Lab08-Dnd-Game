#pragma once


#include "ICharacter.h"
#include <memory>
#include <map>

//fwd declaration
class IRace;

class CharacterFactory
{
public:
	//Enums for all the different classes and races supported
	enum classType { WizardType, ClericType, RogueType, FighterType };
	enum raceType { ElfType, HumanType, DwarfType, HalflingType };

	std::shared_ptr<ICharacter> CreateClass(classType classT, raceType raceT, string nameT);

	static 	CharacterFactory & GetCharacterFactory();

  	CharacterFactory(const CharacterFactory &) = delete;
  	CharacterFactory & operator = (const CharacterFactory &) = delete;

private:
	//Map to hold races, filled in constructor
	std::map<raceType,std::shared_ptr<IRace>> m_raceMap;

	CharacterFactory() ;
    ~CharacterFactory() ;

};

