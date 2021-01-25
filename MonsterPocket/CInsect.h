#pragma once
#include "CGrass.h"
class CInsect :
	public CGrass
{
protected:

	float m_poison; // probability to poison the target

public:

	CInsect();
	~CInsect();
	void attackMonster(CAttack* attack, CMonster* target);


	bool poison();
	void setterPoison(float poison);
};

