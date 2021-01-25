#pragma once
#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstdlib>
#include "CPlayer.h"
#include "CAttack.h"
#include "CWater.h"
#include "CFire.h"
#include "CElectric.h"
#include "CInsect.h"
#include "CPlant.h"
#include "CRock.h"
#include "utils.h"

//enlever object
#include "CObject.h"
#include "CDrug.h"
#include "CPotion.h"


class CGame
{

protected:

	std::vector<CPlayer*> l_players;
	bool m_floodedGround;


public:

	CGame();
	~CGame();
	void initializationOfTheGame();
	void gameProgress(std::vector<CPlayer*> l_players);

	std::vector<CPlayer*> getterPlayersArray();

};