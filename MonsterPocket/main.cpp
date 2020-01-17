#include "CAttack.h"
#include "CWater.h"
#include "CFire.h"
#include <iostream>


int main(int argc, char** argv)
{
	CWater *carapuce = new CWater("Carapuce", 45000, 1.5, 80, 80, "normal", "Grass",0.20,0.33);
	CFire *salameche = new CFire("Salameche", 50000, 1.5, 80, 80, "normal", "Water", 0.25);
	CAttack bulleDeau("Bulle d'eau", "Water", 10, 50, 0.15);
	std::cout << "Avant attaque: " << salameche->getterHP();

	carapuce->attackMonster(bulleDeau, carapuce, salameche);

	std::cout << "Après attaque: " << salameche->getterHP();

}
