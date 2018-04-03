#include "CharacterGrid.h"



CharacterGrid::CharacterGrid(QWidget *parent, int height):QWidget(parent)
{
	characterGrid = new QGridLayout(this);

	gridHeight = height;

	QPixmap logo("./Photos/claudette.png");
	for (int i = 0; i < 20; i++) {
		images.push_back(new QLabel);
		images.at(i)->setPixmap(logo.scaled(300, gridHeight / 4, Qt::KeepAspectRatio));
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			characterGrid->addWidget(images.at(5 * j + i), j, i, Qt::AlignCenter);
		}
	}

	this->setLayout(characterGrid);
}


CharacterGrid::~CharacterGrid()
{
}
