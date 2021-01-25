#pragma once
#include "CGrass.h"
class CPlant :
	public CGrass
{
protected:

	float m_cure; //probability to cure itself

public:

	CPlant();
	~CPlant();
	void attackMonster(CAttack* attack, CMonster* target);


	bool cure();
	void setterCure(float cure);

};

