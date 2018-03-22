// GuessWho.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Games.h"
#include "Demo.h"
#include "FPGA.h"

int main()
{
	/*
	int min[4] = { 3,5,1,2 };
	int max[4] = { 5,8,3,5 };
	int testData[10][4] = {
	{4,6,2,3},
	{ 4,6,2,3 },
	{ 4,6,2,3 },
	{ 4,6,2,3 },
	{ 4,6,2,3 },
	{ 4,6,2,3 },
	{ 5,6,2,3 },
	{ 3,6,2,3 },
	{ 2,6,2,3 },
	{ 2,6,2,3 },
	};

	Phoneme testP(min, max, 0.75);
	cout << testP.isPhoneme(testData) << endl;
	*/
	//FPGA test;
	//test.readLoop();

	Games game;
	game.start();
	
	//Demo acts as a debug menu
	//Demo demo;
	//demo.start();

	
    return 0;
}

