#include "CAttack.h"


CAttack::CAttack()
{
}

CAttack::CAttack(std::string nameAttack, std::string type, int useNumber, int power, float failRate)
{
	m_nameAttack = nameAttack;
	m_type= type;
	m_useNumber = useNumber;
	m_power = power;
	m_failRate = failRate;
}

CAttack::~CAttack()
{
}

void CAttack::decrementUseNumber()
{
	m_useNumber--;
}

std::string CAttack::getterType() const
{
	return m_type;
}

int CAttack::getterPower() const
{
	return m_power;
}

float CAttack::getterFailRate() const
{
	return m_failRate;
}




