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
#include <QPushButton>
#include <QLabel>

class GameOverMenu : public QWidget
{
	Q_OBJECT

	QGridLayout * layout;
	QPushButton * quitButton;
	QLabel *pauseBackground;
	QLabel * text;

public:
	GameOverMenu();
	~GameOverMenu();
	QPushButton * getQuitButton() { return quitButton; }
	void setWinner(QString winner);
};

