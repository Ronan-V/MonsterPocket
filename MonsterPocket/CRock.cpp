#include "CRock.h"

CRock::CRock()
{
}
CRock::CRock(std::string nameMonster, int hp, float speed, int attack, int defense, std::string state, std::string weakness, float hide)
	:CMonster(nameMonster, hp, speed, attack, defense, state, weakness)
{
	m_hide = hide;
}

CRock::~CRock()
{
}

bool CRock::hide()
{
	return false;
}
