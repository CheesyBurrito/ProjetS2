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
	menu = new MenuWindow(this, gameLogic->get_character_manager());
	//Loading the default character list
	gameLogic->get_character_manager()->importCharacters
	(menu->getOptionsMenu()->getActiveList().toStdString());
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
	showFullScreen();
	//show();
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
	
	//Checks if enough characters in the vector if not -> error
	if (gameLogic->get_character_manager()->get_character_vector().size() < 20) {
		QMessageBox::critical(NULL, "Erreur", "Il n'y a pas assez de personnages dans la liste (minimum 20)", QMessageBox::Ok);
		menu->showMainMenu();
		return;
	}

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
	player1GameWindow = new GameWindow(this, gameLogic->getPlayer1().get_board_of_player()->get_character_manager());
	setCentralWidget(player1GameWindow);
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

void MainWindow::returnToMenu(GameWindow* caller) {
	caller->getPauseMenu()->hide();
	int answer = QMessageBox::question(NULL, "Quitter la partie", "Ceci entraînera la fin de la partie, voulez-vous vraiment quitter?", QMessageBox::Yes | QMessageBox::No);
	if (answer == QMessageBox::Yes) { //Yes
		this->player1GameWindow->getPauseMenu()->close();
		this->player1GameWindow->close();
		delete player1GameWindow;
		this->player2GameWindow->getPauseMenu()->close();
		this->player2GameWindow->close();
		delete player2GameWindow;
		this->showMenuWindow();
	}
	else { //No
		caller->getPauseMenu()->show();
	}
}

void MainWindow::quitGame(GameWindow* caller) {
	caller->getPauseMenu()->hide();
	int answer = QMessageBox::question(NULL, "Quitter la partie", "Voulez-vous vraiment quitter la partie", QMessageBox::Yes | QMessageBox::No);
	if (answer == QMessageBox::Yes) { //Yes
		this->close();
		caller->getPauseMenu()->close();
	}
	else { //No
		caller->getPauseMenu()->show();
	}
}

void MainWindow::questionMenuSetup()
{
	game->getSideMenu()->getQuestionMenuBar();
}