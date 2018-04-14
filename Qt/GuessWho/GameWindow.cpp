/****************************************
GuessWho ProjetS2 - APP7Gi

P14
William Adam-Grenier - adaw2602
Charles Quesnel - quec2502
Maxime St-Onge - stom2105

Avril 2018

GameWindow.cpp
*****************************************/

#include "GameWindow.h"


GameWindow::GameWindow(QWidget* parent,  Player* player1) : QWidget(parent)
{
	height = parent->height();
	width = parent->width();
	player = player1;
	this->parent = parent;

	setupWidgets();
	setupLayouts();
	setupConnections();
}


GameWindow::~GameWindow()
{
}

void GameWindow::setupConnections() {
	//Zoom button
	connect(sideMenu->getZoomButton(), SIGNAL(clicked()), this, SLOT(toggleZoomMode()));

	//Character cards : click to zoom and hover to show characteristics
	for (int i = 0; i < grid->getCharacters()->size() - 1; i++) {
		connect(this->grid->getCharacters()->at(i), SIGNAL(clicked()), this->grid->getCharacters()->at(i), SLOT(flipCard()));
		connect(this->grid->getCharacters()->at(i), SIGNAL(hovered(std::string)), this->sideMenu, SLOT(setTraits(std::string)));
	}

	//Chosen character card : double click to zoom and hover to show characteristics
	connect(this->grid->getCharacters()->at(20), SIGNAL(doubleClicked()), this->grid->getCharacters()->at(20), SLOT(flipCard()));
	connect(this->grid->getCharacters()->at(20), SIGNAL(hovered(std::string)), this->sideMenu, SLOT(setTraits(std::string)));

	//Pause menu
	connect(pauseMenu->getQuitButton(), SIGNAL(clicked()), parent, SLOT(quitGame()));
	connect(pauseMenu->getCancelGameButton(), SIGNAL(clicked()), parent, SLOT(returnToMenu()));
	connect(pauseMenu->getResumeButton(), SIGNAL(clicked()), this, SLOT(togglePauseMenu()));

	//Test signal
	//connect(sideMenu, SIGNAL(lowerBarTest(std::string, int)), lowerBar, SLOT(changeText(std::string, int)));
}

void GameWindow::setupWidgets() {
	grid = new CharacterGrid(this, height - 100, width - 300, player->get_board_of_player()->get_character_manager());
	lowerBar = new LowerBar(this, width, height - grid->getGridHeight());
	sideMenu = new SideMenu(this, height, width - grid->getGridWidth());
	pauseMenu = new PauseMenu(this);
	gameOverMenu = new GameOverMenu();
	this->gameOverMenu->hide();
	pauseSound = new QSound("./Sounds/pause.wav", this);

	QPixmap zoomCursorPix("./Photos/zoom.png");
	zoomCursor = QCursor(zoomCursorPix.scaled(30, 30));

	QPixmap guessCursorPix("./Photos/guessCursor.png");
	guessCursor = QCursor(guessCursorPix.scaled(80, 80,Qt::KeepAspectRatio));
}

void GameWindow::setupLayouts() {
	layout = new QGridLayout(this);

	layout->addWidget(grid, 0, 0);
	layout->addWidget(lowerBar, 1, 0);
	layout->addWidget(sideMenu, 0, 1, 2, 1);
	layout->setSpacing(0);
	layout->setContentsMargins(0, 0, 0, 0);

	this->setLayout(layout);
}

void GameWindow::setChosenCharacter(Character* character) {
	this->grid->getCharacters()->at(20)->setChosenCharacter(character);
	player->set_character_selected(character);
}

void GameWindow::toggleSelectMode() {

	//Disconect click to choose and connect clic to flip instead
	if (selectMode) {
		this->sideMenu->getZoomButton()->setDisabled(false); //Enable the zoom button

		for (int i = 0; i < grid->getCharacters()->size() - 1; i++) {
			disconnect(this->grid->getCharacters()->at(i), SIGNAL(clickedCharacter(Character*)), this, SLOT(setChosenCharacter(Character*)));
			connect(this->grid->getCharacters()->at(i), SIGNAL(clickedCharacter(Character*)), this->grid->getCharacters()->at(i), SLOT(flipCard()));
			disconnect(this->grid->getCharacters()->at(i), SIGNAL(clickedCharacter(Character*)), this, SLOT(enableOkButton()));
		}
		connect(this->grid->getCharacters()->at(20), SIGNAL(doubleClicked()), this->grid->getCharacters()->at(20), SLOT(flipCard()));
	}

	//Disconect click to flip and connect clic to choose instead
	else {
		this->lowerBar->getOkButton()->setDisabled(true); //Disable OK button until a character is chosen
		this->sideMenu->getZoomButton()->setDisabled(true); //Disable the zoom button

		for (int i = 0; i < grid->getCharacters()->size() - 1; i++) {
			disconnect(this->grid->getCharacters()->at(i), SIGNAL(clickedCharacter(Character*)), this->grid->getCharacters()->at(i), SLOT(flipCard()));
			connect(this->grid->getCharacters()->at(i), SIGNAL(clickedCharacter(Character*)), this, SLOT(setChosenCharacter(Character*)));
			connect(this->grid->getCharacters()->at(i), SIGNAL(clickedCharacter(Character*)), this, SLOT(enableOkButton()));
		}
		disconnect(this->grid->getCharacters()->at(20), SIGNAL(doubleClicked()), this->grid->getCharacters()->at(20), SLOT(flipCard()));
	}

	selectMode = !selectMode;
}

void GameWindow::enableOkButton() {
	if (this->lowerBar->getOkButton()->isEnabled() == false)
		this->lowerBar->getOkButton()->setEnabled(true);
}
void GameWindow::setGuessMode()
{
	guessMode = true;
}

void GameWindow::guessWhoMode() {
	//change cursor

	if (guessMode == true) {
		//Disconect click to flip and connect clic to choose instead
		this->getLowerBar()->changeText("Cliquez sur votre choix", EMPTY_MODE);
		this->setCursor(guessCursor);
		for (int i = 0; i < grid->getCharacters()->size() - 1; i++) {
			disconnect(this->grid->getCharacters()->at(i), SIGNAL(clickedCharacter(Character*)), this->grid->getCharacters()->at(i), SLOT(flipCard()));
			disconnect(this->grid->getCharacters()->at(i), SIGNAL(clickedCharacter(Character*)), this->grid->getCharacters()->at(i), SLOT(zoomCard()));
			connect(this->grid->getCharacters()->at(i), SIGNAL(clickedCharacter(Character*)), this, SLOT(emitGuessWho(Character*)));
		}
		disconnect(this->grid->getCharacters()->at(20), SIGNAL(doubleClicked()), this->grid->getCharacters()->at(20), SLOT(flipCard()));
	}
	//Disconect clic to choose
	else
	{
		for (int i = 0; i < grid->getCharacters()->size() - 1; i++) {
			disconnect(this->grid->getCharacters()->at(i), SIGNAL(clickedCharacter(Character*)), this, SLOT(emitGuessWho(Character*)));
		}
	}
}

void GameWindow::emitGuessWho(Character* c) {
	std::vector<int> q = { 8, c->get_id() };
	emit guessWho(q);
	this->sideMenu->getZoomButton()->setDisabled(true);
}

void GameWindow::toggleZoomMode() {

	//Disconect click to flip and connect clic to zoom instead
	if (guessMode)
	{
		this->getLowerBar()->changeText("Veuillez poser votre question", EMPTY_MODE);
		guessMode = false;
		guessWhoMode();
	}

	if (zoomMode) {
		this->setCursor(Qt::ArrowCursor);
		for (int i = 0; i < grid->getCharacters()->size() - 1; i++) {
			disconnect(this->grid->getCharacters()->at(i), SIGNAL(clickedCharacter(Character*)), this->grid->getCharacters()->at(i), SLOT(zoomCard()));
			connect(this->grid->getCharacters()->at(i), SIGNAL(clickedCharacter(Character*)), this->grid->getCharacters()->at(i), SLOT(flipCard()));
		}
		disconnect(this->grid->getCharacters()->at(20), SIGNAL(clickedCharacter(Character*)), this->grid->getCharacters()->at(20), SLOT(zoomCard()));
		connect(this->grid->getCharacters()->at(20), SIGNAL(doubleClicked()), this->grid->getCharacters()->at(20), SLOT(flipCard()));
	}

	//Disconect click to zoom and connect clic to flip instead
	else {
		this->setCursor(zoomCursor);
		for (int i = 0; i < grid->getCharacters()->size() - 1; i++) {
			disconnect(this->grid->getCharacters()->at(i), SIGNAL(clickedCharacter(Character*)), this->grid->getCharacters()->at(i), SLOT(flipCard()));
			connect(this->grid->getCharacters()->at(i), SIGNAL(clickedCharacter(Character*)), this->grid->getCharacters()->at(i), SLOT(zoomCard()));
		}
		disconnect(this->grid->getCharacters()->at(20), SIGNAL(doubleClicked()), this->grid->getCharacters()->at(20), SLOT(flipCard()));
		connect(this->grid->getCharacters()->at(20), SIGNAL(clickedCharacter(Character*)), this->grid->getCharacters()->at(20), SLOT(zoomCard()));
	}

	zoomMode = !zoomMode;
}

void GameWindow::togglePauseMenu() {
	if (isPaused) {
		pauseMenu->hide();
		this->setEnabled(true);
		pauseSound->play();
	}
	else {
		pauseMenu->show();
		this->setEnabled(false);
		pauseSound->play();
	}

	isPaused = !isPaused;
}

void GameWindow::showGameOver() {
	this->gameOverMenu->show();
	this->setEnabled(true);
}


