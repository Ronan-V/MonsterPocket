#include "CMonster.h"


CMonster::CMonster()
{

}

CMonster::CMonster(std::string nameMonster, int hp, float speed, int attack, int defense, std::string state, std::string weakness)
{
	m_nameMonster = nameMonster;
	m_hp = hp;
	m_speed = speed;
	m_attack = attack;
	m_defense = defense;
	m_state = state;
	m_weakness = weakness;
}

CMonster::~CMonster()
{
}

// a modifier pour adapter a CMonster
void CMonster::attackMonster(CAttack attack, CMonster *striker, CMonster *target)
{
	std::string targetWeakness = target->m_weakness;
	std::string targetStrenght;
	float advantage;
	float randomNb;

	int strikerType;
	std::cout << "\n" << target->m_weakness << "\n";
	if (attack.getterType() == "Fire") { strikerType = 1; }
	else if (attack.getterType() == "Grass") { strikerType = 2; }
	else if (attack.getterType() == "Rock") { strikerType = 3; }
	else if (attack.getterType() == "Electric") { strikerType = 4; }
	else if (attack.getterType() == "Water") { strikerType = 5; }

	if (targetWeakness == "Fire") { targetStrenght = "Rock"; }
	else if (targetWeakness == "Grass") { targetStrenght = "Electric"; }
	else if (targetWeakness == "Rock") { targetStrenght = "Water"; }
	else if (targetWeakness == "Electric") { targetStrenght = "Fire"; }
	else if (targetWeakness == "Water") { targetStrenght = "Grass"; }


	std::cout << "\n Striker type: "<< strikerType << "\n";

	//a mettre dans une fonction
	switch (strikerType)
	{
	case 1: //Fire
		if (targetStrenght == attack.getterType()) { advantage = 0.5; }
		else if (targetWeakness == attack.getterType()) { advantage = 2; }
		else { advantage = 1; }
		break;
	case 2: //Grass
		if (targetStrenght == attack.getterType()) { advantage = 0.5; }
		else if (targetWeakness == attack.getterType()) { advantage = 2; }
		else { advantage = 1; }
		break;
	case 3: //Rock
		if (targetStrenght == attack.getterType()) { advantage = 0.5; }
		else if (targetWeakness == attack.getterType()) { advantage = 2; }
		else { advantage = 1; }
		break;
	case 4: //Electric
		if (targetStrenght == attack.getterType()) { advantage = 0.5; }
		else if (targetWeakness == attack.getterType()) { advantage = 2; }
		else { advantage = 1; }
		break;
	case 5: //Water
		if (targetStrenght == attack.getterType()) { advantage = 0.5; }
		else if (targetWeakness == attack.getterType()) { advantage = 2; }
		else { advantage = 1; }
		break;
	default:
		advantage = 1;
		break;
	}

	randomNb = random(0.85, 1);
	std::cout << "\nRandom: " << randomNb << "\n";


	int damage = (((11 * striker->m_attack * attack.getterPower()) / target->m_defense * 25 + 2) * advantage * randomNb);
	std::cout << "\n" << damage << "\n";

	//random number between 0 and 1 for the fail
	randomNb = random(0, 1);
	std::cout << "\nFailRate :" << attack.getterFailRate() << "\n";
	if (randomNb < attack.getterFailRate()) { damage = 0; } //attack failed

	target->receiveDamage(damage);
	attack.decrementUseNumber();
}


void CMonster::receiveDamage(int damage)
{
	std::cout << "\nDamage :" << damage << "\n";
	std::cout << "\nNom:" << m_nameMonster << "\n";
	std::cout << "\nHp avant:" << m_hp << "\n";

	m_hp -= damage;
	std::cout << "\nHp apres:" << m_hp << "\n";

}

int CMonster::getterHP()
{
	std::cout << "\nNom:" << m_nameMonster << "\n";
	return m_hp;
}
