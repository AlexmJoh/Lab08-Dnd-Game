// PartyAttack.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <memory>
#include <vector>
#include <bits/stdc++.h>
#include "Party.h"
#include "ICharacter.h"
#include "Wizard.h"
#include "Cleric.h"
#include "Fighter.h"
#include "Rogue.h"
#include "CharacterFactory.h"
#include "IRace.h"
#include "PartyAttack.h"
#include "Die.h"

//Function to create a genic party with 4 members having one of each class and race
Party CreateParty(string p_name, string w_name, string f_name, string c_name, string r_name)
{
    std::shared_ptr<ICharacter> val;
    Party party(p_name);

    val = CharacterFactory::GetCharacterFactory().CreateClass(CharacterFactory::WizardType, CharacterFactory::ElfType, w_name);
    std::shared_ptr<Wizard> wizard1 = std::dynamic_pointer_cast<Wizard>(val);
    party.AddPartyMember(wizard1);
    
    val = CharacterFactory::GetCharacterFactory().CreateClass(CharacterFactory::FighterType, CharacterFactory::HumanType, f_name);
    std::shared_ptr<Fighter> fighter1 = std::dynamic_pointer_cast<Fighter>(val);
    party.AddPartyMember(fighter1);

    val = CharacterFactory::GetCharacterFactory().CreateClass(CharacterFactory::ClericType, CharacterFactory::DwarfType, c_name);
    std::shared_ptr<Cleric> cleric1 = std::dynamic_pointer_cast<Cleric>(val);
    party.AddPartyMember(cleric1);

    val = CharacterFactory::GetCharacterFactory().CreateClass(CharacterFactory::RogueType, CharacterFactory::HalflingType, r_name);
    std::shared_ptr<Rogue> rougue1 = std::dynamic_pointer_cast<Rogue>(val);
    party.AddPartyMember(rougue1);

    return party;

}

//Function to sort order of characters based on intiative roll
void PairSort(vector<int> &  a, vector<std::shared_ptr<ICharacter>> & b, int n)
{
    vector<int> tempA = a;
    vector<std::shared_ptr<ICharacter>> tempB = b;

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
		{
			if(a[i]>a[j])
			{
				int temp1  = a[i];
				a[i] = a[j];
				a[j] = temp1;

                std::shared_ptr<ICharacter> temp2 = b[i];
				b[i] = b[j];
				b[j] = temp2;
			}
		}
    }

}


int main()
{
    //Make the game random!!
    srand(time(0));
    //Creating two generic partys using function
    Party p1 = CreateParty("Goon Squad", "Errich LongBottom", "Ryder Kelmp", "Vondal Thunderfist", "Count Schecklemeister");
    Party p2 = CreateParty("Choatic Stupid", "Edwin Wimwag", "Wulf Fondler", "Dexameni", "Gimpy");

    //setting up intitial variables for fight
    bool fightOver = false;
    int turn = 0;
    string winner = "No one";
    int participants = p1.GetPartySize() + p2.GetPartySize();
    Die die;
    int attackRoll, weaponC, target, damage;

    cout << "--------------------------------------------------------------------------------------" << endl;
    cout << "The battle between the " << p1.GetPartyName() << " and " << p2.GetPartyName() << " has begun!!!" << endl;
    cout << "--------------------------------------------------------------------------------------" << endl;

    //While loop for entire fight 
    while(!fightOver)
    {
        turn = turn + 1; //Incrementing turn
        cout << "--------------------------------------------------------------------------------------" << endl;
        cout << "Turn: " << turn << endl;
        cout << "--------------------------------------------------------------------------------------" << endl;
        
        //Creating a vectorof all players in the fight
        vector<std::shared_ptr<ICharacter>> order;

        //Adding players from party 1
        for (int i = 0; i < p1.GetPartySize(); i++)
        { order.push_back(p1.GetCharSlot(i)); }

        //Adding players from party 2
        for (int i = 0; i < p2.GetPartySize(); i++)
        { order.push_back(p2.GetCharSlot(i)); }

        //Creating a vector of players rolled intiative values in order of 'order' vector
        vector<int> init;
        for (int i = 0; i < order.size(); i++)
        { init.push_back(order[i]->GetInitiative() + die.D20()); }

        //Rearranging players postion in 'order' based om corrosponding init roll
        PairSort(init, order, participants);

        //For loop to go through all partipants in a turn
        for(int i = 0; i < participants; i++)
        {
            if(p1.IsPartyDead()) //Checking if party 1 is dead
            {
                winner = p2.GetPartyName(); //If true party 2 has won
                fightOver = true;
                break;
            }

            if(p2.IsPartyDead()) //Checking if party 2 is dead
            {
                winner = p1.GetPartyName(); //If true party 1 has won
                fightOver = true;
                break;
            }
            
            Party* oppParty;
            //oppParty points to opposing party of the character currently up
            if(order[i]->GetParty() == p1.GetPartyName()) { oppParty= &p2; }
            if(order[i]->GetParty() == p2.GetPartyName()) { oppParty= &p1; }

            //Player picks a random target in opposing party
            target = die.roll(oppParty->GetPartySize()) - 1;

            //If target is dead a new target will be picked
            while(oppParty->GetCharSlot(target)->GetHitPoints() <= 0)
            { target = die.roll(oppParty->GetPartySize()) - 1; }

            //targetP is created to be the player targeted
            std::shared_ptr<ICharacter> targetP = oppParty->GetCharSlot(target);
               
            //Player up rolls to attack, if higher/equal to target AC it hits
            attackRoll = order[i]->AttackRoll();
            if(attackRoll >= targetP->GetAmourClass())
            {
                //A random weapon is chosen to attack with 0(Primary), 1(Secondary)
                weaponC = (die.roll(2) - 1);
                //Player up attacks the target of the opposite party, damage is returned
                damage = order[i]->AttackPlayer(weaponC, targetP);

                cout << targetP->GetName() << " was attacked by " << order[i]->GetName() << " dealing "
                << damage << " hitpoints of damage!" << endl;

                if(targetP->GetHitPoints() < 0)
                { cout << targetP->GetName() << "Has fallen in battle!" << endl; }
            }
            else
            {
                cout << order[i]->GetName() << " attacked " << targetP->GetName() << " but missed!" << endl;
            }
            cout << endl;

        }

    }
    cout << "--------------------------------------------------------------------------------------" << endl;
    cout << winner << " has won the fight in " << turn << " turns!!!" << endl;
    cout << "--------------------------------------------------------------------------------------" << endl;
}