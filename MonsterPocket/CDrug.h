#pragma once
#include "CObject.h"
#include "utils.h"
#include "CMonster.h"
class CDrug :
	public CObject
{

protected:


public:

	CDrug();
	CDrug(std::string name, std::string typeOfObject);
	~CDrug();
	void useObject(CMonster* monster, std::string nameObject);
	
};
