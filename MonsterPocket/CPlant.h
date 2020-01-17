#pragma once
#include "CGrass.h"
class CPlant :
	public CGrass
{
protected:

	float m_cure; //probability to cure itself

public:

	CPlant();
	CPlant(std::string nameMonster, int hp, float speed, int attack, int defense, std::string state, std::string weakness, float cure);
	~CPlant();
	bool cure();

};

