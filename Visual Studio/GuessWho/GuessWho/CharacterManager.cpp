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
			addCharacter(new Character(path + characterIDs[j] + ".txt"));
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

//TODO Implement the method
bool CharacterManager::smartCharacterCreation()
{
	return true;
}

void CharacterManager::propertyPrinter(int propertyID)
{
	switch (propertyID)
	{
	case 0: {
		for (int i = 0; i < 4; i++)
		{
			cout << propertiesEyesIndex[i] << " - " << printPhysicalTraitsColorProperties(propertiesEyesIndex[i]) << endl;
		}
	}break;
	case 1: {
		for (int i = 0; i < 6; i++)
		{
			cout << propertiesHairColorIndex[i] << " - " << printPhysicalTraitsColorProperties(propertiesHairColorIndex[i]) << endl;
		}
	}break;
	case 2: {
		for (int i = 0; i < 3; i++)
		{
			cout << propertiesHairPhysiqueIndex[i] << " - " << printPhysicalTraitsProperties(propertiesHairPhysiqueIndex[i]) << endl;
		}
	}break;
	case 3: {
		for (int i = 0; i < 3; i++)
		{
			cout << propertiesSkinColorIndex[i] << " - " << printPhysicalTraitsColorProperties(propertiesSkinColorIndex[i]) << endl;
		}
	}break;
	case 4: {
		for (int i = 0; i < 5; i++)
		{
			cout << propertiesAccessoriesIndex[i] << " - " << printPhysicalTraitsProperties(propertiesAccessoriesIndex[i]) << endl;
		}
	}break;
	case 5: {
		for (int i = 0; i < 4; i++)
		{
			cout << propertiesFacialHairIndex[i] << " - " << printPhysicalTraitsProperties(propertiesFacialHairIndex[i]) << endl;
		}
	}break;
	case 6: {
		for (int i = 0; i < 2; i++)
		{
			cout << propertiesAgeIndex[i] << " - " << printPhysicalTraitsProperties(propertiesAgeIndex[i]) << endl;
		}
	}break;
	case 7:{
		for (int i = 0; i < 2; i++)
		{
			cout << propertiesGender[i] << " - " << printPhysicalTraitsProperties(propertiesGender[i]) << endl;
		}
	}break;
	}

}

string CharacterManager::printPhysicalTraitsColorProperties(int colorIndex)
{
	switch (colorIndex)
	{
	case 0:
	{
		return "Brun";
	}
	case 1:
	{
		return "Vert";
	}
	case 2:
	{
		return "Bleu";
	}
	case 3:
	{
		return "Rouge";
	}
	case 4:
	{
		return "Roux";
	}
	case 5:
	{
		return "Blond";
	}
	case 6:
	{
		return "Noir";
	}
	case 7:
	{
		return "Blanc";
	}
	case 8:
	{
		return "Basane";
	}
	case 9:
	{
		return "Autre";
	}
	default:
	{
		return "Invalid property value!";
	}
	}
}

string CharacterManager::printPhysicalTraitsProperties(int traitIndex)
{
	switch (traitIndex)
	{
	case 0:
	{
		return "Rien";
	}
	case 1:
	{
		return "Chauve";
	}
	case 2:
	{
		return "Court";
	}
	case 3:
	{
		return "Long";
	}
	case 4:
	{
		return "Piercing";
	}
	case 5:
	{
		return "Chapeau";
	}
	case 6:
	{
		return "Lunette";
	}
	case 7:
	{
		return "Tattoo";
	}
	case 8:
	{
		return "Rase";
	}
	case 9:
	{
		return "Barbe Plein";
	}
	case 10:
	{
		return "Moustache";
	}
	case 11:
	{
		return "Favoris";
	}
	case 12:
	{
		return "Homme";
	}
	case 13:
	{
		return "Femme";
	}
	case 14:
	{
		return "Etudiant";
	}
	case 15:
	{
		return "Professeur";
	}
	}
	return "Invalid property value!";
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

