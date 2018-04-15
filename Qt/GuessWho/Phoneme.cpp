/****************************************
GuessWho ProjetS2 - APP7Gi

P14
William Adam-Grenier - adaw2602
Charles Quesnel - quec2502
Maxime St-Onge - stom2105

Avril 2018

Phoneme.cpp
*****************************************/

#include "stdafx.h"
#include "Phoneme.h"


Phoneme::Phoneme(int min[4], int max[4], float percentage)
{
	for (int i = 0; i < 4; i++) {
		minValue[i] = min[i];
		maxValue[i] = max[i];
	}
	detectionPercentage = percentage;
}

Phoneme::~Phoneme()
{
}

bool Phoneme::isPhoneme(int data[READINGS_PER_BURST][4]) {
	bool validTable[READINGS_PER_BURST][4];

	//Checks every value to determine if in valid range
	for (int i = 0; i < READINGS_PER_BURST; i++) {
		for (int j = 0; j < 4; j++) {

			if (data[i][j] >= minValue[j] && data[i][j] <= maxValue[j]) 
				validTable[i][j] = true;
			else
				validTable[i][j] = false;

		}
	}

	for (int i = 0; i < 4; i++) {

		//Counts the number of trues in the table that was just created
		int nbTrue = 0;
		for (int j = 0; j < READINGS_PER_BURST; j++)
			if (validTable[j][i]) nbTrue++;

		//When a channel doesn't meet the percentage minimum, the phoneme is not detected
		if ((float)nbTrue / READINGS_PER_BURST < detectionPercentage)
			return false;
	}

	//If false hasn't been returned, every channel must meet the requierment
	return true;
}