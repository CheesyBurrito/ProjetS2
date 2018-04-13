/****************************************
GuessWho ProjetS2 - APP7Gi

P14
William Adam-Grenier - adaw2602
Charles Quesnel - quec2502
Maxime St-Onge - stom2105

Avril 2018

MainWindow.cpp
*****************************************/

#include "MainWindow.h"
#include <QDebug>

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
	settingSounds();
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
	gameLogic->get_character_manager()->importCharacters(menu->getOptionsMenu()->getActiveList().toStdString());
}

void MainWindow::connectSignals()
{
	//Connecting the signals
	connect(this, SIGNAL(keyPressed()), this, SLOT(deleteStart()));
	connect(menu->getNextButton(), SIGNAL(clicked()), this, SLOT(nextSong()));
	connect(menu->getPrevButton(), SIGNAL(clicked()), this, SLOT(prevSong()));
	connect(menu->getMuteButton(), SIGNAL(clicked()), this, SLOT(playPause()));
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
	this->setGeometry(100, 100, 1300, 600);
	showFullScreen();
	//show();
}

void MainWindow::settingSounds() 
{
	songNames.push_back("Electro Cabello - Kevin MacLeod");
	songNames.push_back("Epic Sax Guy");
	songNames.push_back("Shooting Stars");
	songNames.push_back("Summer - Bensound");
	songNames.push_back("Adventures - A Himitsu");
	songNames.push_back("We Are One - Vexento");
	songNames.push_back("Lucky Day - Jingle Punks");
	songNames.push_back("Carefree - Kevin MacLeod");

	for (int i = 0; i < songNames.size(); i++)
	{
		songPlaylist.push_back(new QSound(defaultSongPath + songNames.at(i) + soundsFileExtension, this));
		songPlaylist.at(i)->setLoops(QSound::Infinite);
	}

	//Starts the last song
	activeSong = 0;
	songPlaylist.at(activeSong)->play();
	menu->getActiveSongLabel()->setText(songNames.at(activeSong));
	play = true;
	
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
	gameLogic->reinitializeBoard();
	//gameLogic->getPlayer1Reference()->set_name_of_player(menu->);


	//GUI ************************
	menu->hide();
	takeCentralWidget();

	player1GameWindow = new GameWindow(this, gameLogic->getPlayer1Reference());
	player2GameWindow = new GameWindow(this, gameLogic->getPlayer2Reference());
	gameWindowCreate = true;

	//connect media player
	player1GameWindow->getActiveSongLabel()->setText(songNames.at(activeSong));
	if (play == true)
		player1GameWindow->getMuteButton()->setStyleSheet("background-image: url(./Photos/soundon.png);");
	else
		player1GameWindow->getMuteButton()->setStyleSheet("background-image: url(./Photos/soundoff.png);");
	connect(player1GameWindow->getNextButton(), SIGNAL(clicked()), this, SLOT(nextSong()));
	connect(player1GameWindow->getPrevButton(), SIGNAL(clicked()), this, SLOT(prevSong()));
	connect(player1GameWindow->getMuteButton(), SIGNAL(clicked()), this, SLOT(playPause()));
	
	connect(this, SIGNAL(wKeyPressed()), player1GameWindow->getSideMenu()->getQuestionMenuBar(), SLOT(goUpTreeWidgetItem()));
	connect(this, SIGNAL(sKeyPressed()), player1GameWindow->getSideMenu()->getQuestionMenuBar(), SLOT(goDownTreeWidgetItem()));
	//connect(this, SIGNAL(enterKeyPressed()), player1GameWindow->getSideMenu()->getQuestionMenuBar(), SLOT(treeWidgetItemClicked()));

	//Connects the pause menu buttons
	connect(this, SIGNAL(escapeKeyPressed()), player1GameWindow, SLOT(togglePauseMenu()));
	connect(player1GameWindow->getPauseMenu(), SIGNAL(escapeKeyPressed()), player1GameWindow, SLOT(togglePauseMenu()));
	numberGames = menu->getNumberGames();
	player1Name = menu->getPlayer1Name();

	if (menu->getNumberPlayers() == 1) { //Second player is AI 
		player1Name = menu->getPlayer1Name();
		player2Name = "BOT";
		secondPlayerIsBot = true;
		gameLogic->getPlayer2Reference()->set_is_cpu(true);
	}
	else {
		player2Name = menu->getPlayer2Name();
		secondPlayerIsBot = false;
	}

	p1_chooseCharacter();
	disconnect(this, SIGNAL(escapeKeyPressed()), menu, SLOT(showMainMenu()));
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
	emit keyPressed();
	if (event->key() == Qt::Key_Escape) {
		emit escapeKeyPressed();
	}
	if(event->key() == Qt::Key_W)
	{
		emit wKeyPressed();
	}
	if (event->key() == Qt::Key_S)
	{
		emit sKeyPressed();
	}
	/*
	if (event->key() == Qt::Key_Enter)
	{
		cout << "Hey there!" << endl;
		emit enterKeyPressed();
	}*/
}

void MainWindow::returnToMenu() {
	this->player1GameWindow->getPauseMenu()->hide();
	int answer = QMessageBox::question(NULL, "Quitter la partie", "Ceci entraînera la fin de la partie, voulez-vous vraiment quitter?", QMessageBox::Yes | QMessageBox::No);
	if (answer == QMessageBox::Yes) { //Yes
		disconnect(this, SIGNAL(escapeKeyPressed()), player1GameWindow, SLOT(togglePauseMenu()));
		disconnect(player1GameWindow->getPauseMenu(), SIGNAL(escapeKeyPressed()), player1GameWindow, SLOT(togglePauseMenu()));

		this->player1GameWindow->getPauseMenu()->close();
		this->player1GameWindow->close();
		delete player1GameWindow;
		this->player2GameWindow->getPauseMenu()->close();
		this->player2GameWindow->close();
		delete player2GameWindow;
		this->showMenuWindow();
		gameWindowCreate = false;
	}
	else { //No
		this->player1GameWindow->getPauseMenu()->show();
	}
}

void MainWindow::quitGame() {
	this->player1GameWindow->getPauseMenu()->hide();
	int answer = QMessageBox::question(NULL, "Quitter la partie", "Voulez-vous vraiment quitter la partie", QMessageBox::Yes | QMessageBox::No);
	if (answer == QMessageBox::Yes) { //Yes
		this->close();
		this->player1GameWindow->getPauseMenu()->close();
	}
	else { //No
		this->player1GameWindow->getPauseMenu()->show();
	}
}

void MainWindow::nextSong()
{
	songPlaylist.at(activeSong)->stop();
	activeSong++;
	if (activeSong > songPlaylist.size() - 1) {
		activeSong = 0;
	}
	if(play)
		songPlaylist.at(activeSong)->play();
	menu->getActiveSongLabel()->setText(songNames.at(activeSong));
	if(gameWindowCreate)
		player1GameWindow->getActiveSongLabel()->setText(songNames.at(activeSong));
}
	
void  MainWindow::prevSong()
{
	songPlaylist.at(activeSong)->stop();
	activeSong--;
	if (activeSong < 0) {
		activeSong = songPlaylist.size() - 1;
	}
	if (play)
		songPlaylist.at(activeSong)->play();
	menu->getActiveSongLabel()->setText(songNames.at(activeSong));
	if (gameWindowCreate)
		player1GameWindow->getActiveSongLabel()->setText(songNames.at(activeSong));
}

void MainWindow::playPause()
{
	if (play == false)
	{
		songPlaylist.at(activeSong)->play();
		play = true;
		if (gameWindowCreate)
			player1GameWindow->getMuteButton()->setStyleSheet("background-image: url(./Photos/soundon.png);");
		menu->getMuteButton()->setStyleSheet("background-image: url(./Photos/soundon.png);");
	}
	else
	{
		songPlaylist.at(activeSong)->stop();
		play = false;
		if (gameWindowCreate)
			player1GameWindow->getMuteButton()->setStyleSheet("background-image: url(./Photos/soundoff.png);");
		menu->getMuteButton()->setStyleSheet("background-image: url(./Photos/soundoff.png);");
	}
}

void MainWindow::questionMenuSetup()
{
	player1GameWindow->getSideMenu()->getQuestionMenuBar();
}

std::string MainWindow::convertBoolToString(bool answer) {
	if (answer == true)
		return "Oui";
	else
		return "Non";
}

void MainWindow::p1_chooseCharacter() {
	setCentralWidget(player1GameWindow);

	player1GameWindow->getLowerBar()->changeText(player1Name.toStdString() + " : Veuillez choisir votre personnage", OK_MODE);
	player1GameWindow->toggleSelectMode();
	connect(player1GameWindow->getLowerBar()->getOkButton(), SIGNAL(clicked()), this, SLOT(p2_chooseCharacter()));
}

void MainWindow::p2_chooseCharacter() {
	player1GameWindow->toggleSelectMode(); //Resets to normal mode
	player2GameWindow->toggleSelectMode(); //Sets to select mode
	disconnect(player1GameWindow->getLowerBar()->getOkButton(), SIGNAL(clicked()), this, SLOT(p2_chooseCharacter()));
	if (secondPlayerIsBot) {
		gameLogic->getPlayer2Reference()->generateRandomCharacter();
		p1_askFirstQuestion();
	}
	else {
		player1GameWindow->hide();
		takeCentralWidget();
		setCentralWidget(player2GameWindow);
		player2GameWindow->show();

		player2GameWindow->getLowerBar()->changeText(player2Name.toStdString() + " : Veuillez choisir votre personnage", OK_MODE);
		connect(player2GameWindow->getLowerBar()->getOkButton(), SIGNAL(clicked()), this, SLOT(p1_askFirstQuestion()));
	}
}

void MainWindow::p1_askFirstQuestion() {
	if (!secondPlayerIsBot) {
		player2GameWindow->hide();
		takeCentralWidget();
		setCentralWidget(player1GameWindow);
		player1GameWindow->show();

		player1GameWindow->getGrid()->getCharacters()->at(20)->flipCard();
		player2GameWindow->getGrid()->getCharacters()->at(20)->flipCard();
	}

	if (player2GameWindow->getSelectMode() == true)
		player2GameWindow->toggleSelectMode(); //Resets to normal mode

	player1GameWindow->getLowerBar()->changeText(player1Name.toStdString() + " : Veuillez poser votre question", EMPTY_MODE);

	gameLogic->getPlayer1Reference()->up_num_turn();
	connectP1ToTree();
}

void MainWindow::p1_askQuestion() {
	player1GameWindow->getLowerBar()->changeText(player1Name.toStdString() + " : Veuillez poser votre question", EMPTY_MODE);

	gameLogic->getPlayer1Reference()->up_num_turn();

	gameLogic->getPlayer1Reference()->get_board_of_player()->get_character_manager()->set_num_character_hidden(
		player1GameWindow->getGrid()->getNbHiddenCharacters());

	connectP1ToTree();
}

void MainWindow::p2_askQuestion() {
	
	gameLogic->getPlayer2Reference()->up_num_turn();

	if (secondPlayerIsBot) {
		p1_answerQuestion(gameLogic->getPlayer2Reference()->cpuQuestionGeneretor(50, gameLogic->getPlayer1()));
	}
	else {
		player2GameWindow->getLowerBar()->changeText(player2Name.toStdString() + " : Veuillez poser votre question", EMPTY_MODE);

		connectP2ToTree();
	}

}

void MainWindow::p2_answerQuestion(std::vector<int> q) {
	disconnectP2ToTree();

	p1_lastQuestion = q;

	if (secondPlayerIsBot) {
		p2_lastAnswer = gameLogic->getAnswerToQuestion(q.at(0), q.at(1), gameLogic->getPlayer1Reference(), gameLogic->getPlayer2Reference());
		p2_getLastAnswer();
	}
	else {
		player2GameWindow->getSideMenu()->setNbHiddenCharacter(player1GameWindow->getGrid()->getNbHiddenCharacters());

		player1GameWindow->hide();
		takeCentralWidget();
		setCentralWidget(player2GameWindow);
		player2GameWindow->show();

		player2GameWindow->getLowerBar()->changeText(player2Name.toStdString() + " : " + gameLogic->convertQuestionToString(q.at(0), q.at(1)), YES_NO_MODE);
		connect(player2GameWindow->getLowerBar()->getYesButton(), SIGNAL(clicked()), this, SLOT(p2_answerQuestionYes()));
		connect(player2GameWindow->getLowerBar()->getNoButton(), SIGNAL(clicked()), this, SLOT(p2_answerQuestionNo()));
	}
}

void MainWindow::p1_answerQuestion(std::vector<int> q) {
	p2_lastQuestion = q;

	if (!secondPlayerIsBot) {
		player2GameWindow->hide();
		takeCentralWidget();
		setCentralWidget(player1GameWindow);
		player1GameWindow->show();

		disconnectP1ToTree();

		player1GameWindow->getSideMenu()->setNbHiddenCharacter(player2GameWindow->getGrid()->getNbHiddenCharacters());
	}
	
		
		player1GameWindow->getLowerBar()->changeText(player1Name.toStdString() + " : " + gameLogic->convertQuestionToString(q.at(0), q.at(1)), YES_NO_MODE);
		connect(player1GameWindow->getLowerBar()->getYesButton(), SIGNAL(clicked()), this, SLOT(p1_answerQuestionYes()));
		connect(player1GameWindow->getLowerBar()->getNoButton(), SIGNAL(clicked()), this, SLOT(p1_answerQuestionNo()));

}

void MainWindow::p2_answerQuestionYes() {
	disconnect(player2GameWindow->getLowerBar()->getYesButton(), SIGNAL(clicked()), this, SLOT(p2_answerQuestionYes()));
	disconnect(player2GameWindow->getLowerBar()->getNoButton(), SIGNAL(clicked()), this, SLOT(p2_answerQuestionNo()));

	p2_lastAnswer = true;
	p2_getLastAnswer();
}

void MainWindow::p2_answerQuestionNo() {
	disconnect(player2GameWindow->getLowerBar()->getYesButton(), SIGNAL(clicked()), this, SLOT(p2_answerQuestionYes()));
	disconnect(player2GameWindow->getLowerBar()->getNoButton(), SIGNAL(clicked()), this, SLOT(p2_answerQuestionNo()));

	p2_lastAnswer = false;
	p2_getLastAnswer();
}

void MainWindow::p1_answerQuestionYes() {
	disconnect(player1GameWindow->getLowerBar()->getYesButton(), SIGNAL(clicked()), this, SLOT(p1_answerQuestionYes()));
	disconnect(player1GameWindow->getLowerBar()->getNoButton(), SIGNAL(clicked()), this, SLOT(p1_answerQuestionNo()));

	p1_lastAnswer = true;
	p1_getLastAnswer();
}

void MainWindow::p1_answerQuestionNo() {
	disconnect(player1GameWindow->getLowerBar()->getYesButton(), SIGNAL(clicked()), this, SLOT(p1_answerQuestionYes()));
	disconnect(player1GameWindow->getLowerBar()->getNoButton(), SIGNAL(clicked()), this, SLOT(p1_answerQuestionNo()));

	p1_lastAnswer = false;
	p1_getLastAnswer();
}

void MainWindow::p2_getLastAnswer() {
	checkEndGameCondition();
	if (winner != "") {
		gameOver(winner);

		return;
	}

	if (secondPlayerIsBot) {
		p2_askQuestion();
	}
	else {
		//If there is a question, show it
		if (p2_lastQuestion.size() > 0) {
			player2GameWindow->getLowerBar()->changeText(player2Name.toStdString() + " : à la question : " +
				gameLogic->convertQuestionToString(p2_lastQuestion.at(0), p2_lastQuestion.at(1)) +
				" la réponse est : " + convertBoolToString(p1_lastAnswer), OK_MODE);

			connect(player2GameWindow->getLowerBar()->getOkButton(), SIGNAL(clicked()), this, SLOT(p2_askQuestion()));
		}
		else {
			p2_askQuestion();
		}
	}
}

void MainWindow::p1_getLastAnswer() {
	checkEndGameCondition();
		if (winner != "") {
			gameOver(winner);
			return;
		}

		if(secondPlayerIsBot) {
			if (p2_lastQuestion.size() > 0) {
				if (p1_lastAnswer == true)
					gameLogic->getPlayer2Reference()->get_board_of_player()->get_character_manager()->hideCharacterAfterQuestion(p2_lastQuestion.at(0), p2_lastQuestion.at(1));
				else
					gameLogic->getPlayer2Reference()->get_board_of_player()->get_character_manager()->hideCharacterAfterQuestionOpposite(p2_lastQuestion.at(0), p2_lastQuestion.at(1));
			}
			player1GameWindow->getSideMenu()->setNbHiddenCharacter(gameLogic->getPlayer2().get_board_of_player()->get_character_manager()->get_num_character_hidden());
		}

		//If there is a question, show it
		if (p1_lastQuestion.size() > 0) {

			player1GameWindow->getLowerBar()->changeText(player1Name.toStdString() + " : à la question : " +
				gameLogic->convertQuestionToString(p1_lastQuestion.at(0), p1_lastQuestion.at(1)) +
				" la réponse est : " + convertBoolToString(p2_lastAnswer), OK_MODE);

			connect(player1GameWindow->getLowerBar()->getOkButton(), SIGNAL(clicked()), this, SLOT(p1_askQuestion()));
		}
		else {
			p1_askQuestion();
		}
}

void MainWindow::connectP1ToTree() {
	connect(player1GameWindow->getSideMenu()->getGuessWhoButton(), SIGNAL(clicked()), player1GameWindow, SLOT(guessWhoMode()));
	connect(player1GameWindow->getSideMenu()->getQuestionMenuBar(), SIGNAL(sendQuestion(std::vector<int>)), this, SLOT(p2_answerQuestion(std::vector<int>)));
	connect(player1GameWindow, SIGNAL(guessWho(std::vector<int>)), this, SLOT(p2_answerQuestion(std::vector<int>)));
}

void MainWindow::disconnectP1ToTree() {
	disconnect(player1GameWindow->getSideMenu()->getGuessWhoButton(), SIGNAL(clicked()), player1GameWindow, SLOT(guessWhoMode()));
	disconnect(player1GameWindow->getSideMenu()->getQuestionMenuBar(), SIGNAL(sendQuestion(std::vector<int>)), this, SLOT(p2_answerQuestion(std::vector<int>)));
	disconnect(player1GameWindow, SIGNAL(guessWho(std::vector<int>)), this, SLOT(p2_answerQuestion(std::vector<int>)));
}

void MainWindow::connectP2ToTree() {
	connect(player2GameWindow->getSideMenu()->getGuessWhoButton(), SIGNAL(clicked()), player2GameWindow, SLOT(guessWhoMode()));
	connect(player2GameWindow->getSideMenu()->getQuestionMenuBar(), SIGNAL(sendQuestion(std::vector<int>)), this, SLOT(p1_answerQuestion(std::vector<int>)));
	connect(player2GameWindow, SIGNAL(guessWho(std::vector<int>)), this, SLOT(p1_answerQuestion(std::vector<int>)));
}

void MainWindow::disconnectP2ToTree() {
	disconnect(player2GameWindow->getSideMenu()->getGuessWhoButton(), SIGNAL(clicked()), player2GameWindow, SLOT(guessWhoMode()));
	disconnect(player2GameWindow->getSideMenu()->getQuestionMenuBar(), SIGNAL(sendQuestion(std::vector<int>)), this, SLOT(p1_answerQuestion(std::vector<int>)));
	disconnect(player2GameWindow, SIGNAL(guessWho(std::vector<int>)), this, SLOT(p1_answerQuestion(std::vector<int>)));
}

void MainWindow::gameOver(QString winner) {

	player1GameWindow->togglePauseMenu();
	disconnect(this, SIGNAL(escapeKeyPressed()), player1GameWindow, SLOT(togglePauseMenu()));
	disconnect(player1GameWindow->getPauseMenu(), SIGNAL(escapeKeyPressed()), player1GameWindow, SLOT(togglePauseMenu()));

	player1GameWindow->getGameOverMenu()->setWinner(winner);
	player1GameWindow->showGameOver();
	connect(player1GameWindow->getGameOverMenu()->getQuitButton(), SIGNAL(clicked()), this, SLOT(exitAfterGameOver()));
	
}

void MainWindow::exitAfterGameOver() {
	disconnect(player1GameWindow->getGameOverMenu()->getQuitButton(), SIGNAL(clicked()), this, SLOT(exitAfterGameOver()));

	player1GameWindow->getGameOverMenu()->close();
	player1GameWindow->close();
	player2GameWindow->close();
	delete player1GameWindow;
	delete player2GameWindow;

	showMenuWindow();

	gameWindowCreate = false;

	
}

bool MainWindow::checkEndGameCondition() {
	int p1 = 0;
	int p2 = 0;

	if (p1_lastQuestion.at(0) == 8) { //P1 made a guess
		if (p2_lastAnswer == true)
			p1 = 1;
		else
			p2 = 2;
	}
	if (p2_lastQuestion.size() > 0 && p2_lastQuestion.at(0) == 8) { //P2 made a guess
		if (p1_lastAnswer == true)
			p2 = 1;
		else
			p1 = 2;
	}

	if (p1 == 2) { //GameOver
		winner = player1Name;
		return true;
	}
	else if (p2 == 2) {//GameOver
		winner = player2Name;
		return true;
	}
	else if (p1 == 1 && p2 == 1) { //Tie
		winner = "Égalité";
		return true;
	}
	else if (p2 == 1) { //P2 wins
		winner = player2Name;
		return true;
	}
	else if (p1 == 1) {
		if ((gameLogic->getPlayer1().get_num_turn() + 1) > gameLogic->getPlayer2().get_num_turn()) //P2 still has a turn
			return false;
		else { //P1 wins
			winner = player1Name;
			return true;
		}

	}
	return false;
}