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
	settingMainWindow();
	creatingObjects();
	connectSignals();
	settingWidgets();
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
	menu->hide();
}

void MainWindow::settingMainWindow()
{
	//Setting the MainWindow
	setWindowTitle("Guess Who?");
	setStyleSheet("background-image: url(./Photos/header_logo.png)");
	this->setGeometry(100, 100, 1366, 768);
	//showFullScreen();
	show();
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
	menu->show();
	setCentralWidget(menu);
	menu->showMainMenu();
}

void MainWindow::gameWindow()
{
	//GAME LOGIC *******************
	gameLogic->get_character_manager()->importCharacters(menu->getOptionsMenu()->getActiveList().toStdString());
	gameLogic->get_character_manager()->shuffleCharacters();
	gameLogic->get_character_manager()->printProperties();

	//This line is crucial, because it allows the other character manger to know what is the order
	cout << gameLogic->get_character_manager()->exportCharacters(menu->getOptionsMenu()->getActiveList().toStdString());
	//gameLogic->get_character_manager().printProperties();
	gameLogic->copyCharacterManagerToPlayer(gameLogic->getPlayer1(), menu->getOptionsMenu()->getActiveList().toStdString());
	gameLogic->copyCharacterManagerToPlayer(gameLogic->getPlayer2(), menu->getOptionsMenu()->getActiveList().toStdString());
	//gameLogic->getPlayer1Reference()->set_name_of_player(menu->);


	//GUI ************************
	menu->hide();
	takeCentralWidget();
	game = new GameWindow(this);
	setCentralWidget(game);
	numberGames = menu->getNumberGames();
	player1Name = menu->getPlayer1Name();
	player2Name = menu->getPlayer2Name();
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