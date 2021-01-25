#pragma once
#include "CMonster.h"
class CFire :
	public CMonster
{

protected:

	float m_burn; //probability to burn the target


public:

	CFire();
	~CFire();
	void attackMonster(CAttack* attack, CMonster* target);

	bool burned();
	void setterBurn(float burn);

};

