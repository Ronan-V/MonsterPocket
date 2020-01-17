#pragma once
#include <iostream>
#include <vector>

class CPlayer
{
protected:

	//std::vector<CMonster*> l_monster;
	//std::vector<CObject*> l_object;

public:

	CPlayer();
	~CPlayer();

	void attack();
	void useObject();
	void swapMonster();

};
