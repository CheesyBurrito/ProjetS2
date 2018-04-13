/****************************************
GuessWho ProjetS2 - APP7Gi

P14
William Adam-Grenier - adaw2602
Charles Quesnel - quec2502
Maxime St-Onge - stom2105

Avril 2018

Phoneme.h
*****************************************/

#pragma once
#include "stdafx.h"

class Phoneme
{
private:
	int minValue[4];
	int maxValue[4];
	float detectionPercentage;

public:
	bool isPhoneme(int data[READINGS_PER_BURST][4]);
	Phoneme(int min[4], int max[4], float percentage);
	~Phoneme();
};

