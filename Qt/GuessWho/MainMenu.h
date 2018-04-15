/****************************************
GuessWho ProjetS2 - APP7Gi

P14
William Adam-Grenier - adaw2602
Charles Quesnel - quec2502
Maxime St-Onge - stom2105

Avril 2018

MainMenu.h
*****************************************/

#pragma once
#include <QWidget>
#include <QFont>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QPixmap>
#include "MenuButton.h"

class MainMenu : public QWidget
{
	Q_OBJECT

public slots:
	void createMainMenu();

public:
	MainMenu(QWidget* parent);
	~MainMenu();

	MenuButton* getOnePlayerButton() { return onePlayer; }
	MenuButton* getTwoPlayersButton() { return twoPlayers; }
	MenuButton* getOptionsButton() { return optionsButton; }
	MenuButton* getQuitButton() { return quitButton; }

	int getNumberPlayer() { return numberPlayer; }
	void setNumberPlayer(int num_player) { numberPlayer = num_player; }

private:
	QVBoxLayout * layout;
	int numberPlayer;
	MenuButton *onePlayer;
	MenuButton *twoPlayers;
	MenuButton *optionsButton;
	MenuButton *quitButton;
};
