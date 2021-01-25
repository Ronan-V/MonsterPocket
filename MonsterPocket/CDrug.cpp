#include "CDrug.h"

CDrug::CDrug()
	: CObject()
{
}

CDrug::CDrug(std::string name, std::string typeOfObject)
	: CObject(name, typeOfObject)
{

}

CDrug::~CDrug()
{
}

void CDrug::useObject(CMonster* monster, std::string nameObject)
{
	if (nameObject == "Anti-Burn")
	{
		if (monster->getterStateMonster() == state::Burned)
		{
			monster->setterStateMonster(state::Healthy);

			std::cout << monster->getterNameMonster();
			printLetterByLetter(" is no longer burned");
			std::cout << std::endl << std::endl;
		}
		else
		{
			std::cout << monster->getterNameMonster();
			printLetterByLetter(" wasn't burned ... Anti-Burn is wasted");
			std::cout << std::endl << std::endl;
		}
	}
	else if (nameObject == "Sponge")
	{
		if (monster->getterStateMonster() == state::Flooded) //'monster' corresponds here to the enemy monster
		{
			monster->setterStateMonster(state::Healthy);

			printLetterByLetter("The ground is no longer flooded");
			std::cout << std::endl << std::endl;
		}
		else
		{
			printLetterByLetter("The ground wasn't flooded ... Sponge is wasted");
			std::cout << std::endl << std::endl;
		}
	}
	else if (nameObject == "Antidote")
	{
		if (monster->getterStateMonster() == state::Poisoned)
		{
			monster->setterStateMonster(state::Healthy);

			std::cout << monster->getterNameMonster();
			printLetterByLetter(" is no longer poisoned");
			std::cout << std::endl;

		}
		else
		{
			std::cout << monster->getterNameMonster();
			printLetterByLetter(" wasn't poisoned ... Antidote is wasted");
			std::cout << std::endl;
		}
	}
	else if (nameObject == "Anti-Para")
	{
		if (monster->getterStateMonster() == state::Paralysed)
		{
			monster->setterStateMonster(state::Healthy);

			std::cout << monster->getterNameMonster();
			printLetterByLetter(" is no longer paralysed");
			std::cout << std::endl;

		}
		else
		{
			std::cout << monster->getterNameMonster();
			printLetterByLetter(" wasn't paralysed ... Anti-Para is wasted");
			std::cout << std::endl;
		}
	}
	else if (nameObject == "Anti-Coward")
	{
		if (monster->getterStateMonster() == state::Hidden)	//'monster' corresponds here to the enemy monster
		{
			monster->setterStateMonster(state::Healthy);

			std::cout << monster->getterNameMonster();
			printLetterByLetter(" is no longer hidden");
			std::cout << std::endl;

		}
		else
		{
			std::cout << monster->getterNameMonster();
			printLetterByLetter(" wasn't hidden ... Anti-Coward is wasted");
			std::cout << std::endl;
		}
	}
}