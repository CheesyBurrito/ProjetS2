/****************************************
GuessWho ProjetS2 - APP7Gi

P14
William Adam-Grenier - adaw2602
Charles Quesnel - quec2502
Maxime St-Onge - stom2105

Avril 2018

Board.h
*****************************************/

#pragma once
#include "CharacterManager.h"


class Board
{
private:
	CharacterManager * characterManager = new CharacterManager();
public:
	Board();
	Board(CharacterManager &characterManager1);
	~Board();

	//General methods
	void initializeCharacterManagerBoard(CharacterManager characterManager1, string path);

	//Setters and Getters
	CharacterManager* get_character_manager() const;
	void set_character_manager(CharacterManager* character_manager);
};

