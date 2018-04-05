#pragma once
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <vector>
#include "CharacterCard.h"

class CharacterGrid : public QWidget
{
private:
	QGridLayout * characterGrid;
	std::vector<CharacterCard*> *images;
	int gridWidth;
	CharacterCard* chosenCharacter;

public:
	CharacterGrid(QWidget *parent, int height, int width);
	~CharacterGrid();
	int getCardHeight();

	std::vector<CharacterCard*>* getCharacters() { return images; }
};

