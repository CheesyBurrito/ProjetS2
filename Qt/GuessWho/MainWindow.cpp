#include "MainWindow.h"

MainWindow::MainWindow() : QMainWindow()
{
	constructorLogic();
}

MainWindow::~MainWindow()
{
	delete menu;
}

void MainWindow::constructorLogic()
{
	creatingObjects();
	connectSignals();
	settingWidgets();
	settingMainWindow();
}

void MainWindow::creatingObjects()
{
	//Creating the objects for the GUI and Game
	start = new StartWindow(this);
	gameLogic = new Games();
	menu = new MenuWindow(this);
}

void MainWindow::connectSignals()
{
	//Connecting the signals
	connect(this, SIGNAL(keyPressed()), this, SLOT(deleteStart()));
}

void MainWindow::settingWidgets()
{
	//Setting the widgets
	setCentralWidget(start);
}

void MainWindow::settingMainWindow()
{
	//Setting the MainWindow
	setWindowTitle("Guess Who?");
	setStyleSheet("background-image: url(./Photos/header_logo.png)");
	//showFullScreen();
	show();
}

void MainWindow::deleteStart()
{
	disconnect(this, SIGNAL(keyPressed()), this, SLOT(deleteStart()));
	start->close();
	delete start;
	showMenuWindow();
}

void MainWindow::showMenuWindow()
{
	setCentralWidget(menu);
	menu->showFirstMenu();
}

void MainWindow::gameWindow()
{
	gameLogic->get_character_manager()->importCharacters(menu->getActiveList().toStdString());
	gameLogic->get_character_manager()->shuffleCharacters();
	gameLogic->get_character_manager()->printProperties();

	//This line is crucial, because it allows the other character manger to know what is the order
	cout << gameLogic->get_character_manager()->exportCharacters(menu->getActiveList().toStdString());
	//gameLogic->get_character_manager().printProperties();
	gameLogic->copyCharacterManagerToPlayer(gameLogic->getPlayer1(), menu->getActiveList().toStdString());
	gameLogic->copyCharacterManagerToPlayer(gameLogic->getPlayer2(), menu->getActiveList().toStdString());
	//gameLogic->getPlayer1Reference()->set_name_of_player(menu->);
	takeCentralWidget();
	game = new GameWindow(this);
	setCentralWidget(game);
	if (menu->getNumberPlayer() == 2)
	{
		numberGames = menu->getNumberGames_2();
		joueur1Name = menu->getJoueur1_2Name();
		joueur2Name = menu->getJoueur2Name();
		menu->hideTwoPlayersWindow();
	}
	else
	{
		numberGames = menu->getNumberGames();
		joueur1Name = menu->getJoueur1Name();
		joueur2Name = "AI";
		menu->hideOnePlayerWindow();
	}
	//menu->hide();
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