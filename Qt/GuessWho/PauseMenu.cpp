/****************************************
GuessWho ProjetS2 - APP7Gi

P14
William Adam-Grenier - adaw2602
Charles Quesnel - quec2502
Maxime St-Onge - stom2105

Avril 2018

PauseMenu.cpp
*****************************************/

#include "PauseMenu.h"


PauseMenu::PauseMenu(QWidget* parent)
{

	pauseBackground = new QLabel(this);
	QPixmap pause_Pix("./Photos/pauseMenu.png");
	pauseBackground->setPixmap(pause_Pix.scaled(700, 373));

	layout = new QGridLayout(this);
	quitButton = new MenuButton(this, " Quitter");
	resumeButton = new MenuButton(this, " Retourner au jeu");
	cancelGameButton = new MenuButton(this, " Retourner au menu");
	media_Player = new MediaPlayer(this);

	this->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
	layout->setAlignment(Qt::AlignCenter);
	layout->setSpacing(0);
	layout->addWidget(pauseBackground,0,0,10,1,Qt::AlignCenter);
	layout->addWidget(resumeButton,3,0, Qt::AlignCenter);
	layout->addWidget(cancelGameButton,4,0, Qt::AlignCenter);
	layout->addWidget(quitButton,5,0, Qt::AlignCenter);
	layout->addWidget(media_Player, 7, 0, Qt::AlignCenter);
	this->setLayout(layout);
	
}

PauseMenu::~PauseMenu()
{
}

void PauseMenu::keyPressEvent(QKeyEvent *event) {
	if (event->key() == Qt::Key_Escape) {
		emit escapeKeyPressed();
	}
}
