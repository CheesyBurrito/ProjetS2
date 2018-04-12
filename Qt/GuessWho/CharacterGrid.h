#pragma once
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <vector>
#include "CharacterCard.h"
#include "CharacterManager.h"

class CharacterGrid : public QWidget
{
private:
	QGridLayout * characterGrid;
	std::vector<CharacterCard*> *characters;
	int gridWidth;
	int gridHeight;
	CharacterCard* chosenCharacter;
	CharacterManager* characterManager;

public:
	CharacterGrid(QWidget *parent, int height, int width, CharacterManager* characterManager = NULL);
	~CharacterGrid();

	void setupCharacters();
	void setupLayouts();
	void calculateGridDimensions(int height, int width);
	int getNbHiddenCharacters();

	int getGridWidth() { return gridWidth; }
	int getGridHeight() { return gridHeight; }

	std::vector<CharacterCard*>* getCharacters() { return characters; }
};
