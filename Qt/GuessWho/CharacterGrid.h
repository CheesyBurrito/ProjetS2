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
	int gridHeight;
	CharacterCard* chosenCharacter;

public:
	CharacterGrid(QWidget *parent, int height, int width);
	~CharacterGrid();

	void calculateGridDimensions(int height, int width);

	int getGridWidth() { return gridWidth; }
	int getGridHeight() { return gridHeight; }
	int getCardHeight();

	std::vector<CharacterCard*>* getCharacters() { return images; }
};

