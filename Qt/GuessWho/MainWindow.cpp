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

	fpgaComm.loadPhonemesFromFile("Phonemes.csv");
	timer.setInterval(FPGA_READ_INTERVAL);
	timer.start();
	
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

	connect(this, SIGNAL(phonemeKeyPressed()), &fpgaComm, SLOT(toggleReadMode()));
	connect(&timer, SIGNAL(timeout()), &fpgaComm, SLOT(readSlot()));

	connect(this, SIGNAL(sKeyPressed()), &fpgaComm, SLOT(readAndPrint()));

	connect(this, SIGNAL(wKeyPressed()), this, SLOT(emulateMouseClick()));
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
	this->setGeometry(100, 100, 1920, 1080);
	//showFullScreen();
	show();
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
	numGames = 0;
	numGamesPlayed = 0;
	winPlayer1 = 0;
	winPlayer2 = 0;
	menu->show();
	setCentralWidget(menu);
	menu->showMainMenu();
}

void MainWindow::gameWindow()
{
	//GAME LOGIC *******************
	
	player1GameOver = GAME_OVER_NOT;
	player2GameOver = GAME_OVER_NOT;

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

	p1_lastQuestion.clear();
	p2_lastQuestion.clear();
	//gameLogic->getPlayer1Reference()->set_name_of_player(menu->);


	//GUI ************************
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
	connect(this, SIGNAL(enterKeyPressed()), player1GameWindow->getSideMenu()->getQuestionMenuBar(), SLOT(enterSubTree()));

	//Connects the pause menu buttons
	connect(this, SIGNAL(escapeKeyPressed()), player1GameWindow, SLOT(togglePauseMenu()));
	connect(player1GameWindow->getPauseMenu(), SIGNAL(escapeKeyPressed()), player1GameWindow, SLOT(togglePauseMenu()));

	//Initialize FPGA communication
	connect(&fpgaComm, SIGNAL(cardFailed()), player1GameWindow->getSideMenu(), SLOT(fpgaError()));
	connect(&fpgaComm, SIGNAL(cardFailed()), player2GameWindow->getSideMenu(), SLOT(fpgaError()));
	connect(&fpgaComm, SIGNAL(cardOn()), player1GameWindow->getSideMenu(), SLOT(fpgaOn()));
	connect(&fpgaComm, SIGNAL(cardOn()), player2GameWindow->getSideMenu(), SLOT(fpgaOn()));
	connect(&fpgaComm, SIGNAL(cardOff()), player1GameWindow->getSideMenu(), SLOT(fpgaOff()));
	connect(&fpgaComm, SIGNAL(cardOff()), player2GameWindow->getSideMenu(), SLOT(fpgaOff()));

	connect(player1GameWindow->getLowerBar()->getOkButton(), SIGNAL(clicked()), this, SLOT(checkEndGameCondition()));
	connect(player2GameWindow->getLowerBar()->getOkButton(), SIGNAL(clicked()), this, SLOT(checkEndGameCondition()));

	fpgaComm.checkCardStatus();
	fpgaComm.setReadMode(false);


	player1Name = menu->getPlayer1Name();
	numGames = menu->getNumGames();

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

	menu->hide();
	takeCentralWidget();

	p1_chooseCharacter();
	disconnect(this, SIGNAL(escapeKeyPressed()), menu, SLOT(showMainMenu()));
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
	emit keyPressed();
	if (event->key() == Qt::Key_Escape) {
		emit escapeKeyPressed();
	}
	if (event->key() == PHONEME_KEY) {
		emit phonemeKeyPressed();
	}
	if(event->key() == Qt::Key_W)
	{
		emit wKeyPressed();
	}
	if (event->key() == Qt::Key_S)
	{
		emit sKeyPressed();
	}
	if (event->key() == Qt::Key_E)
	{
		emit enterKeyPressed();
	}
}

void MainWindow::emulateMouseClick() {

	QPoint pos = QCursor::pos(); //Get mouse position
	QWidget *receiver = this->childAt(this->mapFromGlobal(pos)); //Find wich widget is there

	//Emit button press + release
	if (receiver) {
		QMouseEvent *e =  new QMouseEvent(QEvent::MouseButtonPress, receiver->mapFromGlobal(pos), Qt::LeftButton,
			Qt::LeftButton, Qt::NoModifier);
		QCoreApplication::postEvent(receiver, e);

		QMouseEvent *e2 = new QMouseEvent(QEvent::MouseButtonRelease, receiver->mapFromGlobal(pos), Qt::LeftButton,
			Qt::LeftButton, Qt::NoModifier);
		QCoreApplication::postEvent(receiver, e2);
	}
}

void MainWindow::returnToMenu() {
	this->player1GameWindow->getPauseMenu()->hide();
	int answer = QMessageBox::question(NULL, "Quitter la partie", "Ceci entraînera la fin de la partie, voulez-vous vraiment quitter?", QMessageBox::Yes | QMessageBox::No);
	if (answer == QMessageBox::Yes) { //Yes
		disconnect(this, SIGNAL(escapeKeyPressed()), player1GameWindow, SLOT(togglePauseMenu()));
		disconnect(player1GameWindow->getPauseMenu(), SIGNAL(escapeKeyPressed()), player1GameWindow, SLOT(togglePauseMenu()));

		disconnectFPGA();

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
	cout << "P1 ask first" << endl;
	if (!secondPlayerIsBot) {
		disconnect(player2GameWindow->getLowerBar()->getOkButton(), SIGNAL(clicked()), this, SLOT(p1_askFirstQuestion()));

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
	cout << "P1 ask" << endl;
	disconnect(player1GameWindow->getLowerBar()->getOkButton(), SIGNAL(clicked()), this, SLOT(p1_askQuestion()));
	player1GameWindow->getLowerBar()->changeText(player1Name.toStdString() + " : Veuillez poser votre question", EMPTY_MODE);

	gameLogic->getPlayer1Reference()->up_num_turn();

	gameLogic->getPlayer1Reference()->get_board_of_player()->get_character_manager()->set_num_character_hidden(
		player1GameWindow->getGrid()->getNbHiddenCharacters());

	connectP1ToTree();
}

void MainWindow::p2_askQuestion() {
	cout << "P2 ask" << endl;
	

	gameLogic->getPlayer2Reference()->up_num_turn();

	if (secondPlayerIsBot) {
		p1_answerQuestion(gameLogic->getPlayer2Reference()->cpuQuestionGeneretor(50, gameLogic->getPlayer1(), p1_lastQuestion.at(0)));
	}
	else {
		disconnect(player2GameWindow->getLowerBar()->getOkButton(), SIGNAL(clicked()), this, SLOT(p2_askQuestion()));
		player2GameWindow->getLowerBar()->changeText(player2Name.toStdString() + " : Veuillez poser votre question", EMPTY_MODE);

		connectP2ToTree();
	}

}

void MainWindow::p2_answerQuestion(std::vector<int> q) {
	cout << "P2 answer" << endl;
	disconnectP1ToTree();

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
	cout << "P1 answer" << endl;
	p2_lastQuestion = q;

	if (!secondPlayerIsBot) {
		player2GameWindow->hide();
		takeCentralWidget();
		setCentralWidget(player1GameWindow);
		player1GameWindow->show();

		disconnectP2ToTree();

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
	cout << "P2 get last" << endl;
	if (p1_lastQuestion.at(0) == 8) { //If P1 made a guess
		if (p2_lastAnswer == true)
			player1GameOver = GAME_OVER_WON;
		else {
			player1GameOver = GAME_OVER_LOST;
			if(!secondPlayerIsBot)
				checkEndGameCondition();
		}

		//checkEndGameCondition();
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
	cout << "P1 get last" << endl;
	if (p2_lastQuestion.at(0) == 8) { //If P2 made a guess
		if (p1_lastAnswer == true)
			player2GameOver = GAME_OVER_WON;
		else
			player2GameOver = GAME_OVER_LOST;
		
		checkEndGameCondition();
	}
	//else if (p1_lastQuestion.at(0) == 8) //Player 2 has played their tie turn
		//checkEndGameCondition();

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

			player1GameWindow->getLowerBar()->changeText(player1Name.toStdString() + ", à la question : " +
				gameLogic->convertQuestionToString(p1_lastQuestion.at(0), p1_lastQuestion.at(1)) +
				" la réponse est : " + convertBoolToString(p2_lastAnswer), OK_MODE);

			connect(player1GameWindow->getLowerBar()->getOkButton(), SIGNAL(clicked()), this, SLOT(p1_askQuestion()));
		}
		else {
			p1_askQuestion();
		}
}

void MainWindow::connectP1ToTree() {
	connect(player1GameWindow->getSideMenu()->getGuessWhoButton(), SIGNAL(clicked()), player1GameWindow, SLOT(setGuessMode()));
	connect(player1GameWindow->getSideMenu()->getGuessWhoButton(), SIGNAL(clicked()), player1GameWindow, SLOT(guessWhoMode()));
	connect(player1GameWindow->getSideMenu()->getQuestionMenuBar(), SIGNAL(sendQuestion(std::vector<int>)), player1GameWindow, SLOT(setNormalMode(std::vector<int>)));
	connect(player1GameWindow->getSideMenu()->getQuestionMenuBar(), SIGNAL(sendQuestion(std::vector<int>)), this, SLOT(p2_answerQuestion(std::vector<int>)));
	connect(player1GameWindow, SIGNAL(guessWho(std::vector<int>)), this, SLOT(p2_answerQuestion(std::vector<int>)));
}

void MainWindow::disconnectP1ToTree() {
	disconnect(player1GameWindow->getSideMenu()->getGuessWhoButton(), SIGNAL(clicked()), player1GameWindow, SLOT(guessWhoMode()));
	disconnect(player1GameWindow->getSideMenu()->getGuessWhoButton(), SIGNAL(clicked()), player1GameWindow, SLOT(setGuessMode()));
	disconnect(player1GameWindow->getSideMenu()->getQuestionMenuBar(), SIGNAL(sendQuestion(std::vector<int>)), this, SLOT(p2_answerQuestion(std::vector<int>)));
	disconnect(player1GameWindow->getSideMenu()->getQuestionMenuBar(), SIGNAL(sendQuestion(std::vector<int>)), player1GameWindow, SLOT(setNormalMode(std::vector<int>)));
	disconnect(player1GameWindow, SIGNAL(guessWho(std::vector<int>)), this, SLOT(p2_answerQuestion(std::vector<int>)));
}

void MainWindow::connectP2ToTree() {
	connect(player2GameWindow->getSideMenu()->getGuessWhoButton(), SIGNAL(clicked()), player2GameWindow, SLOT(setGuessMode()));
	connect(player2GameWindow->getSideMenu()->getGuessWhoButton(), SIGNAL(clicked()), player2GameWindow, SLOT(guessWhoMode()));
	connect(player2GameWindow->getSideMenu()->getQuestionMenuBar(), SIGNAL(sendQuestion(std::vector<int>)), player2GameWindow, SLOT(setNormalMode(std::vector<int>)));
	connect(player2GameWindow->getSideMenu()->getQuestionMenuBar(), SIGNAL(sendQuestion(std::vector<int>)), this, SLOT(p1_answerQuestion(std::vector<int>)));
	connect(player2GameWindow, SIGNAL(guessWho(std::vector<int>)), this, SLOT(p1_answerQuestion(std::vector<int>)));
}

void MainWindow::disconnectP2ToTree() {
	disconnect(player2GameWindow->getSideMenu()->getGuessWhoButton(), SIGNAL(clicked()), player2GameWindow, SLOT(guessWhoMode()));
	disconnect(player2GameWindow->getSideMenu()->getGuessWhoButton(), SIGNAL(clicked()), player2GameWindow, SLOT(setGuessMode()));
	disconnect(player2GameWindow->getSideMenu()->getQuestionMenuBar(), SIGNAL(sendQuestion(std::vector<int>)), this, SLOT(p1_answerQuestion(std::vector<int>)));
	disconnect(player2GameWindow->getSideMenu()->getQuestionMenuBar(), SIGNAL(sendQuestion(std::vector<int>)), player2GameWindow, SLOT(setNormalMode(std::vector<int>)));
	disconnect(player2GameWindow, SIGNAL(guessWho(std::vector<int>)), this, SLOT(p1_answerQuestion(std::vector<int>)));
}

void MainWindow::gameOver(QString winner) {

	player1GameWindow->getPauseMenu()->hide();
	disconnect(this, SIGNAL(escapeKeyPressed()), player1GameWindow, SLOT(togglePauseMenu()));
	disconnect(player1GameWindow->getPauseMenu(), SIGNAL(escapeKeyPressed()), player1GameWindow, SLOT(togglePauseMenu()));

	numGamesPlayed++;
	player1GameWindow->getGameOverMenu()->setWinner(winner,player1Name,player2Name,winPlayer1,winPlayer2,numGames,numGamesPlayed);
	player1GameWindow->showGameOver();
	connect(player1GameWindow->getGameOverMenu()->getQuitButton(), SIGNAL(clicked()), this, SLOT(exitAfterGameOver()));
	
}

void MainWindow::exitAfterGameOver() {
	disconnect(player1GameWindow->getGameOverMenu()->getQuitButton(), SIGNAL(clicked()), this, SLOT(exitAfterGameOver()));

	disconnectFPGA();

	player1GameWindow->getGameOverMenu()->close();
	player1GameWindow->getPauseMenu()->close();
	player1GameWindow->close();
	player2GameWindow->close();
	delete player1GameWindow;
	delete player2GameWindow;

	if (numGamesPlayed >= numGames)
		showMenuWindow();
	else
		gameWindow();

	gameWindowCreate = false;

	
}

bool MainWindow::checkEndGameCondition() {

	if (player1GameOver == GAME_OVER_LOST) {
		winPlayer2++;
		gameOver(player2Name);
		return true;
	}
	else if (player2GameOver == GAME_OVER_LOST) {
		winPlayer1++;
		gameOver(player1Name);
		return true;
	}
	else if (player1GameOver == GAME_OVER_WON && player2GameOver == GAME_OVER_WON) {
		winPlayer1++;
		winPlayer2++;
		gameOver("Égalité");
		return true;
	}
	else if (player2GameOver == GAME_OVER_WON) {
		winPlayer2++;
		gameOver(player2Name);
		return true;
	}
	else {
		if (gameLogic->getPlayer1().get_num_turn() > gameLogic->getPlayer2().get_num_turn()) //Player 2 still has a turn to take a guess
			return false;
		/*else {
			winPlayer1++;
			gameOver(player1Name);
			return true;
		}*/
	}
}

void MainWindow::disconnectFPGA() {
	disconnect(&fpgaComm, SIGNAL(cardFailed()), player1GameWindow->getSideMenu(), SLOT(fpgaError()));
	disconnect(&fpgaComm, SIGNAL(cardFailed()), player2GameWindow->getSideMenu(), SLOT(fpgaError()));

	disconnect(&fpgaComm, SIGNAL(cardOn()), player1GameWindow->getSideMenu(), SLOT(fpgaOn()));
	disconnect(&fpgaComm, SIGNAL(cardOn()), player2GameWindow->getSideMenu(), SLOT(fpgaOn()));

	disconnect(&fpgaComm, SIGNAL(cardOff()), player1GameWindow->getSideMenu(), SLOT(fpgaOff()));
	disconnect(&fpgaComm, SIGNAL(cardOff()), player2GameWindow->getSideMenu(), SLOT(fpgaOff()));
}