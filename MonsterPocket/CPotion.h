#pragma once
#include "CObject.h"
class CPotion :
	public CObject
{
protected:

	int m_power;


public:

	CPotion();
	CPotion(int power);
	~CPotion();

	void healingPot(int m_power);
	void speedPlus(int m_power);
	void attackPlus(int m_power);
	void defensePlus(int m_power);
};

