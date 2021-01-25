#include "CInsect.h"

CInsect::CInsect()
	:CGrass()
{
}

CInsect::~CInsect()
{
}

void CInsect::attackMonster(CAttack* attack, CMonster* target)
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

		//If poison() returns true AND the target has no negative state due to a specialty AND the target isn't Insect
		if (poison() && target->getterStateMonster() == state::Healthy && target->getterTypeMonster() != type::Insect)
		{
			target->setterStateMonster(state::Poisoned);
			target->setternbTurnUnderState(0);
			std::cout << target->getterNameMonster() << " is poisoned" << std::endl;

		}
	}
	attack->decrementUseNumber(); //Decrement the attack's use number

	if (target->getterStateMonster() == state::Flooded)
	{
		giveHpMonster(m_maxHP / 20); //Earn a twentieth of its HPs
	}
}

bool CInsect::poison()
{
	return randomLowerThan(0, 1, m_poison);
}

void CInsect::setterPoison(float poison)
{
	m_poison = poison;
}

