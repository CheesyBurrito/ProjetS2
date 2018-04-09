#include "MainWindow.h"

MainWindow::MainWindow() : QMainWindow()
{
	showFullScreen();
	//show();
	setWindowTitle("Guess Who?");
	setStyleSheet("background-image: url(./Photos/header_logo.png)");

	start = new StartWindow(this);
	connect(this, SIGNAL(keyPressed()), this, SLOT(openMenu()));
	setCentralWidget(start);
	menu = new MenuWindow(this);

}

MainWindow::~MainWindow()
{
	//delete menu;
	//delete game;
}

void MainWindow::openMenu()
{
	disconnect(this, SIGNAL(keyPressed()), this, SLOT(openMenu()));
	setCentralWidget(menu);
	start->close();
	delete start;
	QObject::connect(menu->getOnePlayerButton(), SIGNAL(clicked()), this, SLOT(onePlayerWindow()));
	QObject::connect(menu->getTwoPlayersButton(), SIGNAL(clicked()), this, SLOT(twoPlayersWindow()));
	QObject::connect(menu->getOptionsButton(), SIGNAL(clicked()), this, SLOT(optionsWindow()));
	QObject::connect(menu->getQuitButton(), SIGNAL(clicked()), this, SLOT(close()));
}

void MainWindow::menuWindow()
{
	menu->deleteOptionsWindow();
	menu->startMenu();
	QObject::connect(menu->getOnePlayerButton(), SIGNAL(clicked()), this, SLOT(onePlayerWindow()));
	QObject::connect(menu->getTwoPlayersButton(), SIGNAL(clicked()), this, SLOT(twoPlayersWindow()));
	QObject::connect(menu->getOptionsButton(), SIGNAL(clicked()), this, SLOT(optionsWindow()));
	QObject::connect(menu->getQuitButton(), SIGNAL(clicked()), this, SLOT(close()));
}

void MainWindow::menuWindowFromGame()
{
	menu = new MenuWindow(this);
	game->close();
	setCentralWidget(menu);
	QObject::connect(menu->getOnePlayerButton(), SIGNAL(clicked()), this, SLOT(onePlayerWindow()));
	QObject::connect(menu->getTwoPlayersButton(), SIGNAL(clicked()), this, SLOT(twoPlayersWindow()));
	QObject::connect(menu->getOptionsButton(), SIGNAL(clicked()), this, SLOT(optionsWindow()));
	QObject::connect(menu->getQuitButton(), SIGNAL(clicked()), this, SLOT(close()));
	delete game;
}

void MainWindow::onePlayerWindow()
{
	numberPlayer = 1;
	menu->onePlayerWindow();
	QObject::connect(menu->getOkButton(), SIGNAL(clicked()), this, SLOT(gameWindow()));
}

void MainWindow::twoPlayersWindow()
{
	numberPlayer = 2;
	menu->twoPlayersWindow();
	QObject::connect(menu->getOkButton(), SIGNAL(clicked()), this, SLOT(gameWindow()));
}

void MainWindow::optionsWindow()
{
	menu->optionsWindow();
	QObject::connect(menu->getAddCharacterButton(), SIGNAL(clicked()), menu, SLOT(addCharacters()));
	QObject::connect(menu->getCreateNewListButton(), SIGNAL(clicked()), this, SLOT(menuWindow()));
	QObject::connect(menu->getChangeListButton(), SIGNAL(clicked()), menu, SLOT(showDialog()));
	QObject::connect(menu->getBackButton(), SIGNAL(clicked()), this, SLOT(menuWindow()));
}


void MainWindow::gameWindow()
{
	game = new GameWindow(this);
	setCentralWidget(game);
	numberGames = menu->getNumberGames();

	if (numberPlayer == 2)
	{
		joueur1Name = menu->getJoueur1Name();
		joueur2Name = menu->getJoueur2Name();
	}
	else
	{
		joueur1Name = menu->getJoueur1Name();
		joueur2Name = "AI";
	}
	menu->deletePlayersWindow();
	menu->close();
	delete menu;

}

void MainWindow::keyPressEvent(QKeyEvent *event) {
	emit keyPressed();
	if (event->key() == Qt::Key_Escape) {
		emit escapeKeyPressed();
	}
}

void MainWindow::quitGame() {
	this->game->getPauseMenu()->hide();
	int answer = QMessageBox::question(NULL, "Quitter la partie", "Voulez-vous vraiment quitter la partie", QMessageBox::Yes | QMessageBox::No);
	if (answer == QMessageBox::Yes) { //Yes
		this->game->getPauseMenu()->close();
		this->menuWindowFromGame();
	}
	else { //No
		this->game->getPauseMenu()->show();
	}
}