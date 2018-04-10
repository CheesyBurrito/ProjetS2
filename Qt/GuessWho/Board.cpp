#include "stdafx.h"
#include "Board.h"


Board::Board()
{
}

Board::Board(CharacterManager& characterManager1)
{
	characterManager = &characterManager1;
}


Board::~Board()
{
}

void Board::initializeCharacterManagerBoard(CharacterManager characterManager1, string path)
{
	//This first loads all of the same characters as the original characterManager
	characterManager->importCharacters(path);
	//The sorting will not be necessary as once the characterManager is shuffled, it exports it self
	/*
	//Then it applies the same order of the original character manger
	for(int i = 0; i < characterManager->get_character_vector().size(); i++)
	{
		for (int k = 0; i < characterManager->get_character_vector().size(); k++)
		{
			if(characterManager1.get_character_vector().at(i)->get_id() == characterManager->get_character_vector().at(k)->get_id())
			{
				//swap
				Character *tempCharacter = characterManager->get_character_vector().at(i);
				characterManager->get_character_vector().insert(characterManager->get_character_vector().begin() + i, characterManager->get_character_vector().at(k));
				characterManager->get_character_vector().insert(characterManager->get_character_vector().begin() + k, tempCharacter);
			}
		}
	}
	*/
}


CharacterManager* Board::get_character_manager() const
{
	return characterManager;
}

void Board::set_character_manager(CharacterManager* character_manager)
{
	characterManager = character_manager;
}
