/****************************************
GuessWho ProjetS2 - APP7Gi

P14
William Adam-Grenier - adaw2602
Charles Quesnel - quec2502
Maxime St-Onge - stom2105

Avril 2018

GameOverMenu.cpp
*****************************************/
#include "GameOverMenu.h"



GameOverMenu::GameOverMenu()
{
	pauseBackground = new QLabel(this);
	QPixmap pause_Pix("./Photos/pauseMenu.png");
	pauseBackground->setPixmap(pause_Pix.scaled(700, 373));

	layout = new QGridLayout(this);
	quitButton = new QPushButton("Quitter", this);
	text = new QLabel(this);

	this->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
	layout->setAlignment(Qt::AlignCenter);
	layout->setSpacing(0);
	layout->addWidget(pauseBackground, 0, 0, 10, 1, Qt::AlignCenter);
	layout->addWidget(text, 3, 0, Qt::AlignCenter);
	layout->addWidget(quitButton, 5, 0, Qt::AlignCenter);
	this->setLayout(layout);
}


GameOverMenu::~GameOverMenu()
{
}

void GameOverMenu::setWinner(QString winner) {
	text->setText("Le gagant est: " + winner);
}