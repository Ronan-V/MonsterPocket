#include "CGame.h"

CGame::CGame()
{
	initializationOfTheGame();
}

CGame::~CGame()
{
}

void CGame::initializationOfTheGame()
{
	//***Initialization***

	short nbMonsters = 0;
	short nbAttacks = 0;
	short nbObjects = 0;

	std::string line;
	std::string word;
	short wordshort;
	float wordFloat;

	std::string typeOfGrass;
	std::string nameMonster;
	short hpMin;
	short hpMax;
	short hpMonster;
	float speedMin;
	float speedMax;
	float speedMonster;
	short attackMin;
	short attackMax;
	short attackMonster;
	short defMin;
	short defMax;
	short defenseMonster;
	type typeMonster;
	float specialtyMonster_1;
	float specialtyMonster_2;

	std::string objectName;
	short objectPower;
	std::string objectType;
	std::string drugSpecificity;



	std::vector <CMonster*> arrayMonsters; //Where all the monsters will be added
	std::vector <CObject*> arrayObjects; //Where all the objects will be added
	std::vector <CAttack*> arrayAttacks; //Where all the objects will be added

	//****************Gets the list of attacks and puts it in arrays****************

	//Count the number of attacks in the file
	std::ifstream myFileAttacks("attacks.pkmn");
	if (myFileAttacks.is_open())
	{
		while (std::getline(myFileAttacks, line)) {
			if (line == "EndAttack") { nbAttacks++; }
		}

		myFileAttacks.close();
	}
	else { std::cout << "Error when opening the file attacks.pkm" << std::endl; }

	//Register the information from the file 'attacks.pkmn'
	std::ifstream mySecondFile("attacks.pkmn");
	if (mySecondFile.is_open())
	{
		//Do this for each attack of the file
		for (short i = 0; i < nbAttacks; i++)
		{
			CAttack* attack = new CAttack();
			mySecondFile >> word;
			if (word == "Attack")
			{
				while (word != "EndAttack")
				{
					mySecondFile >> word;
					if (word == "Name")
					{
						mySecondFile >> word;
						attack->setterNameAttack(word);
					}
					else if (word == "Type")
					{
						mySecondFile >> word;
						if (word == "Fire") { attack->setterTypeAttack(type::Fire); }
						else if (word == "Grass") { attack->setterTypeAttack(type::Grass); }
						else if (word == "Rock") { attack->setterTypeAttack(type::Rock); }
						else if (word == "Electric") { attack->setterTypeAttack(type::Electric); }
						else if (word == "Water") { attack->setterTypeAttack(type::Water); }
						else if (word == "Normal") { attack->setterTypeAttack(type::Normal); }
						else { std::cout << "Error when getting the type of the attack." << std::endl; }
					}
					else if (word == "Power")
					{
						mySecondFile >> wordshort;
						attack->setterPowerAttack(wordshort);

					}
					else if (word == "NbUse")
					{
						mySecondFile >> wordshort;
						attack->setterUseNb(wordshort);
					}
					else if (word == "Fail")
					{
						mySecondFile >> wordFloat;
						attack->settterFailRate(wordFloat);

					}
					else if (word == "EndAttack")
					{
						//If we see "EndAttack", do nothing.
					}
					else { std::cout << "Error, unknown word in attacks.pkmn." << word << std::endl; }
				}
			}
			arrayAttacks.push_back(attack);
		}
		mySecondFile.close();
	}
	else { std::cout << "Error when opening the file attacks.pkmn." << std::endl; }


	//****************Gets the list of monsters and puts it in arrays****************

	//Count the number of monsters in the file
	std::ifstream myFileMonsters("monsters.pkmn");
	if (myFileMonsters.is_open())
	{
		while (std::getline(myFileMonsters, line)) {
			if (line == "EndMonster") { nbMonsters++; }
		}
		myFileMonsters.close();
	}
	else { std::cout << "Error when opening the file monsters.pkmn." << std::endl; }

	//Register the information from the file 'monsters.pkmn'
	std::ifstream myFile("monsters.pkmn");
	if (myFile.is_open())
	{
		//Do this for each monster of the file
		for (short i = 0; i < nbMonsters; i++)
		{
			myFile >> word;
			if (word == "Monster")
			{
				while (word != "EndMonster")
				{
					myFile >> word;
					if (word == "Name")
					{
						myFile >> word;
						nameMonster = word;
					}
					else if (word == "Type")
					{
						myFile >> word;
						if (word == "Fire") { typeMonster = type::Fire; }
						else if (word == "Plant"){ typeMonster = type::Plant; }
						else if (word == "Insect") { typeMonster = type::Insect; }
						else if (word == "Rock") { typeMonster = type::Rock; }
						else if (word == "Electric") { typeMonster = type::Electric; }
						else if (word == "Water") { typeMonster = type::Water; }
						else { std::cout << "Error when getting the type of the monster." << std::endl; }
					}
					else if (word == "HP")
					{
						myFile >> wordshort;
						hpMin = wordshort;
						myFile >> wordshort;
						hpMax = wordshort;
						hpMonster = random(hpMin, hpMax);
					}
					else if (word == "Speed")
					{
						myFile >> wordFloat;
						speedMin = wordFloat;
						myFile >> wordFloat;
						speedMax = wordFloat;
						speedMonster = random(speedMin, speedMax);
					}
					else if (word == "Attack")
					{
						myFile >> wordshort;
						attackMin = wordshort;
						myFile >> wordshort;
						attackMax = wordshort;
						attackMonster = random(attackMin, attackMax);
					}
					else if (word == "Defense")
					{
						myFile >> wordshort;
						defMin = wordshort;
						myFile >> wordshort;
						defMax = wordshort;
						defenseMonster = random(defMin, defMax);
					}
					else if (word == "Burn" || word == "Poison" || word == "Heal" || word == "Protect" || word == "Paralysis" || word == "Flood")
					{
						myFile >> wordFloat;
						specialtyMonster_1 = wordFloat;
					}
					else if (word == "Fall")
					{
						myFile >> wordFloat;
						specialtyMonster_2 = wordFloat;
					}
					else if (word == "EndMonster")
					{
						//If we see "EndMonster", do nothing.
					}
					else { std::cout << "Error, unknown word in monsters.pkmn." << word << std::endl; }
				}
			}

			//Creation of the monster depending on its type and fill the array of monsters
			if (typeMonster == type::Fire)
			{
				CFire* fireMonster = new CFire();
				fireMonster->setterNameMonster(nameMonster);
				fireMonster->setterHpMonster(hpMonster);
				fireMonster->setterSpeedMonster(speedMonster);
				fireMonster->setterAttackMonster(attackMonster);
				fireMonster->setterDefenseMonster(defenseMonster);
				fireMonster->setterTypeMonster(type::Fire);
				fireMonster->setterBurn(specialtyMonster_1);
				fireMonster->setterAttacks(arrayAttacks); // Set 4 attacks to the monster.
				arrayMonsters.push_back(fireMonster);
			}
			else if (typeMonster == type::Plant)
			{
				CPlant* plantMonster = new CPlant();
				plantMonster->setterNameMonster(nameMonster);
				plantMonster->setterHpMonster(hpMonster);
				plantMonster->setterSpeedMonster(speedMonster);
				plantMonster->setterAttackMonster(attackMonster);
				plantMonster->setterDefenseMonster(defenseMonster);
				plantMonster->setterTypeMonster(type::Plant);
				plantMonster->setterCure(specialtyMonster_1);
				plantMonster->setterAttacks(arrayAttacks);
				arrayMonsters.push_back(plantMonster);
				typeOfGrass = " ";
			}
			else if (typeMonster == type::Insect)
			{
				CInsect* insectMonster = new CInsect();
				insectMonster->setterNameMonster(nameMonster);
				insectMonster->setterHpMonster(hpMonster);
				insectMonster->setterSpeedMonster(speedMonster);
				insectMonster->setterAttackMonster(attackMonster);
				insectMonster->setterDefenseMonster(defenseMonster);
				insectMonster->setterTypeMonster(type::Insect);
				insectMonster->setterPoison(specialtyMonster_1);
				insectMonster->setterAttacks(arrayAttacks);
				arrayMonsters.push_back(insectMonster);
				typeOfGrass = " "; //resets the 'typeOfGrass' string to not enter the loop each time.

			}
			else if (typeMonster == type::Rock)
			{
				CRock* rockMonster = new CRock();
				rockMonster->setterNameMonster(nameMonster);
				rockMonster->setterHpMonster(hpMonster);
				rockMonster->setterSpeedMonster(speedMonster);
				rockMonster->setterAttackMonster(attackMonster);
				rockMonster->setterDefenseMonster(defenseMonster);
				rockMonster->setterTypeMonster(type::Rock);
				rockMonster->setterHide(specialtyMonster_1);
				rockMonster->setterAttacks(arrayAttacks);
				arrayMonsters.push_back(rockMonster);
			}
			else if (typeMonster == type::Electric)
			{
				CElectric* elecMonster = new CElectric();
				elecMonster->setterNameMonster(nameMonster);
				elecMonster->setterHpMonster(hpMonster);
				elecMonster->setterSpeedMonster(speedMonster);
				elecMonster->setterAttackMonster(attackMonster);
				elecMonster->setterDefenseMonster(defenseMonster);
				elecMonster->setterTypeMonster(type::Electric);
				elecMonster->setterParalyse(specialtyMonster_1);
				elecMonster->setterAttacks(arrayAttacks);
				arrayMonsters.push_back(elecMonster);
			}
			else if (typeMonster == type::Water)
			{
				CWater* waterMonster = new CWater();
				waterMonster->setterNameMonster(nameMonster);
				waterMonster->setterHpMonster(hpMonster);
				waterMonster->setterSpeedMonster(speedMonster);
				waterMonster->setterAttackMonster(attackMonster);
				waterMonster->setterDefenseMonster(defenseMonster);
				waterMonster->setterTypeMonster(type::Water);
				waterMonster->setterFlood(specialtyMonster_1);
				waterMonster->setterFall(specialtyMonster_2);
				waterMonster->setterAttacks(arrayAttacks);
				arrayMonsters.push_back(waterMonster);
			}
		}
		myFile.close();
	}
	else { std::cout << "Error when opening the file monsters.pkmn" << std::endl; }



	//****************Gets the list of objects and puts it in arrays****************

	//Count the number of objects in the file
	std::ifstream myFileObjects("objects.pkmn");
	if (myFileObjects.is_open())
	{
		while (std::getline(myFileObjects, line)) {
			if (line == "EndObject") { nbObjects++; }
		}
		myFileObjects.close();
	}
	else { std::cout << "Error when opening the file objects.pkmn" << std::endl; }

	std::ifstream myThirdFile("objects.pkmn");
	if (myThirdFile.is_open())
	{
		//Do this for each object of the file
		for (short i = 0; i < nbObjects; i++)
		{
			myThirdFile >> word;
			if (word == "Object")
			{
				while (word != "EndObject")
				{
					myThirdFile >> word;
					if (word == "Name")
					{
						myThirdFile >> word;
						objectName = word;
					}
					else if (word == "Power")
					{
						myThirdFile >> wordshort;
						objectPower = wordshort;
					}
					else if (word == "Type")
					{
						myThirdFile >> word;
						objectType = word;
					}
					else if (word == "EndObject")
					{
						//If we see "EndObject", do nothing.
					}
					else { std::cout << "Error, unknown word in objects.pkmn." << word << std::endl; }
				}
			}
			if (objectType == "Potion")
			{
				CPotion* potion = new CPotion(objectName, objectPower, objectType);
				arrayObjects.push_back(potion);
			}
			else if (objectType == "Drug")
			{
				CDrug* drug = new CDrug(objectName, objectType);
				arrayObjects.push_back(drug);
			}
		}
		myThirdFile.close();
	}




	CPlayer* blueTeam = new CPlayer(arrayMonsters, arrayObjects, "Arthur");
	CPlayer* redTeam = new CPlayer(arrayMonsters, arrayObjects, "Ronan");
	l_players.push_back(blueTeam);
	l_players.push_back(redTeam);

	


	//DIALOGUE
	std::string sentence;

	sentence = "\t\t\t\t\t\t";
	sentence += l_players[1]->getterNamePlayer();
	sentence += " wants to fight !";
	printLetterByLetter(sentence);
	std::cout << std::endl << std::endl;

	sentence = l_players[1]->getterNamePlayer();
	sentence += " sends ";
	sentence += redTeam->getterMonstersPlayerArray().at(0)->getterNameMonster();
	sentence += " !";
	printLetterByLetter(sentence);
	std::cout << std::endl;

	sentence = "Let's go ";
	sentence += blueTeam->getterMonstersPlayerArray().at(0)->getterNameMonster();
	sentence += " !";
	printLetterByLetter(sentence);

	std::cout << std::endl;
}

void CGame::gameProgress(std::vector<CPlayer*> l_players)
{
	short whichTurn = 0; // 0 = blue / 1 = red
	short choice;
	short choiceActionPlayer0;
	short choiceActionPlayer1;
	short choiceSecondAction_P0;
	short choiceSecondAction_P1;
	short firstToCheck = 0;
	short secondToCheck = 1;

	//While both players have monsters alive
	while (l_players[0]->getterMonstersPlayerArray().size() != 0 && l_players[1]->getterMonstersPlayerArray().size() != 0)
	{
		Sleep(1500);
		std::cout << std::endl << "******************************************************  New turn  ******************************************************" << std::endl << std::endl;
		Sleep(300);

		/*
			3 turns :
				1: Blue player
				2: Red player
				3: execution of both player's choices
		*/
		whichTurn = 0;
		for (whichTurn = 0; whichTurn < 3; whichTurn++)
		{
			if (whichTurn == 0 || whichTurn == 1)
			{
				if (whichTurn == 1) { system("cls"); }

				std::cout << std::endl << "***************************************************  " << l_players[whichTurn]->getterNamePlayer() << "'s turn  ****************************************************" << std::endl << std::endl;
				Sleep(300);
				std::cout << l_players[0]->getterNamePlayer() << "'s monster " << l_players[0]->getterMonstersPlayerArray().at(0)->getterNameMonster() << " (";
				std::cout << l_players[0]->getterMonstersPlayerArray().at(0)->getterTypeMonsterAsString() << ") is " << l_players[0]->getterMonstersPlayerArray().at(0)->getterStateMonsterAsString() << std::endl;
				std::cout << l_players[1]->getterNamePlayer() << "'s monster " << l_players[1]->getterMonstersPlayerArray().at(0)->getterNameMonster() << " (";
				std::cout << l_players[1]->getterMonstersPlayerArray().at(0)->getterTypeMonsterAsString() << ") is " << l_players[1]->getterMonstersPlayerArray().at(0)->getterStateMonsterAsString() << std::endl << std::endl;

				Sleep(400);
				std::cout << "What do you want to do ?" << std::endl << std::endl;
				std::cout << "\t\t(1) Attack with " << l_players[whichTurn]->getterMonstersPlayerArray().at(0)->getterNameMonster() << "\t\t";
				std::cout << "(2) Use an object" << "\t\t";
				std::cout << "(3) Switch monsters" << std::endl;

				if (whichTurn == 0)
				{
					std::cin >> choiceActionPlayer0; // Save action ( between Attack, Object, and Swap)
					choice = choiceActionPlayer0;
					std::cin.ignore();
				}
				else
				{
					std::cin >> choiceActionPlayer1;
					choice = choiceActionPlayer1;
					std::cin.ignore();
				}


				switch (choice)
				{
				case 1: //Attack
					std::cout << std::endl << "Select your attack:" << std::endl << std::endl;
					//For all the squares on the monster's attacks array
					for (short i = 0; i < l_players[whichTurn]->getterMonstersPlayerArray().at(0)->getterArrayAttacksMonster().size(); i++)
					{
						//Print the attacks of the monster except the one with useNumber = 0
						if (l_players[whichTurn]->getterMonstersPlayerArray().at(0)->getterArrayAttacksMonster().at(0)->getterUseNumber() > 0)
						{
							std::cout << "(" << i << ") " << l_players[whichTurn]->getterMonstersPlayerArray().at(0)->getterArrayAttacksMonster().at(i)->getterNameAttack();
							std::cout << "                   \t" << l_players[whichTurn]->getterMonstersPlayerArray().at(0)->getterArrayAttacksMonster().at(i)->getterTypeAttackAsString();
							std::cout << "\t (" << l_players[whichTurn]->getterMonstersPlayerArray().at(0)->getterArrayAttacksMonster().at(i)->getterUseNumber() << " uses left)" << std::endl;
						}
					}
					//Register the attack chosen
					std::cin >> choice;
					std::cin.ignore();
					break;
				case 2: //Use an object
					std::cout << "Select your object:" << std::endl << std::endl;
					//Print the available objects
					for (short i = 0; i < l_players[whichTurn]->getterObjectsPlayerArray().size(); i++)
					{
						std::cout << "(" << i << ")\t" << l_players[whichTurn]->getterObjectsPlayerArray().at(i)->getterNameObject() << std::endl;

					}
					//Register the object chosen
					std::cin >> choice;
					std::cin.ignore();
					break;
				case 3: //Switch monsters
					std::cout << "Select the monster you want:" << std::endl << std::endl;
					//Print the availabe monsters
					for (short i = 1; i < l_players[whichTurn]->getterMonstersPlayerArray().size(); i++)
					{
						std::cout << "\t" << l_players[whichTurn]->getterMonstersPlayerArray().at(i)->getterNameMonster();
						std::cout << "                   \t" << l_players[whichTurn]->getterMonstersPlayerArray().at(i)->getterTypeMonsterAsString() << "\t(" << i << ")" << std::endl;
					}
					//Register the monster chosen
					std::cin >> choice;
					std::cin.ignore();
					break;
				}
				if (whichTurn == 0) { choiceSecondAction_P0 = choice; } //Save Action Number ( Between 0, 1, 2, 3 ... for the number of object, attack, monster...)
				else { choiceSecondAction_P1 = choice; }
			}

			/**********************************EXECUTION OF THE ACTIONS***********************************************/

			else if (whichTurn == 2) //Executes actions in order of priority
			{
				// Checking states first giving sometimes a little advantage, we alternate who starts
				if (firstToCheck = 1)
				{
					firstToCheck = 0;
					secondToCheck = 1;
				}
				else
				{
					firstToCheck = 1;
					secondToCheck = 0;
				}
				l_players[firstToCheck]->getterMonstersPlayerArray().at(0)->checkStates(l_players[secondToCheck]->getterMonstersPlayerArray().at(0));
				l_players[secondToCheck]->getterMonstersPlayerArray().at(0)->checkStates(l_players[firstToCheck]->getterMonstersPlayerArray().at(0));

				/*
				choiceActionPlayer equals:
					0, if the player wants to change his monster
					1, if the player wants to use an object
					2, if the player wants his monster to attack
				*/

				//If they chose to swap
				if (choiceActionPlayer0 == 3) { l_players[0]->swapMonster(choiceSecondAction_P0); }
				if (choiceActionPlayer1 == 3) { l_players[1]->swapMonster(choiceSecondAction_P1); }

				//If they chose to use an object
				if (choiceActionPlayer0 == 2) { l_players[0]->useObject(choiceSecondAction_P0, l_players[1]); }
				if (choiceActionPlayer1 == 2) { l_players[1]->useObject(choiceSecondAction_P1, l_players[0]); }

				//If they chose to attack (the order is chosen by the monsters' speed)
				//If player 0's monster is faster, he attacks first
				if (l_players[0]->getterMonstersPlayerArray().at(0)->getterSpeedMonster() > l_players[1]->getterMonstersPlayerArray().at(0)->getterSpeedMonster())
				{
					if (choiceActionPlayer0 == 1) { l_players[0]->attack(choiceSecondAction_P0, l_players[1]); }
					if (choiceActionPlayer1 == 1) { l_players[1]->attack(choiceSecondAction_P0, l_players[0]); }
				}
				//If player 1's monster is faster, he attacks first
				if (l_players[1]->getterMonstersPlayerArray().at(0)->getterSpeedMonster() >= l_players[0]->getterMonstersPlayerArray().at(0)->getterSpeedMonster())
				{
					if (choiceActionPlayer1 == 1) { l_players[1]->attack(choiceSecondAction_P0, l_players[0]); }
					if (choiceActionPlayer0 == 1) { l_players[0]->attack(choiceSecondAction_P0, l_players[1]); }
				}
			}
			l_players[0]->getterMonstersPlayerArray().at(0)->setternbTurnUnderState(1);	 //Add 1 to the number under the actual state
			l_players[1]->getterMonstersPlayerArray().at(0)->setternbTurnUnderState(1);
		}
	}

	std::string sentence;
	if (l_players[0]->getterMonstersPlayerArray().size() == 0)
	{
		sentence = "Congratulations !!!\n";
		sentence += l_players[1]->getterNamePlayer();
		sentence += " won the fight\n";
		sentence += l_players[1]->getterMonstersPlayerArray().at(0)->getterNameMonster();
		sentence += " is dancing for the victory";
	}
	else
	{
		sentence = "Congratulations !!!\n";
		sentence += l_players[0]->getterNamePlayer();
		sentence += " won the fight";
		sentence += l_players[0]->getterMonstersPlayerArray().at(0)->getterNameMonster();
		sentence += " is dancing for the victory";
	}
}


std::vector<CPlayer*> CGame::getterPlayersArray()
{
	return l_players;
}