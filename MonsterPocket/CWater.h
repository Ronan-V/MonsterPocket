#pragma once
#include "CMonster.h"
class CWater :
	public CMonster
{
protected:
	float m_flood; //probability to flood the ground
	float m_fall; //probability of the enemy to fall and fail his attack

public:

	CWater();
	CWater(std::string nameMonster, int hp, float speed, int attack, int defense, std::string state, std::string weakness, float flood, float fall);
	~CWater();
	bool flood();
};

