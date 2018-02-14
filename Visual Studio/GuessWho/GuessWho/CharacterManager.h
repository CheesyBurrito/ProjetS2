#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "Character.h"
using namespace std;

class CharacterManager
{
private:
	bool isShuffle = false;
	bool isLoaded = false;
	int numCharacterHidden = 0;
	int totalCharacter = 5;

	int propertiesEyesIndex[4] = { 0, 1, 2, 3 }; //Possible values for the eyes color
	int propertiesHairColorIndex[6] = { 0, 4, 5, 6, 7, 9 }; //Possible values for the hair color
	int propertiesHairPhysiqueIndex[3] = {1, 2, 3}; //Possible values for the hair physique
	int propertiesSkinColorIndex[3] = {6, 7, 8};
	int propertiesAccessoriesIndex[5] = { 0, 5, 6, 7, 8 };
	int propertiesFacialHairIndex[4] = {8, 9, 10, 11};
	int propertiesAgeIndex[2] = {14, 15};
	int propertiesGender[2] = {12, 13};

	enum physicalTraitsColor {Brun, Vert, Bleu, Rouge, Roux, Blond, Noir, Blanc, Basane, Autre};
	enum physicalTraits {Rien, Chauve, Court, Long, Piercing, Chapeau, Lunette, Tattoo, Rase, BarbePleine, Moustache, Favoris, Homme, Femme, Etudiant, Professeur};
	vector<Character*> characterVector;
	public:
	//Constructor
	CharacterManager();
	//Deconstructor
	~CharacterManager();

	//General Methods
	bool generateCharacters(); //Generates the Characters for the game
	void printProperties(); //This function prints all the properties of the Objects in the vector
	bool exportCharacters(string path); //Exports all characters in vector to files
	bool importCharacters(string path);

	//Setters and Getters


	bool is_is_shuffle() const;
	void set_is_shuffle(bool is_shuffle);
	bool is_is_loaded() const;
	void set_is_loaded(bool is_loaded);
	int get_num_character_hidden() const;
	void set_num_character_hidden(int num_character_hidden);
	int get_total_character() const;
	void set_total_character(int total_character);
};

