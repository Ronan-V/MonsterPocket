#include "CGrass.h"

CGrass::CGrass()
{
}

CGrass::CGrass(std::string nameMonster, int hp, float speed, int attack, int defense, std::string state, std::string weakness)
	:CMonster(nameMonster, hp, speed, attack, defense, state, weakness)
{

}

CGrass::~CGrass()
{
}
