#include "CPotion.h"

CPotion::CPotion()
	: CObject()
{
	m_power = 0;
}

CPotion::CPotion(std::string name, short power, std::string typeOfObject)
	: CObject(name, typeOfObject)
{
	m_power = power;
}

CPotion::~CPotion()
{
}

void CPotion::useObject(CMonster* monster, std::string nameObject)
{
	if (nameObject == "Potion" || nameObject == "Super-Potion" || nameObject == "Hyper-Potion")
	{
		monster->giveHpMonster(m_power);	//Give 'power' HPs
	}
	else if (nameObject == "Attack+")
	{
		monster->giveAttackMonster(m_power);	//Give 'power' speed points
	}
	else if (nameObject == "Defense+")
	{
		monster->giveDefenseMonster(m_power);	//Give 'power' attack points
	}
	else if (nameObject == "Speed+")
	{
		monster->giveSpeedMonster(m_power);		//Give 'power' defense points
	}
}
