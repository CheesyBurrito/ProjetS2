#include "stdafx.h"
#include "Phoneme.h"


Phoneme::Phoneme(int min[4], int max[4], int percentage)
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
