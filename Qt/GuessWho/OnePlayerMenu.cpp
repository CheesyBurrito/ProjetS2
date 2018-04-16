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

OnePlayerMenu::OnePlayerMenu(QWidget* parent, int colorMenu) : QWidget(parent)
{
	color = colorMenu;
	createOnePlayerMenu();
}

OnePlayerMenu::~OnePlayerMenu()
{
}

void OnePlayerMenu::createOnePlayerMenu()
{
	setFixedWidth(620);

	playerNameLayout = new QHBoxLayout;
	player1Menu = new ColorMenu(this);

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
	colorMenuPlayer1->setStyleSheet("background-image: url(./Photos/color" + QString::number(color) + ".png);");
	colorMenuPlayer1->setCursor(Qt::PointingHandCursor);
	colorMenuPlayer1->setFixedSize(40, 40);

	name1 = new QLabel("Nom du Joueur", this);
	name1->setFont(QFont("Walkway Bold", 18));
	name1->setStyleSheet("background: transparent; color : white");

	numGames = new QLabel("Nombre de partie", this);
	numGames->setFont(QFont("Walkway Bold", 18));
	numGames->setStyleSheet("background: transparent; color : white");

	m_lcd = new QLCDNumber(this);
	m_lcd->setFixedSize(250, 50);
	m_lcd->setSegmentStyle(QLCDNumber::Flat);
	m_lcd->setStyleSheet("background: white;");
	m_lcd->display(1);

	m_slider = new QSlider(Qt::Horizontal,this);
	m_slider->setValue(1);
	m_slider->setSingleStep(2);
	m_slider->setRange(1, 7);
	m_slider->setFixedWidth(250);

	connect(m_slider, SIGNAL(valueChanged(int)), m_lcd, SLOT(display(int)));
	ok = new MenuButton(this, " Commencer");

	playerNameLayout->addWidget(player1);
	playerNameLayout->addWidget(colorMenuPlayer1);

	layout->insertRow(0, name1,playerNameLayout);
	layout->insertRow(1,numGames, m_lcd);
	layout->insertRow(2,"",m_slider);
	layout->insertRow(3, ok);

	connect(getColorMenuButtonPlayer1(), SIGNAL(clicked()), this, SLOT(showColorMenu()));

	hide();
}

void OnePlayerMenu::setOnePlayerGame()
{
	player1Name = player1->text();

}

void OnePlayerMenu::showColorMenu()
{
	player1Menu->show();
	setDisabled(true);
}

void OnePlayerMenu::set_Enabled()
{
	setDisabled(false);
}

void OnePlayerMenu::setColorButton(int color)
{
	colorMenuPlayer1->setStyleSheet("background-image: url(./Photos/color" + QString::number(color) + ".png);");
}