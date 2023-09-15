

#pragma once

#include <vector>
#include <memory>
#include <iostream>
#include "ICharacter.h"
#include "Wizard.h"
#include "Cleric.h"
#include "Rogue.h"
#include "Fighter.h"


class ICharacter;

class Party
{
   
  
public:
   Party();
   Party(string name);
   ~Party();

   void AddPartyMember(std::shared_ptr<ICharacter> character);
   void RemovePartyMember(std::shared_ptr<ICharacter> character);

   std::shared_ptr<ICharacter> GetCharSlot(int slot);

   void SetPartyName(string name);
   string GetPartyName();

   int GetPartySize();
   bool IsPartyDead();

   //static Party & GetParty();

private:
   string p_name;
   int p_size;
   vector<std::shared_ptr<ICharacter>> p_members;

   
};


