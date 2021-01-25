#include "CAttack.h"


CAttack::CAttack()
{
}

CAttack::CAttack(std::string nameAttack, type typeAttack, short useNumber, short power, float failRate)
{
	m_nameAttack = nameAttack;
	m_typeAttack = typeAttack;
	m_useNumber = useNumber;
	m_power = power;
	m_failRate = failRate;
}

CAttack::~CAttack()
{
}

void CAttack::decrementUseNumber() // Once we attacked, soustract 1 to the useNumber to have a maximum use.
{
	m_useNumber--;
	std::string sentence;

	sentence = m_nameAttack;
	sentence += " has ";
	printLetterByLetter(sentence);
	std::cout << m_useNumber;
	sentence = " uses left";
	printLetterByLetter(sentence);
	std::cout << std::endl << std::endl;

}

std::string CAttack::getterNameAttack() const
{
	return m_nameAttack;
}

type CAttack::getterTypeAttack() const
{
	return m_typeAttack;
}

std::string CAttack::getterTypeAttackAsString() const
{
	std::string type;
	switch (m_typeAttack)
	{
	case type::Fire:
		type = "Fire";
		break;
	case type::Grass:
		type = "Grass";
		break;
	case type::Rock:
		type = "Rock";
		break;
	case type::Electric:
		type = "Electric";
		break;
	case type::Water:
		type = "Water";
		break;
	case type::Normal:
		type = "Normal";
		break;
	}
	return type;
}

short CAttack::getterUseNumber() const
{
	return m_useNumber;
}

short CAttack::getterPower() const
{
	return m_power;
}

float CAttack::getterFailRate() const
{
	return m_failRate;
}

void CAttack::setterNameAttack(std::string nameAttack)
{
	m_nameAttack = nameAttack;
}

void CAttack::setterTypeAttack(type typeAttack)
{
	m_typeAttack = typeAttack;
}

void CAttack::setterUseNb(short useNb)
{
	m_useNumber = useNb;
}

void CAttack::setterPowerAttack(short power)
{
	m_power = power;
}

void CAttack::settterFailRate(float failRate)
{
	m_failRate = failRate;
}