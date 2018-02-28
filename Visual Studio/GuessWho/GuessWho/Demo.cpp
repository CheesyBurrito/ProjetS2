#include "stdafx.h"
#include "Demo.h"
#include <conio.h>

Demo::Demo()
{
	idCounter = 0;
}

Demo::~Demo()
{
}

void Demo::start() {
	int choice = -1;
	string choice_str;
	bool demoEnd = false;

	while (!demoEnd) {
		cout << string(50, '\n');

		cout << "***********GUESS WHO : GESTIONNAIRE DE PERSONNAGES***********" << endl << endl;

		cout << "1 : Ajouter un personnage" << endl;
		cout << "2 : Lister les personnages" << endl;
		cout << "3 : Exporter les personnages" << endl;
		cout << "4 : Importer des personnages" << endl;
		cout << "5 : Quitter" << endl;
		cout << ">> ";

		choice = inputVerification();
		
		switch (choice) {
		default:
			break;

		case 1: //Add
			this->addCharacter();
			break;

		case 2: //List
			cout << string(50, '\n');
			characterManager.printProperties();
			cout << "Appuyez sur une touche pour revenir au menu";
			_getch();
			break;

		case 3: //Export
			cout << string(50, '\n');
			cout << "Nom de la sauvegarde :" << endl << ">> ";
			cin >> choice_str;
			characterManager.exportCharacters("Ressources/CharacterFiles/" + choice_str);
			break;

		case 4: //Import
			cout << string(50, '\n');
			cout << "Nom de la sauvegarde :" << endl << ">> ";
			cin >> choice_str;
			characterManager.importCharacters("Ressources/CharacterFiles/" + choice_str);
			break;

		case 5: //Exit
			demoEnd = true;
			break;
		}
	}
}

void Demo::addCharacter()
{
	string name;
	int eyes, hairColor, hairCharacteristics, gender, skinColor, accessories, facialHair, age;

	cout << string(50, '\n');
	cout << "Nom du personnage :" << endl << ">> ";
	cin >> name;

	cout << string(50, '\n');
	cout << "Couleur des yeux :" << endl;
	cout << "0 : Brun" << endl;
	cout << "1 : Vert" << endl;
	cout << "2 : Bleu" << endl;
	cout << "3 : Rouge" << endl;
	cout << ">> ";
	cin >> eyes;

	cout << string(50, '\n');
	cout << "Couleur des cheveux :" << endl;
	cout << "0 : Brun" << endl;
	cout << "4 : Roux" << endl;
	cout << "5 : Blond" << endl;
	cout << "6 : Noir" << endl;
	cout << "7 : Blanc" << endl;
	cout << "9 : Autre" << endl;
	cout << ">> ";
	cin >> hairColor;

	cout << string(50, '\n');
	cout << "Type de cheveux :" << endl;
	cout << "1 : Chauve" << endl;
	cout << "2 : Courts" << endl;
	cout << "3 : Longs" << endl;
	cout << ">> ";
	cin >> hairCharacteristics;

	cout << string(50, '\n');
	cout << "Sexe :" << endl;
	cout << "12 : Homme" << endl;
	cout << "13 : Femme" << endl;
	cout << ">> ";
	cin >> gender;

	cout << string(50, '\n');
	cout << "Couleur de la peau :" << endl;
	cout << "6 : Noir" << endl;
	cout << "7 : Blanc" << endl;
	cout << "8 : Basane" << endl;
	cout << ">> ";
	cin >> skinColor;

	cout << string(50, '\n');
	cout << "Accessoires :" << endl;
	cout << "0 : Rien" << endl;
	cout << "4 : Piercing" << endl;
	cout << "5 : Chapeau" << endl;
	cout << "6 : Lunettes" << endl;
	cout << "7 : Tatoo" << endl;
	cout << ">> ";
	cin >> accessories;

	cout << string(50, '\n');
	cout << "Pilosite faciale :" << endl;
	cout << "8 : Rase" << endl;
	cout << "9 : Barbe" << endl;
	cout << "10 : Moustache" << endl;
	cout << "11 : Favoris" << endl;
	cout << ">> ";
	cin >> facialHair;

	cout << string(50, '\n');
	cout << "Categorie :" << endl;
	cout << "14 : Etudiant" << endl;
	cout << "15 : Professeur" << endl;
	cout << ">> ";
	cin >> age;

	characterManager.addCharacter(new Character(idCounter++, eyes, hairColor, hairCharacteristics, gender, skinColor, accessories, facialHair, age, name));
}

int Demo::inputVerification()
{
	int input = -1;
	cin >> input;

	if(cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Entree invalide!" << endl;
	}
	return input;
}

