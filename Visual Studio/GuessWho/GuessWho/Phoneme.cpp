#include "stdafx.h"
#include "Phoneme.h"


Phoneme::Phoneme(int min[4], int max[4], int percentage)
{
	minValue = min;
	maxValue = max;
	detectionPercentage = percentage;
}


Phoneme::~Phoneme()
{
}
