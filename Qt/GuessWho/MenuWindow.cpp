/****************************************
GuessWho ProjetS2 - APP7Gi

P14
William Adam-Grenier - adaw2602
Charles Quesnel - quec2502
Maxime St-Onge - stom2105

Avril 2018

MenuWindow.cpp
*****************************************/

#include "MenuWindow.h"

MenuWindow::MenuWindow(QWidget* parent, CharacterManager* characterManager) : QWidget(parent)
{
	c_manager = characterManager;
	widthImage = parent->width() - 620;
	heightImage = parent->height();

	settingLoadingMenu();
	createMenuWindow();
}

MenuWindow::~MenuWindow()
{
}

void MenuWindow::createMenuWindow()
{

	setWindowTitle("Guess Who?");
	setStyleSheet("background-image: url(./Photos/header_logo.png)");

	layout = new QHBoxLayout(this);
	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(0);

	image = new QLabel(this);
	QPixmap logo("./Photos/logo.png");
	image->setPixmap(logo.scaled(widthImage, heightImage, Qt::KeepAspectRatio));

	mainMenu = new MainMenu(this);
	optionsMenu = new OptionsMenu(this, c_manager);
	onePlayerMenu = new OnePlayerMenu(this);
	twoPlayersMenu = new TwoPlayersMenu(this);


	layout->addWidget(image);
	layout->addWidget(mainMenu);

	connect(mainMenu->getOnePlayerButton(), SIGNAL(clicked()), mainMenu, SLOT(hide()));
	connect(mainMenu->getOnePlayerButton(), SIGNAL(clicked()), onePlayerMenu, SLOT(show()));
	connect(mainMenu->getTwoPlayersButton(), SIGNAL(clicked()), mainMenu, SLOT(hide()));
	connect(mainMenu->getTwoPlayersButton(), SIGNAL(clicked()), twoPlayersMenu, SLOT(show()));
	connect(mainMenu->getOptionsButton(), SIGNAL(clicked()), mainMenu, SLOT(hide()));
	connect(mainMenu->getOptionsButton(), SIGNAL(clicked()), optionsMenu, SLOT(show()));
	connect(mainMenu->getQuitButton(), SIGNAL(clicked()), this->parent(), SLOT(close()));

	layout->addWidget(optionsMenu);

	connect(optionsMenu->getAddCharacterButton(), SIGNAL(clicked()), optionsMenu, SLOT(addCharacters()));
	connect(optionsMenu->getCreateNewListButton(), SIGNAL(clicked()), optionsMenu, SLOT(newList()));
	connect(optionsMenu->getChangeListButton(), SIGNAL(clicked()), optionsMenu, SLOT(showDialog()));
	connect(optionsMenu->getBackButton(), SIGNAL(clicked()), optionsMenu, SLOT(hide()));
	connect(optionsMenu->getBackButton(), SIGNAL(clicked()), mainMenu, SLOT(show()));

	layout->addWidget(onePlayerMenu);
	connect(onePlayerMenu->getOkButton(), SIGNAL(clicked()), this, SLOT(setOnePlayerGame()));

	layout->addWidget(twoPlayersMenu);
	connect(twoPlayersMenu->getOkButton(), SIGNAL(clicked()), this, SLOT(setTwoPlayersGame()));

	layout->addWidget(loading);

	optionsMenu->hide();
	onePlayerMenu->hide();
	twoPlayersMenu->hide();

	setLayout(layout);
}

void MenuWindow::settingLoadingMenu()
{
	loading = new QWidget(this);
	loadingImage = new QLabel(loading);
	loadingLayout = new QHBoxLayout(loading);
	QPixmap logo("./Photos/loading.png");
	loadingImage->setPixmap(logo.scaled(620, 1080, Qt::KeepAspectRatio));
	loadingLayout->addWidget(loadingImage);
	loadingLayout->setContentsMargins(0, 0, 0, 0);
	loadingLayout->setSpacing(0);
	loadingLayout->setAlignment(Qt::AlignCenter);
	loading->setStyleSheet("background: transparent;");
	loading->setLayout(loadingLayout);
	loading->hide();
}

void MenuWindow::setOnePlayerGame()
{
	player1Name = onePlayerMenu->getPlayer1Name();
	player2Name = "AI";
	numberPlayers = 1;
	numGames = onePlayerMenu->getNumGames();
	onePlayerMenu->hide();
	loading->show();
}

void MenuWindow::setTwoPlayersGame()
{
	player1Name = twoPlayersMenu->getPlayer1Name();
	player2Name = twoPlayersMenu->getPlayer2Name();
	numberPlayers = 2;
	numGames = twoPlayersMenu->getNumGames();
	twoPlayersMenu->hide();
	loading->show();
}

void MenuWindow::showMainMenu()
{
	this->show();
	optionsMenu->hide();
	onePlayerMenu->hide();
	twoPlayersMenu->hide();
	loading->hide();
	mainMenu->show();
	connect(this->parent(), SIGNAL(escapeKeyPressed()), this, SLOT(showMainMenu()));
}