#pragma once
#include "CObject.h"
#include "CMonster.h"
#include "utils.h"
class CPotion :
	public CObject
{
protected:

	short m_power;


public:

	CPotion();
	CPotion(std::string name, short power, std::string typeOfObject);
	~CPotion();
	void useObject(CMonster* monster, std::string nameObject);
};

