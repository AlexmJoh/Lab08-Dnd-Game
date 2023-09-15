#pragma once

class IRace
{
public:

	IRace(int m_HP, int m_Armour, int m_Init, int m_Speed): 
	m_hitPointMods(m_HP), m_amourClassMods(m_Armour), 
	m_initiativeMods(m_Init), m_speedMods(m_Speed)	{}

	virtual int GetHitPointMods(){ return m_hitPointMods; } 
	virtual int GetArmourClassMods(){ return m_amourClassMods; } 
	virtual int GetInitiativeMods(){ return m_initiativeMods; } 
	virtual int GetSpeedMods(){ return m_speedMods; } 

    ~IRace() {}

protected:
	int m_hitPointMods;
	int m_amourClassMods;
	int m_initiativeMods;
	int m_speedMods;
};


class Elf  : public IRace
{

public:
	Elf() :  IRace(-1,1,1,5) {}
    virtual ~Elf() {}
};


class Human  : public IRace
{

public:
	Human() : IRace(1, 4, -1, 5) {}
    virtual ~Human() {}

};

class Dwarf  : public IRace
{

public:
	Dwarf() :  IRace(1,5,-1,0) {}
    virtual ~Dwarf() {}

};


class Halfling  : public IRace
{

public:
	Halfling() : IRace(-1, 2, 2, 0) {}
    virtual ~Halfling() {}

};


