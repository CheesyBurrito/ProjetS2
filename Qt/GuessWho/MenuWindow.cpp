#include "MenuWindow.h"
#include <QDebug>

MenuWindow::MenuWindow(QWidget* parent) : QWidget(parent)
{
	widthImage = parent->width() * 2/ 3;

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

	onePlayer = new MenuButton(this," 1 joueur");
	twoPlayers = new MenuButton(this, " 2 joueurs");
	optionsButton = new MenuButton(this, " Options");
	quitButton = new MenuButton(this, " Quitter");

	layoutPrincipal->addWidget(onePlayer, 4, 4, Qt::AlignLeft);
	layoutPrincipal->addWidget(twoPlayers, 5, 4, Qt::AlignLeft);
	layoutPrincipal->addWidget(optionsButton,6, 4, Qt::AlignLeft);
	layoutPrincipal->addWidget(quitButton, 7, 4, Qt::AlignLeft);

	layoutPrincipal->setContentsMargins(0, 0, 0, 0);
	layoutPrincipal->setSpacing(0);

	QObject::connect(onePlayer, SIGNAL(hovered()), this, SLOT(setMenuHoveredButton()));
	QObject::connect(twoPlayers, SIGNAL(hovered()), this, SLOT(setMenuHoveredButton()));
	QObject::connect(optionsButton, SIGNAL(hovered()), this, SLOT(setMenuHoveredButton()));
	QObject::connect(quitButton, SIGNAL(hovered()), this, SLOT(setMenuHoveredButton()));
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
		m_lcd->setFixedHeight(50);
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

	layoutPrincipal->setSpacing(10);
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
		m_lcd->setFixedHeight(50);
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

	layoutPrincipal->setSpacing(10);

}

void MenuWindow::optionsWindow()
{
	delete onePlayer;
	delete twoPlayers;
	delete optionsButton;
	delete quitButton;

	addCharacter = new MenuButton(this," Ajouter un personnage");
		addCharacter->setToolTip("Le personnage sera ajouté à la liste active");

	createNewList = new MenuButton(this, " Créer une nouvelle liste");
		createNewList->setToolTip("La nouvelle liste deviendra la liste active");

	changeList = new MenuButton(this, " Changer de liste");
		changeList->setToolTip("La liste choisie deviendra la liste active");

	back = new MenuButton(this, " Retour");
		back->setToolTip(" Retourner au menu principal");

	active_List = new QLineEdit(this);
		active_List->setStyleSheet("background: white;");
		active_List->setFont(QFont("Walkway Bold", 20));
		active_List->setText(activeList);
		active_List->setReadOnly(true);

	list = new QLabel("Liste Active:", this);
		list->setFont(QFont("Walkway Bold", 20));
		list->setStyleSheet("background: transparent; color : white");

	layoutPrincipal->addWidget(addCharacter, 4, 4, Qt::AlignLeft);
		layoutPrincipal->addWidget(createNewList, 5, 4, Qt::AlignLeft);
		layoutPrincipal->addWidget(changeList, 6, 4, Qt::AlignLeft);
		layoutPrincipal->addWidget(back, 7, 4, Qt::AlignLeft);
		layoutPrincipal->addWidget(list, 9, 0,1,4,Qt::AlignRight);
		layoutPrincipal->addWidget(active_List, 9, 4, 1 ,4);

	connect(addCharacter, SIGNAL(hovered()), this, SLOT(setOptionsHoveredButton()));
	connect(createNewList, SIGNAL(hovered()), this, SLOT(setOptionsHoveredButton()));
	connect(changeList, SIGNAL(hovered()), this, SLOT(setOptionsHoveredButton()));
	connect(back, SIGNAL(hovered()), this, SLOT(setOptionsHoveredButton()));
}

void MenuWindow::showDialog()
{
	QString selfilter = tr("GuessWho Files (*.gw)");
	QString fileDialog = QFileDialog::getOpenFileName(this, "Ouvrir une liste de personnages", "./Photos", tr("GuessWho Files (*.gw)"), &selfilter);
	if (fileDialog != "")
	{
		activeList = fileDialog;
	}
	active_List->setText(activeList);
}

void MenuWindow::setMenuHoveredButton()
{
	onePlayer->setIsSelected(false);
	twoPlayers->setIsSelected(false);
	optionsButton->setIsSelected(false);
	quitButton->setIsSelected(false);
}

void MenuWindow::setOptionsHoveredButton()
{
	addCharacter->setIsSelected(false);
	createNewList->setIsSelected(false);
	changeList->setIsSelected(false);
	back->setIsSelected(false);
}

void MenuWindow::addCharacters()
{
	/*QWidget *zoomWindow;
	zoomWindow = new QWidget;
	QVBoxLayout *zoomLayout = new QVBoxLayout(zoomWindow);
	QLabel *img = new QLabel(zoomWindow);
	img->setPixmap(picture);
	zoomLayout->addWidget(img);

	zoomWindow->setStyleSheet("background-image: url(./Photos/header_logo.png)");
	zoomWindow->setLayout(zoomLayout);
	zoomWindow->setWindowFlags(Qt::SplashScreen);
	zoomWindow->show();*/
}

void MenuWindow::deleteOptionsWindow()
{
	delete addCharacter;
	delete createNewList;
	delete changeList;
	delete back;
	delete active_List;
	delete list;
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

QString MenuWindow::getListName()
{
	return activeList;
}