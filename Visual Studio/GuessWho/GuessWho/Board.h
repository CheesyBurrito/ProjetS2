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
	void initializeCharacterManagerBoard(CharacterManager characterManager1);

	//Setters and Getters
	CharacterManager* get_character_manager() const;
	void set_character_manager(CharacterManager* character_manager);
};

