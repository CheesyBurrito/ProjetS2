#include "stdafx.h"
#include "CharacterManager.h"


CharacterManager::CharacterManager()
{
	//generateCharacters();
}


CharacterManager::~CharacterManager()
{
}


void CharacterManager::addCharacter(Character *c)
{
	characterVector.push_back(c);
}

//Has to be updated to implement the use of vector based accessories indexing
bool CharacterManager::generateCharacters()
{
	for(int i = 0; i < 10; i++)
	{
		//characterVector.push_back(new Character(i, propertiesEyesIndex[rand() % 3], propertiesHairColorIndex[rand() % 5], propertiesHairPhysiqueIndex[rand() % 2], propertiesGender[rand() % 1], propertiesSkinColorIndex[rand() % 2], propertiesAccessoriesIndex[rand() % 4], propertiesFacialHairIndex[rand() % 3], propertiesAgeIndex[rand() % 1], "William"));
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
	ofstream file(path + "characterList.txt"); //Exports a list containing all files (used when importing characters)

	if (file.is_open()) {

		for (int i = 0; i < characterVector.size(); i++)
		{
			if (characterVector.at(i)->exportCharacter(path) == false)
				return false;
			file << characterVector.at(i)->get_id() << endl;
		}

		file.close();

		return true;
	}

	return false;
}

bool CharacterManager::importCharacters(string path) 
{
	ifstream file(path + "characterList.txt");

	vector<string> characterIDs;
	int i = 0;
	string currentID;

	if (file.is_open()) {

		while (getline(file, currentID)) { //Loads IDs from file
			characterIDs.push_back(currentID); 
			i++;
		}

		file.close();

		for (int j = 0; j < i; j++) { //Creates characters for each loaded ID
			characterVector.push_back(new Character(path + characterIDs[j] + ".txt"));
		}

		return true;
	}

	return false;
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
