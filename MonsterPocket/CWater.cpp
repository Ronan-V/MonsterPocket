#include "CWater.h"

CWater::CWater()
{
}

CWater::CWater(std::string nameMonster, int hp, float speed, int attack, int defense, std::string state, std::string weakness, float flood, float fall)
	:CMonster(nameMonster, hp, speed, attack, defense, state, weakness)
{
	m_flood = flood;
	m_fall = fall;
}

CWater::~CWater()
{
}

bool CWater::flood()
{
	return false;
}
