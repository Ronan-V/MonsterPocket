#include "CFire.h"

CFire::CFire()
{
}

CFire::CFire(std::string nameMonster, int hp, float speed, int attack, int defense, std::string state, std::string weakness, float burn)
	:CMonster(nameMonster, hp, speed, attack, defense, state, weakness)
{
	m_burn = burn;
}

CFire::~CFire()
{
}

bool CFire::burned()
{
	return false;
}
