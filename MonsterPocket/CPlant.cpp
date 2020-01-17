#include "CPlant.h"

CPlant::CPlant()
{
}

CPlant::CPlant(std::string nameMonster, int hp, float speed, int attack, int defense, std::string state, std::string weakness, float cure)
	:CGrass(nameMonster, hp, speed, attack, defense, state, weakness)
{
	m_cure = cure;
}

CPlant::~CPlant()
{
}

bool CPlant::cure()
{
	return false;
}
