#include "CharacterGrid.h"
#include <QDebug>
#include <string>



CharacterGrid::CharacterGrid(QWidget *parent, int height, int windowWidth):QWidget(parent)
{
	characterGrid = new QGridLayout(this);
	gridHeight = height;

	for (int i = 0; i < 20; i++) {
		images.push_back(new CharacterCard(this, gridHeight / 4, "./Photos/Characters/" + QString::number(i) + ".png"));
		/*QPixmap logo("./Photos/Characters/" + QString::number(i) + ".png");
		images.at(i)->setPixmap(logo.scaled(300, gridHeight / 4, Qt::KeepAspectRatio));
		images.at(i)->setStyleSheet("background: transparent;");*/
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			characterGrid->addWidget(images.at(5 * j + i), j, i+1, Qt::AlignCenter);
		}
	}

	int pictureWidth = 0.715*(gridHeight / 4);

	/*QPixmap logo("./Photos/Characters/" + QString::number(7) + ".png");
	QLabel *image = new QLabel(this);
	image->setPixmap(logo.scaled(1920, gridHeight, Qt::KeepAspectRatio));
	characterGrid->addWidget(image, 0, 0, 4, 5);
	delete image;*/

	characterGrid->setColumnMinimumWidth(0, (windowWidth-300-5*pictureWidth-50)/2);
	characterGrid->setColumnMinimumWidth(6, (windowWidth - 300 - 5 * pictureWidth-50) / 2);

	characterGrid->setContentsMargins(0, 0, 0, 0);
	characterGrid->setSpacing(0);
	this->setLayout(characterGrid);
}


CharacterGrid::~CharacterGrid()
{
}
