#pragma once
#include <iostream>
#include "utils.h"

class CAttack
{

protected:

	std::string m_nameAttack;
	type m_typeAttack;
	short m_useNumber;
	short m_power;
	float m_failRate;

public:

	CAttack();
	CAttack(std::string nameAttack, type typeAttack, short useNumber, short power, float failRate);
	~CAttack();	
	void decrementUseNumber();

	std::string getterNameAttack() const;
	type getterTypeAttack() const;
	std::string getterTypeAttackAsString() const;
	short getterUseNumber() const;
	short getterPower() const;
	float getterFailRate() const;

	void setterNameAttack(std::string nameAttack);
	void setterTypeAttack(type typeAttack);
	void setterUseNb(short useNb);
	void setterPowerAttack(short power);
	void settterFailRate(float failRate);


};

