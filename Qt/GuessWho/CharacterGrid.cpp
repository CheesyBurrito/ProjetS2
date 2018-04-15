/****************************************
GuessWho ProjetS2 - APP7Gi

P14
William Adam-Grenier - adaw2602
Charles Quesnel - quec2502
Maxime St-Onge - stom2105

Avril 2018


CharacterGrid::CharacterGrid(QWidget *parent, int height, int width):QWidget(parent)
{
	images = new std::vector<CharacterCard*>;
	characterGrid = new QGridLayout(this);
	calculateGridDimensions(width, height);
	//chosenCharacter = new CharacterCard(this, gridWidth / 7, "./Photos/Characters/" + QString::number(22) + ".png", "./Ressources/CharacterFiles/"+to_string(22)+".txt");

	for (int i = 0; i < 21; i++) {
		if (i != 20)
			images->push_back(new CharacterCard(this, gridWidth / 7, "./Photos/Characters/" + QString::number(i) + ".png", "./Ressources/CharacterFiles/" + to_string(i) + ".txt"));
		else
			images->push_back(new CharacterCard(this, gridWidth / 7, "./Photos/Characters/" + QString::number(i) + ".png", "./Ressources/CharacterFiles/" + to_string(i) + ".txt", true));
	}

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 3; j++) {
				characterGrid->addWidget(images->at(7 * j + i), j, i+1, Qt::AlignCenter);
		}
	}

	//images->at(20)->setChosenCharacter("./Photos/Characters/" + QString::number(21) + ".png");

	//int pictureWidth = 0.715*(gridHeight / 3);

	/*QPixmap logo("./Photos/Characters/" + QString::number(7) + ".png");
	QLabel *image = new QLabel(this);
	image->setPixmap(logo.scaled(1920, gridHeight, Qt::KeepAspectRatio));
	characterGrid->addWidget(image, 0, 0, 4, 5);
	delete image;*/

	//characterGrid->setColumnMinimumWidth(0, (windowWidth-300-7*pictureWidth-50)/2);
	//characterGrid->setColumnMinimumWidth(6, (windowWidth - 300 - 7 * pictureWidth-50) / 2);

	characterGrid->setContentsMargins(0, 0, 0, 0);
	characterGrid->setSpacing(0);
	this->setLayout(characterGrid);
}


CharacterGrid::~CharacterGrid()
{
	delete images;
}

int CharacterGrid::getCardHeight()
{
	return chosenCharacter->getCardHeight();
}

void CharacterGrid::calculateGridDimensions(int w, int h) {
	int tempHeight = 1.4*(w / 7);

	if (tempHeight > h/3) { //Cards don't fit if they occupy all the horizontal space --> make them occupy vertical space instead
		int cardWidth = 0.715*(h / 3);
		gridHeight = h;
		gridWidth = 7 * cardWidth;
	}

	else {
		gridWidth = w;
		gridHeight = 3 * tempHeight;
	}
}
CharacterGrid.cpp
*****************************************/

#include "CharacterGrid.h"
#include <QDebug>
#include <string>



CharacterGrid::CharacterGrid(QWidget *parent, int height, int width, CharacterManager* characterManager) :QWidget(parent)
{
	this->setStyleSheet("background: transparent;");
	this->characterManager = characterManager;

	calculateGridDimensions(width, height);
	setupCharacters();
	setupLayouts();

}


CharacterGrid::~CharacterGrid()
{
	delete characters;
}

//OLD VERSION DELETE WHEN BACKEND IS CONNECTED
/*void CharacterGrid::setupCharacters() {
	characters = new std::vector<CharacterCard*>;

	for (int i = 0; i < 21; i++) {
		if (i != 20)
			characters->push_back(new CharacterCard(this, gridWidth / 7, "./Photos/Characters/" + QString::number(i) + ".png", "./Ressources/CharacterFiles/" + to_string(i) + ".txt"));
		else //21st character has to be the "chosen character" card
			characters->push_back(new CharacterCard(this, gridWidth / 7, "./Photos/Characters/" + QString::number(i) + ".png", "./Ressources/CharacterFiles/" + to_string(i) + ".txt", true));
	}
}*/

//NEW VERSION

void CharacterGrid::setupCharacters() {
	characters = new std::vector<CharacterCard*>;

	for (int i = 0; i < 21; i++) {
		if (i != 20) //Adds the 20 characters
			characters->push_back(new CharacterCard(this, gridWidth / 7, characterManager->get_character_vector().at(i)));
		else //Sets the 21st character as a blank card
			characters->push_back(new CharacterCard(this, gridWidth / 7, NULL, true));
	}
}


void CharacterGrid::setupLayouts() {
	characterGrid = new QGridLayout(this);

	//Adds all cards to grid
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 3; j++) {
			characterGrid->addWidget(characters->at(7 * j + i), j, i + 1, Qt::AlignCenter);
		}
	}

	characterGrid->setContentsMargins(0, 0, 0, 0);
	characterGrid->setSpacing(0);
	this->setLayout(characterGrid);
}

void CharacterGrid::calculateGridDimensions(int w, int h) {
	int tempHeight = 1.4*(w / 7); //1.4 --> height to width ratio

	if (tempHeight > h / 3) { //Cards don't fit if they occupy all the horizontal space --> make them occupy vertical space instead
		int cardWidth = 0.715*(h / 3); //0.715 --> width to height ratio
		gridHeight = h;
		gridWidth = 7 * cardWidth;
	}

	else {
		gridWidth = w;
		gridHeight = 3 * tempHeight;
	}
}

int CharacterGrid::getNbHiddenCharacters() {
	int nb = 0;
	for (int i = 0; i < 20; i++) {
		if (this->characters->at(i)->getIsFlipped())
			nb++;
	}

	return nb;