#pragma once

#include "CAttack.h"

#include <vector>
#include <algorithm>



class CMonster
{
protected:

	std::string m_nameMonster;
	short m_hp;
	float m_speed;
	short m_attack;
	short m_defense;
	state m_state;
	type m_type;
	std::vector<CAttack*> l_attacksMonster;
	short m_nbTurnUnderState;
	short m_nbTurnState;
	short m_maxHP;

public:

	CMonster();
	~CMonster();
	void handAttack(CMonster* target);
	void receiveDamages(short damages);
	virtual void attackMonster(CAttack* attack, CMonster* target) = 0;
	float getAdvantage(type typeAttack) const; //Used when we attack to know if it is efficient or not
	void checkStates(CMonster* enemyMonster);
	virtual float getterFallMonster();

	void giveHpMonster(short hp);
	void giveAttackMonster(short attack);
	void giveDefenseMonster(short defense);
	void giveSpeedMonster(float speed);


	std::string getterNameMonster() const;
	short getterHpMonster();
	state getterStateMonster() const;
	std::string getterStateMonsterAsString();
	float getterSpeedMonster() const;
	short getterAttackMonster() const;
	short getterDefenseMonster() const;
	type getterTypeMonster() const;
	std::string getterTypeMonsterAsString() const;
	std::vector<CAttack*> getterArrayAttacksMonster() const;
	short getterMaxHpMonster() const;


	void setterNameMonster(std::string nameMonster);
	void setterHpMonster(short hp);
	void setterSpeedMonster(float speed);
	void setterAttackMonster(short attack);
	void setterDefenseMonster(short defense);
	void setterStateMonster(state state);
	void setterTypeMonster(type type);
	void setterAttacks(std::vector<CAttack*> arrayAttacks);
	void setternbTurnUnderState(short nbTurn);
};