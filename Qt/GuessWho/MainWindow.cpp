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
}

void MainWindow::openMenu()
{
	menu = new MenuWindow(this);
	setCentralWidget(menu);
	start->close();
	delete start;
	QObject::connect(menu->getOnePlayerButton(), SIGNAL(clicked()), this, SLOT(onePlayerWindow()));
	QObject::connect(menu->getTwoPlayersButton(), SIGNAL(clicked()), this, SLOT(twoPlayersWindow()));
	QObject::connect(menu->getQuitButton(), SIGNAL(clicked()), this, SLOT(close()));
}

void MainWindow::onePlayerWindow()
{
	menu->onePlayerWindow();
}


void MainWindow::twoPlayersWindow()
{
	menu->twoPlayersWindow();
}