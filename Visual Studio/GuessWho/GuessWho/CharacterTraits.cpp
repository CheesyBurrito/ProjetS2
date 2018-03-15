#include "stdafx.h"
#include "CharacterTraits.h"


CharacterTraits::CharacterTraits()
{
	eyes = -1;
	hairColor = -1;
	hairCharacteristics = -1;
	gender = -1;
	skinColor = -1;
	//No accessories are put inside of it, because the functions will check if empty
	//accessories.push_back(-1);
	facialHair = -1;
	age = -1;
	name = "Personnage non initialise";
}

CharacterTraits::CharacterTraits(int eyes1, int hairColor1, int hairCharacteristics1, int gender1, int skinColor1, vector<int> accessories1, int facialHair1, int age1, string name1)
{
	eyes = eyes1;
	hairColor = hairColor1;
	hairCharacteristics = hairCharacteristics1;
	gender = gender1;
	skinColor = skinColor1;
	accessories = accessories1;
	numOfAccessoriesOnCharacter = accessories.size();
	facialHair = facialHair1;
	age = age1;
	name = name1;
}

CharacterTraits::~CharacterTraits()
{
}

void CharacterTraits::printProperties()
{
	cout << "Eyes: " << printPhysicalTraitsColorProperties(eyes) << ", Hair color: " << printPhysicalTraitsColorProperties(hairColor) << ", Hair Characteristics: " << printPhysicalTraitsProperties(hairCharacteristics) << ", Gender: " << printPhysicalTraitsProperties(gender) << ", Skin Color: " << printPhysicalTraitsColorProperties(skinColor) << ", Accessories: " << printAccessories() << ", Facial Hair: " << printPhysicalTraitsProperties(facialHair) << ", Age: " << printPhysicalTraitsProperties(age) << ", Name: " << name << endl;
	cout << endl;
}

string CharacterTraits::printAccessories()
{
	string accessoriesString = "";
	if(accessories.size() < Min_NUM_OF_CHARACTER_ACCESSORIES)
	{
		return "No accessories for this character, check code, this should not happen I think";
	}
	for(int i = 0; i < accessories.size(); i++)
	{
		accessoriesString += printPhysicalTraitsProperties(accessories.at(i));
		if(i == accessories.size() - 1)
		{
			
		}
		else
		{
			accessoriesString += ", ";
		}
		
	}

	return accessoriesString;
}

string CharacterTraits::printPhysicalTraitsColorProperties(int colorIndex)
{
	switch(colorIndex)
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

string CharacterTraits::printPhysicalTraitsProperties(int traitIndex)
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

string CharacterTraits::addNewAccessory(int accessoryIndex)
{
	//No need to check if the accessory is valid, as it is done by the character (the check is done before the call)
	if(accessories.size() == MAX_NUM_OF_CHARACTER_ACCESSORIES)
	{
		return "Number of maximum accessories reached!";
	}
	else
	{
		accessories.push_back(accessoryIndex);
	}
	return "Accessory added!";
}

bool CharacterTraits::hasAccessory(int accessoryIndex)
{
	for(int i = 0; i < numOfAccessoriesOnCharacter; i++)
	{
		if(accessories.at(i) != accessoryIndex)
		{
			return true;
		}
		else
		{
			continue;
		}
	}
	return false;
}


int CharacterTraits::getEyes()
{
	return eyes;
}

int CharacterTraits::getHairColor()
{

	return hairColor;
}

int CharacterTraits::getHairCharacteristics()
{
	return hairCharacteristics;
}

int CharacterTraits::getGender()
{
	return gender;
}

int CharacterTraits::getSkinColor()
{
	return skinColor;
}

vector<int> CharacterTraits::getAccessories()
{
	return accessories;
}

int CharacterTraits::getFacialHair()
{
	return facialHair;
}

int CharacterTraits::getAge()
{
	return age;
}

string CharacterTraits::getName()
{
	return name;
}

void CharacterTraits::set_eyes(int eyes)
{
	this->eyes = eyes;
}

void CharacterTraits::set_hair_color(int hair_color)
{
	hairColor = hair_color;
}

void CharacterTraits::set_hair_characteristics(int hair_characteristics)
{
	hairCharacteristics = hair_characteristics;
}

void CharacterTraits::set_gender(int gender)
{
	this->gender = gender;
}

void CharacterTraits::set_skin_color(int skin_color)
{
	skinColor = skin_color;
}

void CharacterTraits::set_accessories(vector<int> accessories)
{
	this->accessories = accessories;
}

void CharacterTraits::set_facial_hair(int facial_hair)
{
	facialHair = facial_hair;
}

void CharacterTraits::set_age(int age)
{
	this->age = age;
}

void CharacterTraits::set_name(string name)
{
	this->name = std::move(name);
}

int CharacterTraits::get_num_of_accessories_on_character() const
{
	return numOfAccessoriesOnCharacter;
}

void CharacterTraits::set_num_of_accessories_on_character(int num_of_accessories_on_character)
{
	numOfAccessoriesOnCharacter = num_of_accessories_on_character;
}



