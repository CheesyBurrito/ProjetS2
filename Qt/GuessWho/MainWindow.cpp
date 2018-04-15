#include "MainWindow.h"

MainWindow::MainWindow() : QMainWindow()
{
	showFullScreen();
	//show();
	setWindowTitle("Guess Who?");
	setStyleSheet("background-image: url(./Photos/header_logo.png)");

	start = new StartWindow(this);
	connect(this, SIGNAL(keyPressed()), this, SLOT(deleteStart()));
	setCentralWidget(start);
	menu = new MenuWindow(this);
}

MainWindow::~MainWindow()
{
	delete menu;
}

void MainWindow::deleteStart()
{
	disconnect(this, SIGNAL(keyPressed()), this, SLOT(deleteStart()));
	start->close();
	delete start;
	connect(menu->getOkOnePlayerButton(), SIGNAL(clicked()), this, SLOT(gameWindow()));
	connect(menu->getOkTwoPlayersButton(), SIGNAL(clicked()), this, SLOT(gameWindow()));
	showMenuWindow();
}

void MainWindow::showMenuWindow()
{
	setCentralWidget(menu);
	menu->showMainMenu();
}

void MainWindow::gameWindow()
{
	menu->hide();
	takeCentralWidget();
	game = new GameWindow(this);
	setCentralWidget(game);
	numberGames = menu->getNumberGames();
	joueur1Name = menu->getPlayer1Name();
	joueur2Name = menu->getPlayer2Name();
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
	emit keyPressed();
	if (event->key() == Qt::Key_Escape) {
		emit escapeKeyPressed();
	}
}

void MainWindow::returnToMenu() {
	this->game->getPauseMenu()->hide();
	int answer = QMessageBox::question(NULL, "Quitter la partie", "Ceci entraînera la fin de la partie, voulez-vous vraiment quitter?", QMessageBox::Yes | QMessageBox::No);
	if (answer == QMessageBox::Yes) { //Yes
		this->game->getPauseMenu()->close();
		this->game->close();
		delete game;
		this->showMenuWindow();
	}
	else { //No
		this->game->getPauseMenu()->show();
	}
}

void MainWindow::quitGame() {
	this->game->getPauseMenu()->hide();
	int answer = QMessageBox::question(NULL, "Quitter la partie", "Voulez-vous vraiment quitter la partie", QMessageBox::Yes | QMessageBox::No);
	if (answer == QMessageBox::Yes) { //Yes
		this->close();
		this->game->getPauseMenu()->close();
	}
	else { //No
		this->game->getPauseMenu()->show();
	}
}