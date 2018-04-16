/****************************************
GuessWho ProjetS2 - APP7Gi

P14
William Adam-Grenier - adaw2602
Charles Quesnel - quec2502
Maxime St-Onge - stom2105

Avril 2018

TwoPlayersMenu.cpp
*****************************************/

#include "TwoPlayersMenu.h"

TwoPlayersMenu::TwoPlayersMenu(QWidget* parent, int colorMenu1, int colorMenu2) : QWidget(parent)
{
	color1 = colorMenu1;
	color2 = colorMenu2;
	createTwoPlayersMenu();
}

TwoPlayersMenu::~TwoPlayersMenu()
{
}

void TwoPlayersMenu::createTwoPlayersMenu()
{
	setFixedWidth(620);

	playerNameLayout1 = new QHBoxLayout;
	playerNameLayout2 = new QHBoxLayout;
	player1Menu = new ColorMenu(this);
	player2Menu = new ColorMenu(this);

	layout = new QFormLayout(this);
	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(10);
	layout->setFormAlignment(Qt::AlignCenter);

	player1 = new QLineEdit(this);
	player1->setStyleSheet("background: white;");
	player1->setFont(QFont("Walkway Bold", 18));
	player1->setText("Joueur1");
	player1->setFixedWidth(200);

	colorMenuPlayer1 = new QPushButton(this);
	colorMenuPlayer1->setStyleSheet("background-image: url(./Photos/color" + QString::number(color1) + ".png);");
	colorMenuPlayer1->setCursor(Qt::PointingHandCursor);
	colorMenuPlayer1->setFixedSize(40,40);

	player2 = new QLineEdit;
	player2->setStyleSheet("background: white;");
	player2->setFont(QFont("Walkway Bold", 18));
	player2->setText("Joueur2");
	player2->setFixedWidth(200);

	colorMenuPlayer2 = new QPushButton(this);
	colorMenuPlayer2->setStyleSheet("background-image: url(./Photos/color" + QString::number(color2) + ".png);");
	colorMenuPlayer2->setCursor(Qt::PointingHandCursor);
	colorMenuPlayer2->setFixedSize(40, 40);

	name1 = new QLabel("Nom du Joueur1", this);
	name1->setFont(QFont("Walkway Bold", 18));
	name1->setStyleSheet("background: transparent; color : white");

	name2 = new QLabel("Nom du Joueur2", this);
	name2->setFont(QFont("Walkway Bold", 18));
	name2->setStyleSheet("background: transparent; color : white");

	numGames = new QLabel("Nombre de partie", this);
	numGames->setFont(QFont("Walkway Bold", 18));
	numGames->setStyleSheet("background: transparent; color : white");

	m_lcd = new QLCDNumber(this);
	m_lcd->setFixedHeight(50);
	m_lcd->setFixedSize(250, 50);
	m_lcd->setSegmentStyle(QLCDNumber::Flat);
	m_lcd->setStyleSheet("background: white;");
	m_lcd->display(1);

	m_slider = new QSlider(Qt::Horizontal, this);
	m_slider->setValue(1);
	m_slider->setValue(1);
	m_slider->setSingleStep(2);
	m_slider->setRange(1, 7);
	m_slider->setFixedWidth(250);

	connect(m_slider, SIGNAL(valueChanged(int)), m_lcd, SLOT(display(int)));
	ok = new MenuButton(this, " Commencer");

	playerNameLayout1->addWidget(player1);
	playerNameLayout1->addWidget(colorMenuPlayer1);

	playerNameLayout2->addWidget(player2);
	playerNameLayout2->addWidget(colorMenuPlayer2);

	layout->insertRow(0, name1, playerNameLayout1);
	layout->insertRow(1, name2, playerNameLayout2);
	layout->insertRow(2, numGames, m_lcd);
	layout->insertRow(3, "", m_slider);
	layout->insertRow(4,ok);

	connect(getColorMenuButtonPlayer1(), SIGNAL(clicked()), this, SLOT(showColorMenu1()));
	connect(getColorMenuButtonPlayer2(), SIGNAL(clicked()), this, SLOT(showColorMenu2()));

	hide();
}

void TwoPlayersMenu::setTwoPlayersGame()
{
	player1Name = player1->text();
	player2Name = player2->text();

}

void TwoPlayersMenu::showColorMenu1()
{
	player1Menu->show();
	player1Menu->getColor0Button()->show();
	player1Menu->getColor1Button()->show();
	player1Menu->getColor2Button()->show();
	player1Menu->getColor3Button()->show();
	player1Menu->getColor4Button()->show();
	player1Menu->getColor5Button()->show();
	if (color2 == 0)
	{
		player1Menu->getColor0Button()->hide();
		player1Menu->setColorMenu(0);
	}
	else if (color2 == 1)
	{
		player1Menu->getColor1Button()->hide();
		player1Menu->setColorMenu(1);
	}
	else if (color2 == 2)
	{
		player1Menu->getColor2Button()->hide();
		player1Menu->setColorMenu(2);
	}
	else if (color2 == 3)
	{
		player1Menu->getColor3Button()->hide();
		player1Menu->setColorMenu(3);
	}
	else if (color2 == 4)
	{
		player1Menu->getColor4Button()->hide();
		player1Menu->setColorMenu(4);
	}
	else if (color2 == 5)
	{
		player1Menu->getColor5Button()->hide();
		player1Menu->setColorMenu(5);
	}
	setDisabled(true);
}

void TwoPlayersMenu::showColorMenu2()
{
	player2Menu->show();
	player2Menu->getColor0Button()->show();
	player2Menu->getColor1Button()->show();
	player2Menu->getColor2Button()->show();
	player2Menu->getColor3Button()->show();
	player2Menu->getColor4Button()->show();
	player2Menu->getColor5Button()->show();
	if (color1 == 0)
	{
		player2Menu->getColor0Button()->hide();
		player2Menu->setColorMenu(0);
	}
	else if (color1 == 1)
	{
		player2Menu->getColor1Button()->hide();
		player2Menu->setColorMenu(1);
	}
	else if (color1 == 2)
	{
		player2Menu->getColor2Button()->hide();
		player2Menu->setColorMenu(2);
	}
	else if (color1 == 3)
	{
		player2Menu->getColor3Button()->hide();
		player2Menu->setColorMenu(3);
	}
	else if (color1 == 4)
	{
		player2Menu->getColor4Button()->hide();
		player2Menu->setColorMenu(4);
	}
	else if (color1 == 5)
	{
		player2Menu->getColor5Button()->hide();
		player2Menu->setColorMenu(5);
	}
	setDisabled(true);
}

void TwoPlayersMenu::set_Enabled()
{
	setDisabled(false);
}

void TwoPlayersMenu::setColorButton(int color_1,int color_2)
{
	color1 = color_1;
	color2 = color_2;
	colorMenuPlayer1->setStyleSheet("background-image: url(./Photos/color" + QString::number(color_1) + ".png);");
	colorMenuPlayer2->setStyleSheet("background-image: url(./Photos/color" + QString::number(color_2) + ".png);");
}