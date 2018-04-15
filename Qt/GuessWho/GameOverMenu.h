/****************************************
GuessWho ProjetS2 - APP7Gi

P14
William Adam-Grenier - adaw2602
Charles Quesnel - quec2502
Maxime St-Onge - stom2105

Avril 2018

GameOverMenu.h
*****************************************/

#pragma once
#include <QWidget>
#include <QKeyEvent>
#include <QGridLayout>
#include "MenuButton.h"
#include <QLabel>


class GameOverMenu : public QWidget
{
	Q_OBJECT

	QGridLayout * layout;
	MenuButton * quitButton;
	QLabel *pauseBackground;
	QLabel * text;
	QLabel * score;
	QLabel * num_games;

public:
	GameOverMenu();
	~GameOverMenu();
	MenuButton * getQuitButton() { return quitButton; }
	void setWinner(QString winner,QString player1, QString player2, int win1, int win2, int games, int gamesPlayed);
};

