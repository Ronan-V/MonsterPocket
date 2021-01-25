#pragma once
#include "CMonster.h"

class CRock :
	public CMonster
{
protected:
	
	float m_hide; //probabilty to hide underground

public:

	CRock();
	~CRock();
	void attackMonster(CAttack* attack, CMonster* target);

	bool hide();
	void setterHide(float hide);
};

