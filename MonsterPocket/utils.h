#pragma once
#include <cstdlib> 
#include <ctime>
#include <iostream>
#include "windows.h"

#include <Mmsystem.h>
#include <mciapi.h>
#pragma comment(lib, "Winmm.lib")

enum class type{
	Fire,
	Grass,
	Plant,
	Insect,
	Rock,
	Electric,
	Water,
	Normal
};

enum class state {
	Burned,
	Poisoned,
	Hidden,
	Paralysed,
	Flooded,
	Healthy
};

double random(double min, double max);
bool randomLowerThan(double min, double max, double limit);
void printLetterByLetter(std::string sentence);