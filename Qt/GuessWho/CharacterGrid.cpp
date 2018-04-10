#include "CharacterGrid.h"
#include <QDebug>
#include <string>



CharacterGrid::CharacterGrid(QWidget *parent, int height, int width):QWidget(parent)
{
	this->setStyleSheet("background: transparent;");

	calculateGridDimensions(width, height);
	setupCharacters();
	setupLayouts();
		
}


CharacterGrid::~CharacterGrid()
{
	delete characters;
}

void CharacterGrid::setupCharacters(){
	characters = new std::vector<CharacterCard*>;

	for (int i = 0; i < 21; i++) {
		if (i != 20)
			characters->push_back(new CharacterCard(this, gridWidth / 7, "./Photos/Characters/" + QString::number(i) + ".png", "./Ressources/CharacterFiles/" + to_string(i) + ".txt"));
		else //21st character has to be the "chosen character" card
			characters->push_back(new CharacterCard(this, gridWidth / 7, "./Photos/Characters/" + QString::number(i) + ".png", "./Ressources/CharacterFiles/" + to_string(i) + ".txt", true));
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

	if (tempHeight > h/3) { //Cards don't fit if they occupy all the horizontal space --> make them occupy vertical space instead
		int cardWidth = 0.715*(h / 3); //0.715 --> width to height ratio
		gridHeight = h;
		gridWidth = 7 * cardWidth;
	}

	else {
		gridWidth = w;
		gridHeight = 3 * tempHeight;
	}
}