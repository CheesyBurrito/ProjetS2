#include "MainWindow.h"

MainWindow::MainWindow() : QMainWindow()
{
	setWindowTitle("Guess Who?");
	//setWindowFlags(Qt::WindowStaysOnTopHint);

	start = new StartWindow();
	setCentralWidget(start);
	QObject::connect(start->getButton(), SIGNAL(clicked()), this, SLOT(openMenu()));

}

MainWindow::~MainWindow()
{
	delete menu;
}

void MainWindow::openMenu()
{
	/*menu = new MenuWindow();
	setCentralWidget(menu);
	start->close();
	delete start;
	QObject::connect(menu->getOnePlayerButton(), SIGNAL(clicked()), this, SLOT(onePlayerWindow()));
	QObject::connect(menu->getTwoPlayersButton(), SIGNAL(clicked()), this, SLOT(twoPlayersWindow()));
	QObject::connect(menu->getQuitButton(), SIGNAL(clicked()), this, SLOT(close()));*/

	game = new GameWindow(this);
	setCentralWidget(game);
	start->close();
	delete start;
}

void MainWindow::onePlayerWindow()
{
	menu->onePlayerWindow();
}


void MainWindow::twoPlayersWindow()
{
	menu->twoPlayersWindow();
}