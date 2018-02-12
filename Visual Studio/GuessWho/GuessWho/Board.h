#pragma once
#include "CharacterManager.h"
#include "Player.h"

class Board
{
private:
	CharacterManager *characterManager = new CharacterManager;
	Player *playerOfBoard;
public:
	Board();
	~Board();
};

