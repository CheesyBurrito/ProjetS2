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
	QPixmap pause_Pix("./Photos/gameOver.png");
	pauseBackground->setPixmap(pause_Pix.scaled(700, 373));

	layout = new QGridLayout(this);
	quitButton = new MenuButton(this, " Retour au menu");
	text = new QLabel(this);
	score = new QLabel(this);
	num_games = new QLabel(this);

	text->setStyleSheet("color : white; Text-align:left");
	text->setFont(QFont("Walkway Bold", 20));
	text->setFixedWidth(520);

	score->setStyleSheet("color : white; Text-align:left");
	score->setFont(QFont("Walkway Bold", 20));
	score->setFixedWidth(520);

	num_games->setStyleSheet("color : white; Text-align:left");
	num_games->setFont(QFont("Walkway Bold", 20));
	num_games->setFixedWidth(520);

	this->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
	layout->setAlignment(Qt::AlignCenter);
	layout->setSpacing(0);
	layout->addWidget(pauseBackground, 0, 0, 10, 1, Qt::AlignCenter);
	layout->addWidget(text, 2, 0, Qt::AlignCenter);
	layout->addWidget(num_games, 4, 0, Qt::AlignCenter);
	layout->addWidget(score, 5, 0, Qt::AlignCenter);
	layout->addWidget(quitButton, 7, 0, Qt::AlignCenter);
	this->setLayout(layout);
}


GameOverMenu::~GameOverMenu()
{
}

void GameOverMenu::setWinner(QString winner,QString player1, QString player2, int win1, int win2, int games, int gamesPlayed) {
	text->setText("Le gagant est: " + winner);
	num_games->setText("Partie " + QString::number(gamesPlayed) + "/" + QString::number(games));
	score->setText(player1 + "   " + QString::number(win1) + " - " + QString::number(win2) + "   " + player2);
	if (gamesPlayed >= games)
		quitButton->setText(" Retour au menu");
	else
		quitButton->setText(" Continuer");

}