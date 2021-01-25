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
	~CWater();

	void attackMonster(CAttack* attack, CMonster* target);
	bool flood();
	float getterFallMonster();

	void setterFlood(float flood);
	void setterFall(float fall);
};

