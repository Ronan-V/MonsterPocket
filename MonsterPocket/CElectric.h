#pragma once
#include "CMonster.h"
#include "CWater.h"

class CElectric :
	public CMonster
{
protected:

	float m_paralysis; // probability to paralyse the target


public:

	CElectric();
	~CElectric();
	void attackMonster(CAttack* attack, CMonster* target);

	bool paralyse();
	void setterParalyse(float paralyse);

};

