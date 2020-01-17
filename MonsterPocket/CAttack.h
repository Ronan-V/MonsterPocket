#pragma once
#include <iostream>
class CAttack
{

protected:

	std::string m_nameAttack;
	std::string m_type;
	int m_useNumber;
	int m_power;
	float m_failRate;

public:

	CAttack();
	CAttack(std::string nameAttack, std::string type, int useNumber, int power, float failRate);
	~CAttack();	
	void decrementUseNumber();
	std::string getterType() const;
	int getterPower() const;
	float getterFailRate() const;

};

