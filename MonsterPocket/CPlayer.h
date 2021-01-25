#pragma once
#include <iostream>
#include <vector>
#include <string>>
#include <algorithm>
#include "CMonster.h"
#include "CObject.h"

class CPlayer
{
protected:

	std::vector<CMonster*> l_monstersPlayer;
	std::vector<CObject*> l_objectsPlayer;
	std::string m_namePlayer;

public:

	CPlayer();
	CPlayer(std::vector<CMonster*> l_tabMonster, std::vector <CObject*> l_tabOjects, std::string name);
	~CPlayer();

	void attack(short choice, CPlayer* targetPlayer);
	void useObject(short choice, CPlayer* enemyPlayer);
	void swapMonster(short choice);

	std::vector<CMonster*> getterMonstersPlayerArray();
	std::vector<CObject*> getterObjectsPlayerArray();
	std::string getterNamePlayer();

	void killMonster();
};
