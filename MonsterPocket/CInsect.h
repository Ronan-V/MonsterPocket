#pragma once
#include "CGrass.h"
class CInsect :
	public CGrass
{
protected:

	float m_poison; // probability to poison the target

public:

	CInsect();
	CInsect(std::string nameMonster, int hp, float speed, int attack, int defense, std::string state, std::string weakness, float poison);
	~CInsect();
	bool poison();
};

