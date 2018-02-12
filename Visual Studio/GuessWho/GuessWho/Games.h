#pragma once
#include "CharacterManager.h"
#include "Board.h"

class Games
{
private:
	CharacterManager characterManager;
	Board boardPlayer1;
	Board boardPlayer2;
public:
	Games();
	~Games();

	//General Methods
	void gameLoop(); //Called by start to enter the game loop
	void start(); //Called to start the game
};

