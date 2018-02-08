#pragma once
#include "CharacterManager.h"

class Games
{
private:
	CharacterManager characterManager;
public:
	Games();
	~Games();

	//General Methods
	void gameLoop(); //Called by start to enter the game loop
	void start(); //Called to start the game
};

