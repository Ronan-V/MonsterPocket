#pragma once
#include <string>
#include <iostream>
#include <string>
#include <vector>

#include "utils.h"
#include "CAttack.h"

class CMonster
{
protected:

	std::string m_nameMonster;
	int m_hp;
	float m_speed;
	int m_attack;
	int m_defense;
	std::string m_state;
	std::string m_weakness;

public:

	CMonster();
	CMonster(std::string nameMonster, int hp, float speed, int attack, int defense, std::string state, std::string weakness);
	~CMonster();
	void attackMonster(CAttack attack, CMonster *striker, CMonster *target);
	void receiveDamage(int damage);
	int getterHP();

};