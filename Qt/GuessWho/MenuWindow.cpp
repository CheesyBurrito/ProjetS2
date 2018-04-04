#include "MenuWindow.h"

MenuWindow::MenuWindow(QWidget* parent) : QWidget(parent)
{
	widthImage = parent->width() * 4/ 6;

	setWindowTitle("Guess Who?");
	setStyleSheet("background-image: url(./Photos/header_logo.png)");
	
	layoutPrincipal = new QGridLayout;

	image = new QLabel(this);
	QPixmap logo("./Photos/logo.png");
	image->setPixmap(logo.scaled(widthImage, 1080, Qt::KeepAspectRatio));
	layoutPrincipal->addWidget(image, 0, 0, 12, 4);

	setLayout(layoutPrincipal);
	startMenu();
}

MenuWindow::~MenuWindow()
{
	delete image;
	delete layoutPrincipal;
}

void MenuWindow::startMenu()
{
	layoutPrincipal->setColumnStretch(0, 60);
	layoutPrincipal->setColumnStretch(4, 20);
	layoutPrincipal->setColumnStretch(5, 10);
	layoutPrincipal->setColumnStretch(6, 0);

	onePlayer = new QPushButton("1 joueur", this);
		onePlayer->setFlat(true);
		onePlayer->setStyleSheet("background: transparent; color : white");
		onePlayer->setCursor(Qt::PointingHandCursor);
		onePlayer->setFont(QFont("Walkway Bold", 30));

	twoPlayers = new QPushButton("2 joueurs", this);
		twoPlayers->setFlat(true);
		twoPlayers->setStyleSheet("background: transparent; color : white");
		twoPlayers->setCursor(Qt::PointingHandCursor);
		twoPlayers->setFont(QFont("Walkway Bold", 30));

	quitButton = new QPushButton("Quitter", this);
		quitButton->setFlat(true);
		quitButton->setStyleSheet("background: transparent; color : white");
		quitButton->setCursor(Qt::PointingHandCursor);
		quitButton->setFont(QFont("Walkway Bold", 30));

	optionsButton = new QPushButton("Options", this);
		optionsButton->setFlat(true);
		optionsButton->setStyleSheet("background: transparent; color : white");
		optionsButton->setCursor(Qt::PointingHandCursor);
		optionsButton->setFont(QFont("Walkway Bold", 30));

	layoutPrincipal->addWidget(onePlayer, 4, 4, Qt::AlignLeft);
	layoutPrincipal->addWidget(twoPlayers, 5, 4, Qt::AlignLeft);
	layoutPrincipal->addWidget(optionsButton,6, 4, Qt::AlignLeft);
	layoutPrincipal->addWidget(quitButton, 7, 4, Qt::AlignLeft);
}

void MenuWindow::onePlayerWindow()
{
	numberPlayer = 1;
	delete onePlayer;
	delete twoPlayers;
	delete optionsButton;
	delete quitButton;

	layoutPrincipal->setColumnStretch(0, 60);
	layoutPrincipal->setColumnStretch(4, 20);
	layoutPrincipal->setColumnStretch(5, 20);
	layoutPrincipal->setColumnStretch(6, 10);

	nom1 = new QLabel("Nom du Joueur", this);
		nom1->setFont(QFont("Walkway Bold", 20));
		nom1->setStyleSheet("background: transparent; color : white");

	joueur1 = new QLineEdit;
		joueur1->setStyleSheet("background: white;");
		joueur1->setFont(QFont("Walkway Bold", 20));
		joueur1->setText("Joueur1");

	numGames = new QLabel("Nombre de parties", this);
		numGames->setFont(QFont("Walkway Bold", 20));
		numGames->setStyleSheet("background: transparent; color : white");

	ok = new QPushButton("Ok", this);
		ok->setFlat(true);
		ok->setStyleSheet("background: transparent; color : white");
		ok->setCursor(Qt::PointingHandCursor);
		ok->setFont(QFont("Walkway Bold", 30));

	m_lcd = new QLCDNumber(this);
		m_lcd->setSegmentStyle(QLCDNumber::Flat);
		m_lcd->setStyleSheet("background: white;");
		m_lcd->display(1);

	m_slider = new QSlider(Qt::Horizontal, this);
		m_slider->setStyleSheet("background: transparent;");
		m_slider->setValue(1);
		m_slider->setSingleStep(2);
		m_slider->setRange(1, 7);

	QObject::connect(m_slider, SIGNAL(valueChanged(int)), m_lcd, SLOT(display(int)));
	layoutPrincipal->addWidget(nom1, 5, 4);
	layoutPrincipal->addWidget(joueur1, 5, 5);
	layoutPrincipal->addWidget(numGames, 6, 4);
	layoutPrincipal->addWidget(m_lcd, 6, 5);
	layoutPrincipal->addWidget(m_slider, 7, 5);
	layoutPrincipal->addWidget(ok, 8, 5, Qt::AlignRight);
}

void MenuWindow::twoPlayersWindow()
{
	numberPlayer = 2;
	delete onePlayer;
	delete twoPlayers;
	delete optionsButton;
	delete quitButton;

	layoutPrincipal->setColumnStretch(0, 60);
	layoutPrincipal->setColumnStretch(4, 20);
	layoutPrincipal->setColumnStretch(5, 20);
	layoutPrincipal->setColumnStretch(6, 10);

	joueur1 = new QLineEdit;
		joueur1->setStyleSheet("background: white;");
		joueur1->setFont(QFont("Walkway Bold", 20));
		joueur1->setText("Joueur1");

	joueur2 = new QLineEdit;
		joueur2->setStyleSheet("background: white;");
		joueur2->setFont(QFont("Walkway Bold", 20));
		joueur2->setText("Joueur2");

	nom1 = new QLabel("Nom du Joueur1", this);
		nom1->setFont(QFont("Walkway Bold", 20));
		nom1->setStyleSheet("background: transparent; color : white");

	nom2 = new QLabel("Nom du Joueur2", this);
		nom2->setFont(QFont("Walkway Bold", 20));
		nom2->setStyleSheet("background: transparent; color : white");

	numGames = new QLabel("Nombre de parties", this);
		numGames->setFont(QFont("Walkway Bold", 20));
		numGames->setStyleSheet("background: transparent; color : white");

	ok = new QPushButton("Ok", this);
		ok->setFlat(true);
		ok->setStyleSheet("background: transparent; color : white");
		ok->setCursor(Qt::PointingHandCursor);
		ok->setFont(QFont("Walkway Bold", 30));

	m_lcd = new QLCDNumber(this);
		m_lcd->setSegmentStyle(QLCDNumber::Flat);
		m_lcd->setStyleSheet("background: white;");
		m_lcd->display(1);

	m_slider = new QSlider(Qt::Horizontal, this);
		m_slider->setStyleSheet("background: transparent;");
		m_slider->setValue(1);
		m_slider->setSingleStep(2);
		m_slider->setRange(1, 7);

	QObject::connect(m_slider, SIGNAL(valueChanged(int)), m_lcd, SLOT(display(int)));
	layoutPrincipal->addWidget(nom1, 4, 4);
	layoutPrincipal->addWidget(joueur1, 4, 5);
	layoutPrincipal->addWidget(nom2, 5, 4);
	layoutPrincipal->addWidget(joueur2, 5, 5);
	layoutPrincipal->addWidget(numGames, 6, 4);
	layoutPrincipal->addWidget(m_lcd, 6, 5);
	layoutPrincipal->addWidget(m_slider, 7, 5);
	layoutPrincipal->addWidget(ok, 8, 5,Qt::AlignRight);

}

void MenuWindow::optionsWindow()
{
	delete onePlayer;
	delete twoPlayers;
	delete optionsButton;
	delete quitButton;

	addCharacter = new QPushButton("Ajouter un personnage", this);
		addCharacter->setFlat(true);
		addCharacter->setStyleSheet("background: transparent; color : white");
		addCharacter->setCursor(Qt::PointingHandCursor);
		addCharacter->setFont(QFont("Walkway Bold", 30));

	listCharacter = new QPushButton("Lister les personnages", this);
		listCharacter->setFlat(true);
		listCharacter->setStyleSheet("background: transparent; color : white");
		listCharacter->setCursor(Qt::PointingHandCursor);
		listCharacter->setFont(QFont("Walkway Bold", 30));

	exportCharacter = new QPushButton("Exporter les personnages", this);
		exportCharacter->setFlat(true);
		exportCharacter->setStyleSheet("background: transparent; color : white");
		exportCharacter->setCursor(Qt::PointingHandCursor);
		exportCharacter->setFont(QFont("Walkway Bold", 30));
		
	back = new QPushButton("Retour", this);
		back->setFlat(true);
		back->setStyleSheet("background: transparent; color : white");
		back->setCursor(Qt::PointingHandCursor);
		back->setFont(QFont("Walkway Bold", 30));
	
	layoutPrincipal->addWidget(addCharacter, 4, 4, Qt::AlignLeft);
		layoutPrincipal->addWidget(listCharacter, 5, 4, Qt::AlignLeft);
		layoutPrincipal->addWidget(exportCharacter, 6, 4, Qt::AlignLeft);
		layoutPrincipal->addWidget(back, 7, 4, Qt::AlignLeft);
}


void MenuWindow::deleteOptionsWindow()
{
	delete addCharacter;
	delete listCharacter;
	delete exportCharacter;
	delete back;
}

void MenuWindow::deletePlayersWindow()
{
	delete nom1;
	delete numGames;
	delete m_slider;
	delete m_lcd;
	delete joueur1;
	delete ok;
	if (numberPlayer == 2)
	{
		delete nom2;
		delete joueur2;
	}

}


QPushButton* MenuWindow::getOnePlayerButton()
{
	return onePlayer;
}

QPushButton* MenuWindow::getTwoPlayersButton()
{
	return twoPlayers;
}

QPushButton* MenuWindow::getOptionsButton()
{
	return optionsButton;
}

QPushButton* MenuWindow::getQuitButton()
{
	return quitButton;
}

QPushButton* MenuWindow::getAddCharacterButton()
{
	return addCharacter;
}

QPushButton* MenuWindow::getListCharacterButton()
{
	return listCharacter;
}

QPushButton* MenuWindow::getExportCharacterButton()
{
	return exportCharacter;
}

QPushButton* MenuWindow::getBackButton()
{
	return back;
}

QPushButton* MenuWindow::getOkButton()
{
	return ok;
}

QString MenuWindow::getJoueur1Name()
{
	return joueur1->text();
}

QString MenuWindow::getJoueur2Name()
{
	return joueur2->text();
}

int MenuWindow::getNumberGames()
{
	return m_lcd->value();
}