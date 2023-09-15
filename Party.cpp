
#include "Party.h"

Party::Party(){}

Party::Party(string name)
{
    p_name = name;
    p_size = 0;
}


void Party::AddPartyMember(std::shared_ptr<ICharacter> character)
{
    p_members.push_back(character);
    character->SetParty(p_name);
    p_size = p_size + 1;
}

void Party::RemovePartyMember(std::shared_ptr<ICharacter> character)
{
    for(int i= 0 ; i < p_members.size(); i++)
    {
      if(p_members[i] == character)
      { p_members.erase(p_members.begin() + i); }
    }
    character->SetParty("None");
    p_size = p_size - 1;
}

std::shared_ptr<ICharacter> Party::GetCharSlot(int slot)
{
    if(slot <= (p_size -1)) { return(p_members[slot]); }
    else { return nullptr; }
}

void Party::SetPartyName(string name){ p_name = name; }

string Party::GetPartyName(){ return p_name; }
   
int Party::GetPartySize() { return p_size; }

bool Party::IsPartyDead()
{
    int HP;
    if(p_size == 0) { return true; }
    for(int i = 0; i < p_size; i++)
    {
        HP = p_members[i]->GetHitPoints();
        if(HP > 0)
        { return false; }
    }
   return true;
}

Party::~Party(){}

