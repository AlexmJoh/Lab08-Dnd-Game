#pragma once

#include <iostream>
#include "Die.h"

using namespace std;

class IItem
{
    int itemCost, itemWeight;
    string itemName;
public:

    IItem(){}
    
    IItem(string name) : itemName(name)
    {
        itemWeight = 1;
        itemCost = 1;
    }

    IItem(string name, int cost, int weight) : 
    itemName(name), itemCost(cost), itemWeight(weight) {}

    string GetName() { return itemName; }

    ~IItem(){}
};

class simpleWeapon : public IItem
{
    int w_range, w_dmgDieCnt, w_dmgDieFaces, w_bonusDamage;
    string w_damageType, w_type;
public:
    simpleWeapon(){}

    simpleWeapon(string name, int dieCnt, int dieFaces, int bonus) : IItem(name)
    {
        w_dmgDieCnt = dieCnt;
        w_dmgDieFaces = dieFaces;
        w_bonusDamage = bonus;
    }

    ~simpleWeapon(){}

    int getDamage()
    {
        Die dmgRoll;
        int damage = w_bonusDamage;
        for(int i = 0; i < w_dmgDieCnt; i++)
        { 
            damage = damage + dmgRoll.roll(w_dmgDieFaces); 
        }
        return damage;
    }


};

