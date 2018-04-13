/****************************************
GuessWho ProjetS2 - APP7Gi

P14
William Adam-Grenier - adaw2602
Charles Quesnel - quec2502
Maxime St-Onge - stom2105

Avril 2018

MainMenu.cpp
*****************************************/

#include "MainMenu.h"

MainMenu::MainMenu(QWidget* parent) : QWidget(parent)
{
	createMainMenu();
}

MainMenu::~MainMenu()
{
}

void MainMenu::createMainMenu()
{
	setFixedWidth(620);
	layout = new QVBoxLayout;
	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(0);
	layout->setAlignment(Qt::AlignCenter);

	onePlayer = new MenuButton(this, " 1 joueur");
	twoPlayers = new MenuButton(this, " 2 joueurs");
	optionsButton = new MenuButton(this, " Options");
	quitButton = new MenuButton(this, " Quitter");


	layout->addWidget(onePlayer);
	layout->addWidget(twoPlayers);
	layout->addWidget(optionsButton);
	layout->addWidget(quitButton);

	setLayout(layout);
}
