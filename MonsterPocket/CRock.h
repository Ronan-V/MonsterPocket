#pragma once
#include "CMonster.h"
class CRock :
	public CMonster
{
protected:
	
	float m_hide; //probabilty to hide underground

public:

	CRock();
	CRock(std::string nameMonster, int hp, float speed, int attack, int defense, std::string state, std::string weakness, float hide);
	~CRock();
	bool hide();
};

