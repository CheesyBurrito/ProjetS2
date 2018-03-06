#include "stdafx.h"
#include "CharacterManager.h"
#include <algorithm>


CharacterManager::CharacterManager()
{
	//generateCharacters();
}


CharacterManager::~CharacterManager()
{
}


string CharacterManager::addCharacter(Character *c)
{
	for(int i = 0; i < characterVector.size(); i++)
	{
		if(c->get_id() == characterVector.at(i)->get_id())
		{
			return "Character already present in the manager, it was not added a second time";
		}
		else
		{
			continue;
		}
	}
	characterVector.push_back(c);

	return "Character successfully added";
}

//Has to be updated to implement the use of vector based accessories indexing COMPLETED
bool CharacterManager::generateCharacters()
{
	for(int i = 0; i < 20; i++)
	{
		vector<int> generateAttribute;
		int numAccessoryRand = rand() % 4;
		if(numAccessoryRand == 0)
		{
			generateAttribute.push_back(propertiesAccessoriesIndex[0]);
		}
		for (int k = 0; k < numAccessoryRand; k++)
		{
			generateAttribute.push_back(propertiesAccessoriesIndex[ 1 + rand() % 3]);
		}
		characterVector.push_back(new Character(i, propertiesEyesIndex[rand() % 3], propertiesHairColorIndex[rand() % 5], propertiesHairPhysiqueIndex[rand() % 2], propertiesGender[rand() % 1], propertiesSkinColorIndex[rand() % 2], generateAttribute, propertiesFacialHairIndex[rand() % 3], propertiesAgeIndex[rand() % 1], "William"));
	}
	isLoaded = true;
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
	pathToFile = path;
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
			cout << addCharacter(new Character(path + characterIDs[j] + ".txt")) << endl;
		}
		isLoaded = true;
		return true;
	}
	isLoaded = false;
	return false;
}

void CharacterManager::clearCharacterVector()
{
	characterVector.clear();
}

void CharacterManager::shuffleCharacters()
{
	isShuffle = true;
	random_shuffle(characterVector.begin(), characterVector.end());
}

bool CharacterManager::smartCharacterCreation()
{
	
}


vector<Character*> CharacterManager::get_character_vector() const
{
	return characterVector;
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

string CharacterManager::get_path_to_file() const
{
	return pathToFile;
}

void CharacterManager::set_path_to_file(string path_to_file)
{
	pathToFile = std::move(path_to_file);
}

