#pragma once
#include <string>>
#include "CMonster.h"

class CObject
{
protected:

	std::string m_nameObject;
	std::string m_typeOfObject;


public:

	CObject();
	CObject(std::string nameObject, std::string typeOfObject);
	~CObject();
	virtual void useObject(CMonster* monster, std::string nameObject) = 0;

	std::string getterNameObject();
	std::string getterTypeOfObject();

	void setterNameObject(std::string nameObject);
};