#pragma once
#include "FPGA.h"
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

