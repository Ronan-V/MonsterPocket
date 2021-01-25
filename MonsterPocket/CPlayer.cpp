#include "CPlayer.h"
CPlayer::CPlayer()
{

}

CPlayer::CPlayer(std::vector<CMonster*> l_tabMonsters, std::vector<CObject*> l_tabObjects, std::string name)
{
	m_namePlayer = name;

	random_shuffle(l_tabMonsters.begin(), l_tabMonsters.end());
	random_shuffle(l_tabObjects.begin(), l_tabObjects.end());
	for (short i = 0; i < 3; i++) { l_monstersPlayer.push_back(l_tabMonsters[i]); } //Gives 3 monsters to the player
	for (short i = 0; i < 5; i++) { l_objectsPlayer.push_back(l_tabObjects[i]); } //Gives 5 objects to the player
}

CPlayer::~CPlayer()
{
}

void CPlayer::attack(short choice, CPlayer* targetPlayer)
{

	//Attack the first monster of 'targetPlayer'
	l_monstersPlayer[0]->attackMonster(l_monstersPlayer[0]->getterArrayAttacksMonster().at(choice), targetPlayer->getterMonstersPlayerArray().at(0));

	//If target's HP are lower than 0
	if (targetPlayer->getterMonstersPlayerArray().at(0)->getterHpMonster() <= 0)
	{
		std::cout << "/!\/!\/!\ " << targetPlayer->getterMonstersPlayerArray().at(0)->getterNameMonster() << " is beaten /!\ /!\ /!\ " << std::endl << std::endl;
		targetPlayer->swapMonster(targetPlayer->getterMonstersPlayerArray().size()); //Change the monster who's fighting. (The array is starting to 0, that's why we substract 1 after size() )
		targetPlayer->killMonster(); //Delete the dead monster from the array

	}

	//Check if there is an attack with a useNumber at 0
	for (short i = 0; i < l_monstersPlayer.size() - 1; i++)
	{
		if (l_monstersPlayer[0]->getterArrayAttacksMonster().at(i)->getterUseNumber() == 0)
		{
			l_monstersPlayer[0]->getterArrayAttacksMonster().at(i) = 0;
		}
	}
}

void CPlayer::useObject(short choice, CPlayer* enemyPlayer)
{
	short monsterChoice;

	if (l_objectsPlayer[choice]->getterTypeOfObject() == "Potion")
	{
		std::cout << m_namePlayer << " which monster do you want to give the potion to ?" << std::endl << std::endl;
		for (short i = 0; i < l_monstersPlayer.size(); i++)
		{
			std::cout << "(" << i << ")" << l_monstersPlayer[i]->getterNameMonster() << std::endl;
		}
		std::cin >> monsterChoice;
		std::cin.ignore();
		l_objectsPlayer[choice]->useObject(l_monstersPlayer[monsterChoice], l_objectsPlayer[choice]->getterNameObject());
		std::cout << std::endl;
	}
	else if (l_objectsPlayer[choice]->getterTypeOfObject() == "Drug")
	{
		//If the drug has to affect an enemy instead of our monster
		if (l_objectsPlayer[choice]->getterNameObject() == "Sponge" || l_objectsPlayer[choice]->getterNameObject() == "Anti-Coward")
		{
			l_objectsPlayer[choice]->useObject(enemyPlayer->getterMonstersPlayerArray().at(0), l_objectsPlayer[choice]->getterNameObject());
		}
		else
		{
			l_objectsPlayer[choice]->useObject(l_monstersPlayer[0], l_objectsPlayer[choice]->getterNameObject());
		}
	}
}

void CPlayer::swapMonster(short choice)
{

	//Swap the monster actually used (the one at 0) with the one chosen
	l_monstersPlayer.push_back(l_monstersPlayer.at(0)); //Create a temporary element in the array to exchange the two mosnters
	l_monstersPlayer[0] = l_monstersPlayer.at(choice);
	l_monstersPlayer[choice] = l_monstersPlayer.at(l_monstersPlayer.size()-1); //The array is starting to 0, that's why we substract 1 after size()
	l_monstersPlayer.pop_back(); //Erase the temporary element
	std::cout << l_monstersPlayer[0]->getterNameMonster(); 
	printLetterByLetter(" is ready to fight");
	std::cout << std::endl;
}

std::vector<CMonster*> CPlayer::getterMonstersPlayerArray()
{
	return l_monstersPlayer;
}

std::vector<CObject*> CPlayer::getterObjectsPlayerArray()
{
	return l_objectsPlayer;
}

std::string CPlayer::getterNamePlayer()
{
	return m_namePlayer;
}

void CPlayer::killMonster()
{
	l_monstersPlayer.pop_back();
}
