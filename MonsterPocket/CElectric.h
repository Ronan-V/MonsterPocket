#pragma once
#include "CMonster.h"
class CElectric :
	public CMonster
{
protected:

	float m_paralysis; // probability to paralyse the target


public:

	CElectric();
	CElectric(std::string nameMonster, int hp, float speed, int attack, int defense, std::string state, std::string weakness, float paralysis);

	~CElectric();
	bool paralyse();

};

