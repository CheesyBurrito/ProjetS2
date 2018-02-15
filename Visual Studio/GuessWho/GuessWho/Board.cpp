#include "stdafx.h"
#include "Board.h"


Board::Board()
{
}

Board::Board(CharacterManager& characterManager1, Player& playerBoard1)
{
	characterManager = &characterManager1;
	playerOfBoard = &playerBoard1;
}


Board::~Board()
{
}
