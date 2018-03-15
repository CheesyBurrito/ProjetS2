#pragma once
#include "FPGA.h"

class Phoneme
{
private:
	int minValue[4];
	int maxValue[4];
	int detectionPercentage;

public:
	bool isPhoneme(int data[READINGS_PER_BURST][4]);
	Phoneme(int min[4], int max[4], int percentage);
	~Phoneme();
};

