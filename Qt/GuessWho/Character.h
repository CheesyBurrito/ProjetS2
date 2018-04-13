/****************************************
GuessWho ProjetS2 - APP7Gi

P14
William Adam-Grenier - adaw2602
Charles Quesnel - quec2502
Maxime St-Onge - stom2105

Avril 2018

Character.h
*****************************************/

#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "CharacterTraits.h"
using namespace std;

class Character
{
private:
	int ID;
	bool isHidden = false;
	string picturePath;
	CharacterTraits* characterTraits;
public:
	Character();
	Character(int ID1);
	Character(int ID1, int eyes1, int hairColor1, int hairCharacteristics1, int gender1, int skinColor1, vector<int> accessories1, int facialHair1, int age1, string name1);
	Character(int ID1, int eyes1, int hairColor1, int hairCharacteristics1, int gender1, int skinColor1, vector<int> accessories1, int facialHair1, int age1, string name1, string picturePath1);
	Character(string path); //Instanciates character from file
	~Character();

	//General Methods
	void printProperties();
	bool exportCharacter(string path);
	bool importCharacterFromFile(string path);

	//Setter and Getters
	int get_id() const;
	void set_id(int id);
	bool is_is_hidden() const;
	void set_is_hidden(bool is_hidden);
	string get_picture_path() const;
	void set_picture_path(string picture_path);
	CharacterTraits* get_character_traits() const;
	void set_character_traits(CharacterTraits* character_traits);
};

