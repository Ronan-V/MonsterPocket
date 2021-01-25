#include "utils.h"


	
//Returns a random number between 'min' and 'max'
double random(double min, double max)
{
	double randNb;

	srand(time(0));
	rand();
	randNb = (double)rand() / RAND_MAX;
	return min + randNb * (max - min);
}

//Returns a boolean to know if the random number is lower than 'limit'
bool randomLowerThan(double min, double max, double limit)
{
	if (random(min, max) < limit) { return true; }
	else { return false; }
}

void printLetterByLetter(std::string sentence)
{
	int x = 0;
	while (sentence[x] != '\0')
	{
		std::cout << sentence[x];
		Sleep(80);
		x++;
	};
}