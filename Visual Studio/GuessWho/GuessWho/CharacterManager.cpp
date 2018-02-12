#include "stdafx.h"
#include "CharacterManager.h"


CharacterManager::CharacterManager()
{
	generateCharacters();
}


CharacterManager::~CharacterManager()
{
}

bool CharacterManager::generateCharacters()
{
	for(int i = 0; i < 10; i++)
	{
		characterVector.push_back(new Character(i, propertiesEyesIndex[rand() % 3], propertiesHairColorIndex[rand() % 5], propertiesHairPhysiqueIndex[rand() % 2], propertiesGender[rand() % 1], propertiesSkinColorIndex[rand() % 2], propertiesAccessoriesIndex[rand() % 4], propertiesFacialHairIndex[rand() % 3], propertiesAgeIndex[rand() % 1], "William"));
	}
	
	return true;
}

void CharacterManager::printProperties()
{
	for(int i = 0; i < characterVector.size(); i++)
	{
		characterVector.at(i) -> printProperties();
	}
}

bool CharacterManager::exportCharacters(string path)
{
	for (int i = 0; i < characterVector.size(); i++)
	{
		if (characterVector.at(i)->exportCharacter(path) == false)
			return false;
	}

	return true;
}

bool CharacterManager::is_is_shuffle() const
{
	return isShuffle;
}

void CharacterManager::set_is_shuffle(bool is_shuffle)
{
	isShuffle = is_shuffle;
}

bool CharacterManager::is_is_loaded() const
{
	return isLoaded;
}

void CharacterManager::set_is_loaded(bool is_loaded)
{
	isLoaded = is_loaded;
}

int CharacterManager::get_num_character_hidden() const
{
	return numCharacterHidden;
}

void CharacterManager::set_num_character_hidden(int num_character_hidden)
{
	numCharacterHidden = num_character_hidden;
}

int CharacterManager::get_total_character() const
{
	return totalCharacter;
}

void CharacterManager::set_total_character(int total_character)
{
	totalCharacter = total_character;
}
