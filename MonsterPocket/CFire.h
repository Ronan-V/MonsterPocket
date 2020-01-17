#pragma once
#include "CMonster.h"
class CFire :
	public CMonster
{

protected:

	float m_burn; //probability to burn the target


public:

	CFire();
	CFire(std::string nameMonster, int hp, float speed, int attack, int defense, std::string state, std::string weakness, float burn);
	~CFire();
	bool burned();

};

