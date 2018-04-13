#include "TwoPlayersMenu.h"

TwoPlayersMenu::TwoPlayersMenu(QWidget* parent) : QWidget(parent)
{
	createTwoPlayersMenu();
}

TwoPlayersMenu::~TwoPlayersMenu()
{
}

void TwoPlayersMenu::createTwoPlayersMenu()
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

	player2 = new QLineEdit;
	player2->setStyleSheet("background: white;");
	player2->setFont(QFont("Walkway Bold", 18));
	player2->setText("Joueur2");
	player2->setFixedWidth(200);

	name1 = new QLabel("Nom du Joueur1", this);
	name1->setFont(QFont("Walkway Bold", 18));
	name1->setStyleSheet("background: transparent; color : white");

	name2 = new QLabel("Nom du Joueur2", this);
	name2->setFont(QFont("Walkway Bold", 18));
	name2->setStyleSheet("background: transparent; color : white");

	numGames = new QLabel("Nombre de parties", this);
	numGames->setFont(QFont("Walkway Bold", 18));
	numGames->setStyleSheet("background: transparent; color : white");

	ok = new MenuButton(this, " Commencer");

	m_lcd = new QLCDNumber(this);
	m_lcd->setFixedSize(200, 50);
	m_lcd->setSegmentStyle(QLCDNumber::Flat);
	m_lcd->setStyleSheet("background: white;");
	m_lcd->display(1);

	m_slider = new QSlider(Qt::Horizontal, this);
	m_slider->setStyleSheet("background: transparent;");
	m_slider->setValue(1);
	m_slider->setSingleStep(2);
	m_slider->setRange(1, 7);
	m_slider->setFixedWidth(200);

	connect(m_slider, SIGNAL(valueChanged(int)), m_lcd, SLOT(display(int)));
	layout->addWidget(name1,0,0,1,1);
	layout->addWidget(player1,0,1,1,2);
	layout->addWidget(name2,1,0,1,1);
	layout->addWidget(player2,1,1,1,2);
	layout->addWidget(numGames,2,0,1,1);
	layout->addWidget(m_lcd,2,1,1,2);
	layout->addWidget(m_slider,3,1,1,2);
	layout->addWidget(ok,4,0,1,2,Qt::AlignRight);

	setLayout(layout);

	hide();
}

