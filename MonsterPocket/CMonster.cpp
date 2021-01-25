#include "CMonster.h"

//Constructor
CMonster::CMonster()
{
	m_nameMonster = "";				//Name of the monster
	m_hp = 100;						//HPs of the monster
	m_speed = 100;					//Speed of the monster
	m_attack = 100;					//Attack points of the monster
	m_defense = 100;				//Defense points of the monster
	m_state = state::Healthy;		//State of the monster (Burned, Paralysed, ...)
	m_type = type::Normal;			//Type of the monster (Fire, Water, ...)
	m_nbTurnUnderState = 0;			//Number of turns under a state
	m_nbTurnState = 0;				//Number of turns the actual state lasts
	m_maxHP = m_hp;					//Maximum HPs of the monster
}

//Destructor
CMonster::~CMonster()
{
}

void CMonster::handAttack(CMonster* target)
{
	// A CODER
}

void CMonster::receiveDamages(short damages)
{
	
	std::string sentence;
	sentence += m_nameMonster;
	sentence += " receives ";
	printLetterByLetter(sentence);
	std::cout << damages;
	sentence = " damages";
	printLetterByLetter(sentence);
	std::cout << std::endl << std::endl;

	m_hp -= damages;

	if (m_hp > 0)
	{
		sentence = m_nameMonster;
		sentence += " has now ";
		printLetterByLetter(sentence);
		std::cout << m_hp;

		sentence = " HPs";
		printLetterByLetter(sentence);
		std::cout << std::endl << std::endl;
	}

}

float CMonster::getAdvantage(type typeAttack) const
{
	type targetWeakness;
	type targetStrenght;
	float advantage;

	if (m_type == type::Fire) {
		targetWeakness = type::Water;
		targetStrenght = type::Grass;
	}
	else if (m_type == type::Plant || m_type == type::Insect) {
		targetWeakness = type::Fire;
		targetStrenght = type::Rock;
	}
	else if (m_type == type::Rock) {
		targetWeakness = type::Grass;
		targetStrenght = type::Electric;
	}
	else if (m_type == type::Electric) {
		targetWeakness = type::Rock;
		targetStrenght = type::Water;
	}
	else if (m_type == type::Water) {
		targetWeakness = type::Electric;
		targetStrenght = type::Fire;
	}

	//Match the type of the attack with the target's strenght and weakness
	if (typeAttack == targetStrenght)
	{
		advantage = 0.5;
		std::string sentence;
		sentence = "\t\t\t\t\t\t";
		sentence += " This not very effective ...";
		printLetterByLetter(sentence);
		std::cout << std::endl << std::endl;
	}
	else if (typeAttack == targetWeakness)
	{
		advantage = 2;
		std::string sentence;
		sentence = "\t\t\t\t\t\t";
		sentence += " This is super effective !";
		printLetterByLetter(sentence);
		std::cout << std::endl << std::endl;
	}
	else { advantage = 1; }
	return advantage;
}

void CMonster::checkStates(CMonster* enemyMonster)
{
	if (m_state == state::Burned)
	{
		if ( enemyMonster->m_state == state::Flooded)	 //If the ground is flooded, the monster is no longer burned
		{
			m_state == state::Healthy;
			m_nbTurnUnderState = 0;

			std::string sentence;
			sentence = "\t\t\t\t\t\t";
			sentence += m_nameMonster;
			sentence += " is no longer burned !";
			printLetterByLetter(sentence);
			std::cout << std::endl << std::endl;
		}
		else
		{	//If not healed
			m_attack -= m_attack / 10;	//Substact a tenth of its actual attack
		}
	}
	else if (m_state == state::Poisoned)
	{
		if (enemyMonster->m_state == state::Flooded)	//If the ground is flooded, the monster is no longer poisoned
		{
			m_state == state::Healthy;
			m_nbTurnUnderState = 0;

			std::cout << m_nameMonster; 
			printLetterByLetter(" is no longer poisoned");
			std::cout << std::endl;
		}
		else
		{	//If not healed
			m_hp -= enemyMonster->m_attack / 10;	//Substact a tenth of its actu
		}
	}
	else if (m_state == state::Hidden)
	{
		if (m_nbTurnUnderState == m_nbTurnState)
		{
			m_state = state::Healthy;
			m_nbTurnUnderState = 0;
			std::cout << m_nameMonster;
			printLetterByLetter(" came out of his hole");
			std::cout << std::endl;
		}
	}
	else if (m_state == state::Paralysed)
	{
		//Probability to go out of paralysis : number of turn under paralysis divided by 6
		if (randomLowerThan(0, 1, m_nbTurnUnderState / 6))
		{
			m_state = state::Healthy;
			m_nbTurnUnderState = 0;
			std::cout << m_nameMonster;
			printLetterByLetter(" is no longer paralysed");
			std::cout << std::endl;
		}
	}
	else if (m_state == state::Flooded)
	{
		if (m_nbTurnUnderState == m_nbTurnState)
		{
			m_state = state::Healthy;
			m_nbTurnUnderState = 0;
			printLetterByLetter("The ground has dried");
			std::cout << std::endl;
		}
	}
}

float CMonster::getterFallMonster()
{
	return 0;
}

void CMonster::giveHpMonster(short hp)
{
	m_hp += hp;
	std::cout << m_nameMonster;
	printLetterByLetter(" receives ");
	std::cout << hp;
	printLetterByLetter(" HPs");
	std::cout << std::endl;
	if (m_hp > m_maxHP) 
	{ 
		m_hp = m_maxHP;
		printLetterByLetter("Max HPs reached");
		std::cout << std::endl;
	} //Not to go beyond 'm_maxHP'
	std::cout << m_nameMonster;
	printLetterByLetter(" HPs are now at ");
	std::cout << m_hp << std::endl;
}

void CMonster::giveAttackMonster(short attack)
{
	m_attack += attack;
	std::cout << std::endl << m_nameMonster;
	printLetterByLetter(" receives ");
	std::cout << attack;
	printLetterByLetter(" attack points");
	std::cout << std::endl << std::endl;
	printLetterByLetter(" attack is now at ");
	std::cout << m_attack << std::endl;
}

void CMonster::giveDefenseMonster(short defense)
{
	m_defense += defense;
	std::cout << m_nameMonster;
	printLetterByLetter(" receives ");
	std::cout << defense;
	printLetterByLetter(" defense points");
	std::cout << std::endl << std::endl;
	std::cout << m_nameMonster; 
	printLetterByLetter(" defense is now at "); 
	std::cout << m_defense << std::endl;
}

void CMonster::giveSpeedMonster(float speed)
{
	m_speed += speed;
	std::cout << m_nameMonster;
	printLetterByLetter(" receives ");
	std::cout << speed;
	printLetterByLetter(" speed points");
	std::cout << std::endl << std::endl;
	std::cout << m_nameMonster;
	printLetterByLetter(" speed is now at ");
	std::cout << m_speed << std::endl;
}

std::string CMonster::getterNameMonster() const
{
	return m_nameMonster;
}


short CMonster::getterHpMonster()
{
	return m_hp;
}

state CMonster::getterStateMonster() const
{
	return m_state;
}

std::string CMonster::getterStateMonsterAsString()
{
	std::string state;
	switch (m_state)
	{
	case state::Burned:
		state = "burned";
		break;
	case state::Poisoned:
		state = "poisoned";
		break;
	case state::Hidden:
		state = "hidden";
		break;
	case state::Paralysed:
		state = "paralysed";
		break;
	case state::Flooded:
		state = "flooding the ground";
		break;
	case state::Healthy:
		state = "healthy";
		break;
	default:
		break;
	}
	return state;
}

float CMonster::getterSpeedMonster() const
{
	return m_speed;
}

short CMonster::getterAttackMonster() const
{
	return m_attack;
}
short CMonster::getterDefenseMonster() const
{
	return m_defense;
}

type CMonster::getterTypeMonster() const
{
	return m_type;
}

std::string CMonster::getterTypeMonsterAsString() const
{
	std::string typeMonster;

	switch (m_type)
	{
	case type::Fire:
		typeMonster = "Fire";
		break;
	case type::Grass:
		typeMonster = "Grass";
		break;
	case type::Plant:
		typeMonster = "Plant";
		break;
	case type::Insect:
		typeMonster = "Insect";
		break;
	case type::Rock:
		typeMonster = "Rock";
		break;
	case type::Electric:
		typeMonster = "Electric";
		break;
	case type::Water:
		typeMonster = "Water";
		break;
	case type::Normal:
		typeMonster = "Normal";
		break;
	}
	return typeMonster;
}

std::vector<CAttack*> CMonster::getterArrayAttacksMonster() const
{
	return l_attacksMonster;
}


short CMonster::getterMaxHpMonster() const
{
	return m_maxHP;
}


void CMonster::setterNameMonster(std::string nameMonster)
{
	m_nameMonster = nameMonster;
}

void CMonster::setterHpMonster(short hp)
{
	m_hp = hp;
	m_maxHP = m_hp;		//Set the monster's max_hp when m_hp is initialized
}

void CMonster::setterSpeedMonster(float speed)
{
	m_speed = speed;
}

void CMonster::setterAttackMonster(short attack)
{
	m_attack = attack;
}

void CMonster::setterDefenseMonster(short defense)
{
	m_defense = defense;
}

void CMonster::setterStateMonster(state state)
{
	m_state = state;
}

void CMonster::setterTypeMonster(type type)
{
	m_type = type;
}

void CMonster::setterAttacks(std::vector<CAttack*> arrayAttacks)
{
	short i = 0;
	
	random_shuffle(arrayAttacks.begin(), arrayAttacks.end());	// mixes the order of the elements in the array

	while(l_attacksMonster.size() < 4)
	{
		if (arrayAttacks.at(i)->getterTypeAttack() == m_type || arrayAttacks.at(i)->getterTypeAttack() == type::Normal)
		{
			CAttack* attack = new CAttack(*(arrayAttacks.at(i)));
			l_attacksMonster.push_back(attack);
		}
		i++;
	}
}

void CMonster::setternbTurnUnderState(short nbTurn)
{
	if (nbTurn == 0) { m_nbTurnUnderState = 0; }	//If we receive 0, set the number of turn under the state to 0
	else { m_nbTurnUnderState += nbTurn; } //Else, add 'nbTurn' to this number (always 1 for now)
}
