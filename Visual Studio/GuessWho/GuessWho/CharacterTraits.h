#pragma once
#include <string>
#include <iostream>
using namespace std;

class CharacterTraits

{
private: 
	int eyes;
	int hairColor;
	int hairCharacteristics;
	int gender;
	int skinColor;
	int accessories;
	int facialHair;
	int age;
	string name;
public:
	//Constructors
	CharacterTraits();
	CharacterTraits(int eyes1, int hairColor1, int hairCharacteristics1, int gender1, int skinColor1, int accessories1, int facialHair1, int age1, string name1);
	//Deconstructor
	~CharacterTraits();

	//General Methods
	//TODO: Implement the print method
	void printProperties();
	string printPhysicalTraitsColorProperties(int colorIndex);
	string printPhysicalTraitsProperties(int traitIndex);

	//Getters
	int getEyes();
	int getHairColor();
	int getHairCharacteristics();
	int getGender();
	int getSkinColor();
	int getAccessories();
	int getFacialHair();
	int getAge();
	string getName();

	//Setters
	void set_eyes(int eyes);
	void set_hair_color(int hair_color);
	void set_hair_characteristics(int hair_characteristics);
	void set_gender(int gender);
	void set_skin_color(int skin_color);
	void set_accessories(int accessories);
	void set_facial_hair(int facial_hair);
	void set_age(int age);
	void set_name(string name);
};

