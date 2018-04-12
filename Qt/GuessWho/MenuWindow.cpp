#include "MenuWindow.h"

MenuWindow::MenuWindow(QWidget* parent, CharacterManager* characterManager) : QWidget(parent)
{
	c_manager = characterManager;
	widthImage = parent->width() - 520;
	heightImage = parent->height() * 2 / 3;
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

	optionsMenu->hide();
	onePlayerMenu->hide();
	twoPlayersMenu->hide();

	setLayout(layout);
}

void MenuWindow::setOnePlayerGame()
{
	player1Name = onePlayerMenu->getPlayer1Name();
	player2Name = "AI";
	numberGames = onePlayerMenu->getNumberGames();
	numberPlayers = 1;
}

void MenuWindow::setTwoPlayersGame()
{
	player1Name = twoPlayersMenu->getPlayer1Name();
	player1Name = twoPlayersMenu->getPlayer2Name();
	numberGames = twoPlayersMenu->getNumberGames();
	numberPlayers = 2;
}

void MenuWindow::showMainMenu()
{
	this->show();
	optionsMenu->hide();
	onePlayerMenu->hide();
	twoPlayersMenu->hide();
	mainMenu->show();

}