#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <QDir>
#include "Character.h"
using namespace std;

class CharacterManager
{
private:
	bool isShuffle = false; //Indicates if the character list was shuffled
	bool isLoaded = false; //Indicates if the character list was loaded
	int numCharacterHidden = 0; //The number of characters hidden in the character list
	int totalCharacter = 20; //Total number of characters allowed in the game

	

	string pathToFile = "Ressources/CharacterFiles/";
	string fileExtension = ".gw";
	string characterFilesExtension = ".txt";
	string fileName = "characterList";

	enum physicalTraitsColor {Brun, Vert, Bleu, Rouge, Roux, Blond, Noir, Blanc, Basane, Autre};
	enum physicalTraits {Rien, Chauve, Court, Long, Piercing, Chapeau, Lunette, Tattoo, Rase, BarbePleine, Moustache, Bouc, Homme, Femme, Etudiant, Professeur};
	
	vector<Character*> characterVector; //The vector holding all the characters of the game

public:
	int propertiesEyesIndexSize = 4;
	int propertiesHairColorIndexSize = 6;
	int propertiesHairPhysiqueIndexSize = 3;
	int propertiesSkinColorIndexSize = 3;
	int propertiesAccessoriesIndexSize = 5;
	int propertiesFacialHairIndexSize = 4;
	int propertiesAgeIndexSize = 2;
	int propertiesGenderSize = 2;

	//Variables
	int propertiesEyesIndex[4] = { 0, 1, 2, 3 }; //Possible values for the eyes color
	int propertiesHairColorIndex[6] = { 0, 4, 5, 6, 7, 9 }; //Possible values for the hair color
	int propertiesHairPhysiqueIndex[3] = { 1, 2, 3 }; //Possible values for the hair physique
	int propertiesSkinColorIndex[3] = { 6, 7, 8 };
	int propertiesAccessoriesIndex[5] = { 0, 4, 5, 6, 7 };
	int propertiesFacialHairIndex[4] = { 8, 9, 10, 11 };
	int propertiesAgeIndex[2] = { 14, 15 };
	int propertiesGender[2] = { 12, 13 };

	//Constructor
	CharacterManager();
	//Deconstructor
	~CharacterManager();

	//General Methods
	string addCharacter(Character*); //Add a character to the character vector, returns a string in case of a failure, to print message
	bool generateCharacters(); //Generates the Characters for the game
	void printProperties(); //This function prints all the properties of the Objects in the vector
	bool exportCharacters(string saveName); //Exports all characters in vector to files
	bool importCharacters(string path); //Import all characters in the character Manager
	/*
	 *Should only be called during the game for changing the list, and not in the deconstructor
	 *while running under the Qt environnement
	*/
	void clearCharacterVector(); //Deletes all elements of the vector, to reset the characters
	void shuffleCharacters(); //Shuffles all of the characters present in the vector
	bool smartCharacterCreation(const Character *c); // Generates characters that have logical traits, ie bald and white haire
	void propertyPrinter(int propertyID);
	string printPhysicalTraitsColorProperties(int colorIndex);
	string printPhysicalTraitsProperties(int traitIndex);
	void hideCharacterAfterQuestion(int characteristicsSlected, int propertyID);
	void hideCharacterAfterQuestionOpposite(int characteristicsSlected, int propertyID);
	void hideCharacter(int characterID);

	//Setters and Getters
	bool is_is_shuffle() const;
	void set_is_shuffle(bool is_shuffle);
	bool is_is_loaded() const;
	void set_is_loaded(bool is_loaded);
	int get_num_character_hidden() const;
	void set_num_character_hidden(int num_character_hidden);
	int get_total_character() const;
	void set_total_character(int total_character);
	string get_path_to_file() const;
	void set_path_to_file(string path_to_file);
	vector<Character*> get_character_vector() const;
	int get_next_id(); //Gets the id of the next character to add to the list

};

