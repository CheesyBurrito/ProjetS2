#include "MenuWindow.h"
#include <QDebug>

MenuWindow::MenuWindow(QWidget* parent) : QWidget(parent)
{
	widthImage = parent->width() - 520;
	heightImage = parent->height() *2/3;

	setWindowTitle("Guess Who?");
	setStyleSheet("background-image: url(./Photos/header_logo.png)");

	layoutPrincipal = new QGridLayout;

	image = new QLabel(this);
	QPixmap logo("./Photos/logo.png");
	image->setPixmap(logo.scaled(widthImage, heightImage, Qt::KeepAspectRatio));
	layoutPrincipal->addWidget(image, 0, 0, 12, 4);

	setLayout(layoutPrincipal);

	createFirstMenu();
	createOnePlayerWindow();
	createTwoPlayersWindow();
	createOptionsWindow();
}

MenuWindow::~MenuWindow()
{
}

void MenuWindow::createFirstMenu()
{

	onePlayer = new MenuButton(this, " 1 joueur");
	twoPlayers = new MenuButton(this, " 2 joueurs");
	optionsButton = new MenuButton(this, " Options");
	quitButton = new MenuButton(this, " Quitter");

	layoutPrincipal->setColumnStretch(0, 60);
	layoutPrincipal->setColumnStretch(4, 20);
	layoutPrincipal->setColumnStretch(5, 10);
	layoutPrincipal->setColumnStretch(6, 10);

	layoutPrincipal->addWidget(onePlayer, 4, 4, Qt::AlignLeft);
	layoutPrincipal->addWidget(twoPlayers, 5, 4, Qt::AlignLeft);
	layoutPrincipal->addWidget(optionsButton,6, 4, Qt::AlignLeft);
	layoutPrincipal->addWidget(quitButton, 7, 4, Qt::AlignLeft);

	layoutPrincipal->setContentsMargins(0, 0, 0, 0);

	connect(onePlayer, SIGNAL(hovered(MenuButton*)), this, SLOT(setMenuHoveredButton(MenuButton*)));
	connect(twoPlayers, SIGNAL(hovered(MenuButton*)), this, SLOT(setMenuHoveredButton(MenuButton*)));
	connect(optionsButton, SIGNAL(hovered(MenuButton*)), this, SLOT(setMenuHoveredButton(MenuButton*)));
	connect(quitButton, SIGNAL(hovered(MenuButton*)), this, SLOT(setMenuHoveredButton(MenuButton*)));

}

void MenuWindow::createOnePlayerWindow()
{
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

	hideOnePlayerWindow();
}

void MenuWindow::createTwoPlayersWindow()
{
	layoutPrincipal->setColumnStretch(0, 60);
	layoutPrincipal->setColumnStretch(4, 20);
	layoutPrincipal->setColumnStretch(5, 20);
	layoutPrincipal->setColumnStretch(6, 10);


	joueur1_2 = new QLineEdit;
		joueur1_2->setStyleSheet("background: white;");
		joueur1_2->setFont(QFont("Walkway Bold", 20));
		joueur1_2->setText("Joueur1");

	joueur2 = new QLineEdit;
		joueur2->setStyleSheet("background: white;");
		joueur2->setFont(QFont("Walkway Bold", 20));
		joueur2->setText("Joueur2");

	nom1_2 = new QLabel("Nom du Joueur1", this);
		nom1_2->setFont(QFont("Walkway Bold", 20));
		nom1_2->setStyleSheet("background: transparent; color : white");

	nom2 = new QLabel("Nom du Joueur2", this);
		nom2->setFont(QFont("Walkway Bold", 20));
		nom2->setStyleSheet("background: transparent; color : white");

	numGames_2 = new QLabel("Nombre de parties", this);
		numGames_2->setFont(QFont("Walkway Bold", 20));
		numGames_2->setStyleSheet("background: transparent; color : white");

	ok_2 = new QPushButton("Ok", this);
		ok_2->setFlat(true);
		ok_2->setStyleSheet("background: transparent; color : white");
		ok_2->setCursor(Qt::PointingHandCursor);
		ok_2->setFont(QFont("Walkway Bold", 30));

	m_lcd_2 = new QLCDNumber(this);
		m_lcd_2->setFixedHeight(50);
		m_lcd_2->setSegmentStyle(QLCDNumber::Flat);
		m_lcd_2->setStyleSheet("background: white;");
		m_lcd_2->display(1);

	m_slider_2 = new QSlider(Qt::Horizontal, this);
		m_slider_2->setStyleSheet("background: transparent;");
		m_slider_2->setValue(1);
		m_slider_2->setSingleStep(2);
		m_slider_2->setRange(1, 7);

	QObject::connect(m_slider_2, SIGNAL(valueChanged(int)), m_lcd_2, SLOT(display(int)));
	layoutPrincipal->addWidget(nom1_2, 4, 4);
	layoutPrincipal->addWidget(joueur1_2, 4, 5);
	layoutPrincipal->addWidget(nom2, 5, 4);
	layoutPrincipal->addWidget(joueur2, 5, 5);
	layoutPrincipal->addWidget(numGames_2, 6, 4);
	layoutPrincipal->addWidget(m_lcd_2, 6, 5);
	layoutPrincipal->addWidget(m_slider_2, 7, 5);
	layoutPrincipal->addWidget(ok_2, 8, 5,Qt::AlignRight);

	hideTwoPlayersWindow();
}

void MenuWindow::createOptionsWindow()
{
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
		layoutPrincipal->addWidget(active_List, 9, 4, 1 ,1);

	connect(addCharacter, SIGNAL(hovered(MenuButton*)), this, SLOT(setOptionsHoveredButton(MenuButton*)));
	connect(createNewList, SIGNAL(hovered(MenuButton*)), this, SLOT(setOptionsHoveredButton(MenuButton*)));
	connect(changeList, SIGNAL(hovered(MenuButton*)), this, SLOT(setOptionsHoveredButton(MenuButton*)));
	connect(back, SIGNAL(hovered(MenuButton*)), this, SLOT(setOptionsHoveredButton(MenuButton*)));

	hideOptionsWindow();
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

void MenuWindow::setMenuHoveredButton(MenuButton *button)
{
	onePlayer->setIsSelected(false);
	twoPlayers->setIsSelected(false);
	optionsButton->setIsSelected(false);
	quitButton->setIsSelected(false);
	button->setIsSelected(true);
}

void MenuWindow::setOptionsHoveredButton(MenuButton *button)
{
	addCharacter->setIsSelected(false);
	createNewList->setIsSelected(false);
	changeList->setIsSelected(false);
	back->setIsSelected(false);
	button->setIsSelected(true);
}

void MenuWindow::addCharacters()
{
	AddCharacterWindow = new AddCharacter(this);
	AddCharacterWindow->show();
	connect(AddCharacterWindow->getCancelButton(), SIGNAL(clicked()), AddCharacterWindow, SLOT(close()));
	connect(AddCharacterWindow->getCancelButton(), SIGNAL(clicked()), this, SLOT(set_Menu()));
	connect(AddCharacterWindow, SIGNAL(characterIsOk()), this, SLOT(set_Menu()));
	disconnect(addCharacter, SIGNAL(hovered(MenuButton*)), this, SLOT(setOptionsHoveredButton(MenuButton*)));
	disconnect(createNewList, SIGNAL(hovered(MenuButton*)), this, SLOT(setOptionsHoveredButton(MenuButton*)));
	disconnect(changeList, SIGNAL(hovered(MenuButton*)), this, SLOT(setOptionsHoveredButton(MenuButton*)));
	disconnect(back, SIGNAL(hovered(MenuButton*)), this, SLOT(setOptionsHoveredButton(MenuButton*)));
	this->setDisabled(true);
}

void MenuWindow::hideFirstMenu()
{
	onePlayer->hide();
	twoPlayers->hide();
	optionsButton->hide();
	quitButton->hide();
}

void MenuWindow::hideOptionsWindow()
{
	addCharacter->hide();
	createNewList->hide();
	changeList->hide();
	back->hide();
	active_List->hide();
	list->hide();
}

void MenuWindow::hideOnePlayerWindow()
{
	nom1->hide();
	numGames->hide();
	m_slider->hide();
	m_lcd->hide();
	joueur1->hide();
	ok->hide();
}

void MenuWindow::hideTwoPlayersWindow()
{
	nom1_2->hide();
	numGames_2->hide();
	m_slider_2->hide();
	m_lcd_2->hide();
	joueur1_2->hide();
	ok_2->hide();
	nom2->hide();
	joueur2->hide();
}

void MenuWindow::showFirstMenu()
{
	layoutPrincipal->setColumnStretch(5, 10);
	layoutPrincipal->setSpacing(0);
	show();
	image->show();
	onePlayer->show();
	twoPlayers->show();
	optionsButton->show();
	quitButton->show();
	connect(onePlayer, SIGNAL(clicked()), this, SLOT(showOnePlayerWindow()));
	connect(twoPlayers, SIGNAL(clicked()), this, SLOT(showTwoPlayersWindow()));
	connect(optionsButton, SIGNAL(clicked()), this, SLOT(showOptionsWindow()));
	connect(quitButton, SIGNAL(clicked()), this->parent(), SLOT(close()));
}

void MenuWindow::showOptionsWindow()
{
	layoutPrincipal->setSpacing(0);
	hideFirstMenu();
	addCharacter->show();
	createNewList->show();
	changeList->show();
	back->show();
	active_List->show();
	list->show();
	connect(addCharacter, SIGNAL(clicked()), this, SLOT(addCharacters()));
	connect(createNewList, SIGNAL(clicked()), this, SLOT(showFirstMenu()));
	connect(createNewList, SIGNAL(clicked()), this, SLOT(hideOptionsWindow()));
	connect(changeList, SIGNAL(clicked()), this, SLOT(showDialog()));
	connect(back, SIGNAL(clicked()), this, SLOT(showFirstMenu()));
	connect(back, SIGNAL(clicked()), this, SLOT(hideOptionsWindow()));
}

void MenuWindow::showOnePlayerWindow()
{
	layoutPrincipal->setColumnStretch(5, 20);
	layoutPrincipal->setSpacing(10);
	numberPlayer = 1;
	hideFirstMenu();
	nom1->show();
	numGames->show();
	m_slider->show();
	m_lcd->show();
	joueur1->show();
	ok->show();
	//connect(ok, SIGNAL(clicked()), this->parent(), SLOT(gameWindow()));
}

void MenuWindow::showTwoPlayersWindow()
{
	layoutPrincipal->setColumnStretch(5, 20);
	layoutPrincipal->setSpacing(10);
	numberPlayer = 2;
	hideFirstMenu();
	nom1_2->show();
	numGames_2->show();
	m_slider_2->show();
	m_lcd_2->show();
	joueur1_2->show();
	ok_2->show();
	nom2->show();
	joueur2->show();
	//connect(ok_2, SIGNAL(clicked()), this->parent(), SLOT(gameWindow()));
}

void MenuWindow::set_Menu()
{
	setDisabled(false);
	connect(addCharacter, SIGNAL(hovered(MenuButton*)), this, SLOT(setOptionsHoveredButton(MenuButton*)));
	connect(createNewList, SIGNAL(hovered(MenuButton *)), this, SLOT(setOptionsHoveredButton(MenuButton*)));
	connect(changeList, SIGNAL(hovered(MenuButton *)), this, SLOT(setOptionsHoveredButton(MenuButton*)));
	connect(back, SIGNAL(hovered(MenuButton *)), this, SLOT(setOptionsHoveredButton(MenuButton*)));
}
