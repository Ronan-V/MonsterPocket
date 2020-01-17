#include "CInsect.h"

CInsect::CInsect()
{
}

CInsect::CInsect(std::string nameMonster, int hp, float speed, int attack, int defense, std::string state, std::string weakness, float poison)
	:CGrass(nameMonster, hp, speed, attack, defense, state, weakness)
{

}

CInsect::~CInsect()
{
}

bool CInsect::poison()
{
	return false;
}
