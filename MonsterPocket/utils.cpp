#include "utils.h"

double random(double min, double max)
{
	srand(time(NULL));
	//float randNb = min + (max - min) * rand() / ((double)RAND_MAX);
	
	//float randNb = rand()%max+min
	//return randNb /= 100;

	double randNb = (double)rand() / RAND_MAX;
	return min + randNb * (max - min);

}