/****************************************
GuessWho ProjetS2 - APP7Gi

P14
William Adam-Grenier - adaw2602
Charles Quesnel - quec2502
Maxime St-Onge - stom2105

Avril 2018

Character.cpp
*****************************************/

#include "stdafx.h"
#include "Character.h"

Character::Character()
{
	ID = -1;
	picturePath = "/Photos/BlankCharacter.png";
	characterTraits = new CharacterTraits();
}

Character::Character(int ID1)
{
	ID = ID1;
	picturePath = to_string(ID) + ".png";
	characterTraits = new CharacterTraits();
}

Character::Character(int ID1, int eyes1, int hairColor1, int hairCharacteristics1, int gender1, int skinColor1, vector<int> accessories1, int facialHair1, int age1, string name1)
{
	ID = ID1;
	picturePath = to_string(ID) + ".png";
	characterTraits = new CharacterTraits(eyes1, hairColor1, hairCharacteristics1, gender1, skinColor1, accessories1, facialHair1, age1, name1);
}

Character::Character(int ID1, int eyes1, int hairColor1, int hairCharacteristics1, int gender1, int skinColor1, vector<int> accessories1, int facialHair1, int age1, string name1, string picturePath1)
{
	ID = ID1;
	picturePath = picturePath1;
	characterTraits = new CharacterTraits(eyes1, hairColor1, hairCharacteristics1, gender1, skinColor1, accessories1, facialHair1, age1, name1);
}

Character::Character(string path)
{
	characterTraits = new CharacterTraits();
	importCharacterFromFile(path);
	
}

Character::~Character()
{
	delete characterTraits;
}

void Character::printProperties()
{
	cout << "ID: " << ID << " ";
	characterTraits -> printProperties();
}

bool Character::exportCharacter(string path) 
{
	if (ID == -1)//Cant export character that doesnt have properties
		return false;

	ofstream file(path + "/" + to_string(ID) + ".txt"); //Exports to path/ID.txt

	if (file.is_open()) {
		file << ID << endl;
		file << characterTraits->getEyes() << endl;
		file << characterTraits->getHairColor() << endl;
		file << characterTraits->getHairCharacteristics() << endl;
		file << characterTraits->getGender() << endl;
		file << characterTraits->getSkinColor() << endl;
		file << characterTraits->get_num_of_accessories_on_character() << endl;

		for(int i = 0; i < characterTraits->get_num_of_accessories_on_character(); i++)
		{
			file << characterTraits->getAccessories().at(i) << endl;
		}

		file << characterTraits->getFacialHair() << endl;
		file << characterTraits->getAge() << endl;
		file << characterTraits->getName() << endl;
	}

	else //Unable to open file
		return false;

	file.close();

	return true;
}

bool Character::importCharacterFromFile(string path)
{
	//cout << path << endl;
	string p_path = path;
	size_t foundSubstring = p_path.find(".txt");
	if (foundSubstring != std::string::npos)
	{
		p_path.erase(foundSubstring, 4);
	}

	picturePath = p_path + ".png";

	ifstream file(path);

	int tmp;
	string name;

	if (file.is_open()) {

		file >> ID;

		file >> tmp;
		characterTraits->set_eyes(tmp);

		file >> tmp;
		characterTraits->set_hair_color(tmp);

		file >> tmp;
		characterTraits->set_hair_characteristics(tmp);

		file >> tmp;
		characterTraits->set_gender(tmp);

		file >> tmp;
		characterTraits->set_skin_color(tmp);

		file >> tmp;
		characterTraits->set_num_of_accessories_on_character(tmp);

		for(int i = 0; i < characterTraits->get_num_of_accessories_on_character(); i++)
		{
			file >> tmp;
			characterTraits->addNewAccessory(tmp);
		}
		

		file >> tmp;
		characterTraits->set_facial_hair(tmp);

		file >> tmp;
		characterTraits->set_age(tmp);

		file >> name;
		characterTraits->set_name(name);

		return true;
	}

	else
	{
		this->ID = -1; //If unable to load, put ID to -1 
		return false;
	}

	//Forces a return, even if this statement should not be reached
	return false;
		
}

int Character::get_id() const
{
	return ID;
}

void Character::set_id(int id)
{
	ID = id;
}

bool Character::is_is_hidden() const
{
	return isHidden;
}

void Character::set_is_hidden(bool is_hidden)
{
	isHidden = is_hidden;
}

string Character::get_picture_path() const
{
	return picturePath;
}

void Character::set_picture_path(string picture_path)
{
	picturePath = std::move(picture_path);
}

CharacterTraits* Character::get_character_traits() const
{
	return characterTraits;
}

void Character::set_character_traits(CharacterTraits* character_traits)
{
	characterTraits = character_traits;
}
