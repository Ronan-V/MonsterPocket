#include "CPlant.h"

CPlant::CPlant()
	:CGrass()
{
}

CPlant::~CPlant()
{
}

void CPlant::attackMonster(CAttack* attack, CMonster* target)
{
	type targetType = target->getterTypeMonster();
	float advantage;
	float randomNb;
	short defenseTarget = 0;
	short damages;

	std::cout << m_nameMonster << " attacks " << attack->getterNameAttack() << std::endl;

	defenseTarget = target->getterDefenseMonster();
	if (target->getterStateMonster() == state::Hidden) { defenseTarget *= 2; }
	advantage = target->getAdvantage(attack->getterTypeAttack());	//Get the advantage
	//Calculate the damages the enemy will take
	damages = (((11 * (double)m_attack * (double)attack->getterPower()) / (defenseTarget * 25) + 2) * advantage * random(0.85, 1));

	if (m_state == state::Paralysed && randomLowerThan(0, 1, 1 / 4))	//When paralysed, the monster has 1 chance over 4 to fail its attack
	{
		std::cout << m_nameMonster << " got stuck ... ";
		std::cout << attack->getterNameAttack() << " failed !" << std::endl;
	}
	else if (target->getterStateMonster() == state::Flooded && randomLowerThan(0, 1, target->getterFallMonster()))
	{
		std::cout << m_nameMonster << " slipped ... ";
		std::cout << attack->getterNameAttack() << " failed !" << std::endl;
		std::cout << m_nameMonster << " receive its own attack" << std::endl;
		receiveDamages(damages);
	}
	//Generate a random number between 0 and 1 to know if the attack fails
	else if (random(0, 1) < attack->getterFailRate())
	{
		std::cout << attack->getterNameAttack() << " failed !" << std::endl;
	}
	else
	{
		target->receiveDamages(damages); //Substract 'damages' from the target's HPs

		//If cure() returns true and the monster isn't already healthy, cure it
		if (cure() && m_state != state::Healthy)
		{
			m_state = state::Healthy;
			m_nbTurnUnderState = 0;
			std::cout << m_nameMonster << " cures himself" << std::endl;

		}
	}
	attack->decrementUseNumber(); //Decrement the attack's use number

	if (target->getterStateMonster() == state::Flooded)
	{
		m_hp += m_maxHP / 20;
		if (m_hp > m_maxHP) { m_hp = m_maxHP; } //Not to go beyond max_hp
	}
}

bool CPlant::cure()
{
	return randomLowerThan(0, 1, m_cure);
}

void CPlant::setterCure( float cure)
{
	m_cure = cure;
}
