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
	int totalCharacter = 20;

	string pathToFile = "Ressources/CharacterFiles/";

	int propertiesEyesIndex[4] = { 0, 1, 2, 3 }; //Possible values for the eyes color
	int propertiesHairColorIndex[6] = { 0, 4, 5, 6, 7, 9 }; //Possible values for the hair color
	int propertiesHairPhysiqueIndex[3] = {1, 2, 3}; //Possible values for the hair physique
	int propertiesSkinColorIndex[3] = {6, 7, 8};
	int propertiesAccessoriesIndex[5] = { 0, 4, 5, 6, 7 };
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
	string addCharacter(Character*); //Add a character to the character vector, returns a string in case of a failure, to print message
	bool generateCharacters(); //Generates the Characters for the game
	void printProperties(); //This function prints all the properties of the Objects in the vector
	bool exportCharacters(string path); //Exports all characters in vector to files
	bool importCharacters(string path); //Import all characters in the character Manager
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
};

