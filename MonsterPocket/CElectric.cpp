#include "CElectric.h"

CElectric::CElectric()
{
}

CElectric::CElectric(std::string nameMonster, int hp, float speed, int attack, int defense, std::string state, std::string weakness, float paralysis)
	:CMonster(nameMonster, hp, speed, attack, defense, state, weakness)
{
	m_paralysis = paralysis;
}


CElectric::~CElectric()
{
}

bool CElectric::paralyse()
{
	return false;
}
