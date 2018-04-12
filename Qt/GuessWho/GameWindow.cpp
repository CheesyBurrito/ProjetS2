#include "GameWindow.h"

GameWindow::GameWindow(QWidget *parent) : QWidget(parent)
{
	height = parent->height();
	width = parent->width();
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

	//Escape Key
	connect(parent, SIGNAL(escapeKeyPressed()), this, SLOT(togglePauseMenu()));
	connect(pauseMenu, SIGNAL(escapeKeyPressed()), this, SLOT(togglePauseMenu()));

	//Pause menu
	connect(pauseMenu->getQuitButton(), SIGNAL(clicked()), parent, SLOT(quitGame()));
	connect(pauseMenu->getCancelGameButton(), SIGNAL(clicked()), parent, SLOT(returnToMenu()));
	connect(pauseMenu->getResumeButton(), SIGNAL(clicked()), this, SLOT(togglePauseMenu()));

	//Test signal
	connect(sideMenu, SIGNAL(lowerBarTest(std::string, int)), lowerBar, SLOT(changeText(std::string, int)));
}

void GameWindow::setupWidgets() {
	grid = new CharacterGrid(this, height - 100, width - 300);
	lowerBar = new LowerBar(this, width, height - grid->getGridHeight());
	sideMenu = new SideMenu(this, height, width - grid->getGridWidth());
	pauseMenu = new PauseMenu(this);
	pauseSound = new QSound("./Sounds/pause.wav", this);

	QPixmap zoomCursorPix("./Photos/zoom.png");
	zoomCursor = QCursor(zoomCursorPix.scaled(30, 30));
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

void GameWindow::toggleZoomMode() {

	//Disconect click to flip and connect clic to zoom instead
	if (zoomMode) {
		this->setCursor(Qt::ArrowCursor);
		for (int i = 0; i < grid->getCharacters()->size() - 1; i++) {
			disconnect(this->grid->getCharacters()->at(i), SIGNAL(clicked()), this->grid->getCharacters()->at(i), SLOT(zoomCard()));
			connect(this->grid->getCharacters()->at(i), SIGNAL(clicked()), this->grid->getCharacters()->at(i), SLOT(flipCard()));
		}
		disconnect(this->grid->getCharacters()->at(20), SIGNAL(clicked()), this->grid->getCharacters()->at(20), SLOT(zoomCard()));
		connect(this->grid->getCharacters()->at(20), SIGNAL(doubleClicked()), this->grid->getCharacters()->at(20), SLOT(flipCard()));
	}

	//Disconect click to zoom and connect clic to flip instead
	else {
		this->setCursor(zoomCursor);
		for (int i = 0; i < grid->getCharacters()->size() - 1; i++) {
			disconnect(this->grid->getCharacters()->at(i), SIGNAL(clicked()), this->grid->getCharacters()->at(i), SLOT(flipCard()));
			connect(this->grid->getCharacters()->at(i), SIGNAL(clicked()), this->grid->getCharacters()->at(i), SLOT(zoomCard()));
		}
		disconnect(this->grid->getCharacters()->at(20), SIGNAL(doubleClicked()), this->grid->getCharacters()->at(20), SLOT(flipCard()));
		connect(this->grid->getCharacters()->at(20), SIGNAL(clicked()), this->grid->getCharacters()->at(20), SLOT(zoomCard()));
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



