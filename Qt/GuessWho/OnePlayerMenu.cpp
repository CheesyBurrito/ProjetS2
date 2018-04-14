/****************************************
GuessWho ProjetS2 - APP7Gi

P14
William Adam-Grenier - adaw2602
Charles Quesnel - quec2502
Maxime St-Onge - stom2105

Avril 2018

OnePlayerMenu.cpp
*****************************************/

#include "OnePlayerMenu.h"
#include <QDebug>

OnePlayerMenu::OnePlayerMenu(QWidget* parent) : QWidget(parent)
{
	createOnePlayerMenu();
}

OnePlayerMenu::~OnePlayerMenu()
{
}

void OnePlayerMenu::createOnePlayerMenu()
{
	setFixedWidth(620);
	layout = new QGridLayout(this);
	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(10);
	layout->setAlignment(Qt::AlignCenter);

	player1 = new QLineEdit(this);
	player1->setStyleSheet("background: white;");
	player1->setFont(QFont("Walkway Bold", 18));
	player1->setText("Joueur1");
	player1->setFixedWidth(200);

	name1 = new QLabel("Nom du Joueur1", this);
	name1->setFont(QFont("Walkway Bold", 18));
	name1->setStyleSheet("background: transparent; color : white");

	ok = new MenuButton(this, " Commencer");

	layout->addWidget(name1, 0, 0, 1, 1);
	layout->addWidget(player1, 0, 1, 1, 2);
	layout->addWidget(ok, 1, 0, 1, 2);

	setLayout(layout);

	hide();
}
