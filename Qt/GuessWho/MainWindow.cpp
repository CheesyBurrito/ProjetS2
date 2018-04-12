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
	electroCabello = new QSound("./Sounds/Electro_Cabello.wav", this);
	epicSaxGuy = new QSound("./Sounds/epicsaxguy.wav", this);
	luckyDay = new QSound("./Sounds/Jingle-Punks-Lucky-Day.wav", this);
	weAreOne = new QSound("./Sounds/Vexento-WeAreOne.wav", this);
	adventures = new QSound("./Sounds/adventures-A-Himitsu.wav", this);
	summer = new QSound("./Sounds/bensound-summer.wav", this);
	carefree = new QSound("./Sounds/Kevin_MacLeod_-_Carefree.wav", this);
	electroCabello->setLoops(QSound::Infinite);
	epicSaxGuy->setLoops(QSound::Infinite);
	luckyDay->setLoops(QSound::Infinite);
	weAreOne->setLoops(QSound::Infinite);
	adventures->setLoops(QSound::Infinite);
	summer->setLoops(QSound::Infinite);
	carefree->setLoops(QSound::Infinite);
	activeSong = "electroCabello";
	electroCabello->play();
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
	//gameLogic->get_character_manager()->importCharacters(menu->getOptionsMenu()->getActiveList().toStdString());

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
	disconnect(this, SIGNAL(escapeKeyPressed()), menu, SLOT(showMainMenu()));
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

void MainWindow::nextSong()
{
	if (activeSong == "electroCabello")
	{
		electroCabello->stop();
		epicSaxGuy->play();
		activeSong = "epicSaxGuy";
	}
	else if (activeSong == "epicSaxGuy")
	{
		epicSaxGuy->stop();
		luckyDay->play();
		activeSong = "luckyDay";
	}
	else if (activeSong == "luckyDay")
	{
		luckyDay->stop();
		weAreOne->play();
		activeSong = "weAreOne";
	}
	else if (activeSong == "weAreOne")
	{
		weAreOne->stop();
		adventures->play();
		activeSong = "adventures";
	}
	else if (activeSong == "adventures")
	{
		adventures->stop();
		summer->play();
		activeSong = "summer";
	}
	else if (activeSong == "summer")
	{
		summer->stop();
		carefree->play();
		activeSong = "carefree";
	}
	else if (activeSong == "carefree")
	{
		carefree->stop();
		electroCabello->play();
		activeSong = "electroCabello";
	}
}
	
	

void  MainWindow::prevSong()
{
	if (activeSong == "electroCabello")
	{
		electroCabello->stop();
		carefree->play();
		activeSong = "carefree";
	}
	else if (activeSong == "carefree")
	{
		carefree->stop();
		summer->play();
		activeSong = "summer";
	}
	else if (activeSong == "summer")
	{
		summer->stop();
		adventures->play();
		activeSong = "adventures";
	}
	else if (activeSong == "adventures")
	{
		adventures->stop();
		weAreOne->play();
		activeSong = "weAreOne";
	}
	else if (activeSong == "weAreOne")
	{
		weAreOne->stop();
		luckyDay->play();
		activeSong = "luckyDay";
	}
	else if (activeSong == "luckyDay")
	{
		luckyDay->stop();
		epicSaxGuy->play();
		activeSong = "epicSaxGuy";
	}
	else if (activeSong == "epicSaxGuy")
	{
		epicSaxGuy->stop();
		electroCabello->play();
		activeSong = "electroCabello";
	}
}