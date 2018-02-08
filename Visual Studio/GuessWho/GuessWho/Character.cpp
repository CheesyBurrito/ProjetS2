#include "stdafx.h"
#include "Character.h"


Character::Character()
{
	ID = -1;
	picturePath = "Insert Path to dummy Picture";
	characterTraits = new CharacterTraits();
}

Character::Character(int ID1)
{
	ID = ID1;
	picturePath = "Insert Path to dummy Picture";
	characterTraits = new CharacterTraits();
}

Character::Character(int ID1, int eyes1, int hairColor1, int hairCharacteristics1, int gender1, int skinColor1, int accessories1, int facialHair1, int age1, string name1)
{
	ID = ID1;
	picturePath = "Insert Path to dummy Picture";
	characterTraits = new CharacterTraits(eyes1, hairColor1, hairCharacteristics1, gender1, skinColor1, accessories1, facialHair1, age1, name1);
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
