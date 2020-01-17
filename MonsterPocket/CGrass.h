#pragma once
#include "CMonster.h"
class CGrass :
	public CMonster
{

protected:


public:

	CGrass();
	CGrass(std::string nameMonster, int hp, float speed, int attack, int defense, std::string state, std::string weakness);
	~CGrass();
};

