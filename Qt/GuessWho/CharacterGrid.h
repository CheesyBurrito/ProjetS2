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
	int gridHeight;

public:
	CharacterGrid(QWidget *parent, int height, int windowWidth);
	~CharacterGrid();

	std::vector<CharacterCard*>* getCharacters() { return images; }
};

