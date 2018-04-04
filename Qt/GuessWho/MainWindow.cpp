#include "MainWindow.h"

MainWindow::MainWindow() : QMainWindow()
{
	showFullScreen();
	setWindowTitle("Guess Who?");

	start = new StartWindow(this);
	setCentralWidget(start);
	QObject::connect(start->getButton(), SIGNAL(clicked()), this, SLOT(openMenu()));

}

MainWindow::~MainWindow()
{
	delete menu;
	//delete game;
}

void MainWindow::openMenu()
{
	menu = new MenuWindow(this);
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
	QObject::connect(menu->getAddCharacterButton(), SIGNAL(clicked()), this, SLOT(menuWindow()));
	QObject::connect(menu->getListCharacterButton(), SIGNAL(clicked()), this, SLOT(menuWindow()));
	QObject::connect(menu->getExportCharacterButton(), SIGNAL(clicked()), this, SLOT(menuWindow()));
	QObject::connect(menu->getBackButton(), SIGNAL(clicked()), this, SLOT(menuWindow()));
}

void MainWindow::gameWindow()
{
	//game = new MenuGame(this);
	//setCentralWidget(game);
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
	qDebug() << joueur1Name;
	qDebug() << joueur2Name;
	qDebug() << numberGames;
	menu->deletePlayersWindow();
	menu->close();
	delete menu;

}