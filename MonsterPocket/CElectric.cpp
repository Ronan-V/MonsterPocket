#include "CElectric.h"

CElectric::CElectric()
	:CMonster()
{
}

CElectric::~CElectric()
{
}

void CElectric::attackMonster(CAttack* attack, CMonster* target)
{
	type targetType = target->getterTypeMonster();
	float advantage;
	short defenseTarget = 0;
	short damages;

	std::cout << m_nameMonster;
	printLetterByLetter(" attacks ");
	std::cout << attack->getterNameAttack() << std::endl;


	defenseTarget = target->getterDefenseMonster();
	if (target->getterStateMonster() == state::Hidden) { defenseTarget *= 2; }
	advantage = target->getAdvantage(attack->getterTypeAttack());	//Get the advantage
	//Calculate the damages the enemy will take
	damages = (((11 * (double)m_attack * (double)attack->getterPower()) / (defenseTarget * 25) + 2) * advantage * random(0.85, 1));

	if (target->getterStateMonster() == state::Flooded && randomLowerThan(0, 1, target->getterFallMonster()))
	{
		std::cout << m_nameMonster;
		printLetterByLetter(" slipped ... ");
		std::cout << attack->getterNameAttack();
		printLetterByLetter(" failed !");
		std::cout << std::endl;
		std::cout << m_nameMonster;
		printLetterByLetter(" receive its own attack");
		std::cout << std::endl;
		receiveDamages(damages);
	}
	//Generate a random number between 0 and 1 to know if the attack fails
	else if (random(0, 1) < attack->getterFailRate())
	{
		std::cout << attack->getterNameAttack();
		printLetterByLetter(" failed !");
		std::cout << std::endl;
	}
	else
	{
		target->receiveDamages(damages);	 //Substract 'damages' from the target's HPs.

		//If paralyze() returns true AND the target has no negative state due to a specialty AND the target isn't Electric
		if (paralyse() && target->getterStateMonster() == state::Healthy && target->getterTypeMonster() != type::Electric)
		{
			target->setterStateMonster(state::Paralysed);
			target->setternbTurnUnderState(0);
			std::cout << target->getterNameMonster();
			printLetterByLetter(" is paralysed");
			std::cout << std::endl;
		}
	}
	attack->decrementUseNumber();	//Decrement the attack's use number
}

bool CElectric::paralyse()
{
	//If the result is lower than 'm_paralysis', the attack stuns the target
	return randomLowerThan(0, 1, m_paralysis);
}

void CElectric::setterParalyse(float paralyse)
{
	m_paralysis = paralyse;
}


