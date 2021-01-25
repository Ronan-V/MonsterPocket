#include "CWater.h"

CWater::CWater()
	:CMonster()
{
}

CWater::~CWater()
{
}

void CWater::attackMonster(CAttack* attack, CMonster* target)
{
	type targetType = target->getterTypeMonster();
	float advantage;
	float randomNb;
	double defenseTarget = 0;
	short damages;
	std::string sentence;

	sentence = m_nameMonster;
	sentence += " attacks ";
	sentence += attack->getterNameAttack();
	sentence += " ("; sentence += attack->getterTypeAttackAsString();	sentence += ")";
	printLetterByLetter(sentence);
	std::cout << std::endl;

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
	//Generate a random number between 0 and 1 to know if the attack fails
	else if (random(0, 1) < attack->getterFailRate())
	{
		std::cout << attack->getterNameAttack() << " failed !" << std::endl;
	}
	else
	{
		target->receiveDamages(damages); //Substract 'damages' from the target's HPs

		/*If flood() returns true AND :
			no negative state due to a specialty is effective 
			OR state is to Burned
			OR state is to Poisoned*/
		if (flood() && (m_state == state::Healthy || m_state == state::Burned || m_state == state::Poisoned))
		{
			m_state = state::Flooded;
			m_nbTurnUnderState = 0;
			m_nbTurnState = random(0, 3.999);	//random() function is using double values, that's why we use 3.999 to have a short between 0 and 3
			std::cout << m_nameMonster << " floods the ground" << std::endl;

		}
	}
	attack->decrementUseNumber(); //Decrement the attack's use number
}

bool CWater::flood()
{
	return randomLowerThan(0, 1, m_flood);
}

float CWater::getterFallMonster()
{
	return m_fall;
}

void CWater::setterFlood(float flood)
{
	m_flood = flood;
}

void CWater::setterFall(float fall)
{
	m_fall = fall;
}
