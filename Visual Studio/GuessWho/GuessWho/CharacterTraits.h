#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;
//The minimum number of accessories allowed by the game
const int Min_NUM_OF_CHARACTER_ACCESSORIES = 1;
//The maximum number of accessories allowed by the game
const int MAX_NUM_OF_CHARACTER_ACCESSORIES = 3;

class CharacterTraits

{
private: 
	//Decleration of variables related to the accessories
	//The number of accesories associated with this character, this will indicate the file reader
	//how many accesories to associate with the character
	int numOfAccessoriesOnCharacter = 1; 
	//The vector of accessories
	vector<int> accessories;

	int eyes;
	int hairColor;
	int hairCharacteristics;
	int gender;
	int skinColor;
	int facialHair;
	int age;
	string name;
public:
	//Constructors
	CharacterTraits();
	CharacterTraits(int eyes1, int hairColor1, int hairCharacteristics1, int gender1, int skinColor1, vector<int> accessories1, int facialHair1, int age1, string name1);
	//Deconstructor
	~CharacterTraits();

	//General Methods
	//TODO: Implement the print method
	void printProperties();
	string printPhysicalTraitsColorProperties(int colorIndex);
	string printPhysicalTraitsProperties(int traitIndex);
	string printAccessories();
	string addNewAccessory(int accessoryIndex); //Returns a string to allow to show an error message in case of failure
	bool hasAccessory(int accessoryIndex);

	//Getters
	int getEyes();
	int getHairColor();
	int getHairCharacteristics();
	int getGender();
	int getSkinColor();
	vector<int> getAccessories();
	int getFacialHair();
	int getAge();
	string getName();

	//Setters
	void set_eyes(int eyes);
	void set_hair_color(int hair_color);
	void set_hair_characteristics(int hair_characteristics);
	void set_gender(int gender);
	void set_skin_color(int skin_color);
	void set_accessories(vector<int> accessories);
	void set_facial_hair(int facial_hair);
	void set_age(int age);
	void set_name(string name);

	int get_num_of_accessories_on_character() const;
	void set_num_of_accessories_on_character(int num_of_accessories_on_character);
};

