#include "GameWindow.h"



GameWindow::GameWindow(QWidget *parent) : QWidget(parent)
{
	//setStyleSheet("background-image: url(./Photos/header_logo.png)");
	layout = new QGridLayout(this);
	grid = new CharacterGrid(this, parent->height()-100, parent->width()-320);
	grid->setStyleSheet("background: transparent;");
	lowerBar = new LowerBar(this, parent->width(),parent->height(),grid->getCardHeight());
	lowerBar->setStyleSheet("background: transparent;");
	sideMenu = new SideMenu(this, parent->height(), parent->width());
	sideMenu->setStyleSheet("background: transparent;");
	pauseMenu = new PauseMenu(this);
	layout->addWidget(grid, 0, 0);
	layout->addWidget(lowerBar, 1, 0);
	layout->addWidget(sideMenu, 0, 1, 2, 1);
	layout->setSpacing(0);
	layout->setContentsMargins(0, 0, 0, 0);
	//layout->setRowStretch(0, 90);
	//layout->setRowStretch(1, 10);

	//layout->setColumnStretch(0, 80);
	//layout->setColumnStretch(1, 20);
	QPixmap zoomCursorPix("./Photos/zoom.png");
	zoomCursor = QCursor(zoomCursorPix.scaled(30,30));

	connect(sideMenu->getZoomButton(), SIGNAL(clicked()), this, SLOT(toggleZoomMode()));
	//connect(sideMenu->getZoomButton(), SIGNAL(clicked()), sideMenu, SLOT(switchZoomIcon()));

	//Connects slots and signals for the character cards
	for (int i = 0; i < grid->getCharacters()->size()-1; i++) {
		connect(this->grid->getCharacters()->at(i), SIGNAL(clicked()), this->grid->getCharacters()->at(i), SLOT(flipCard()));
		connect(this->grid->getCharacters()->at(i), SIGNAL(hovered(std::string)), this->sideMenu, SLOT(setTraits(std::string)));
	}
	connect(this->grid->getCharacters()->at(20), SIGNAL(doubleClicked()), this->grid->getCharacters()->at(20), SLOT(flipCard()));
	connect(this->grid->getCharacters()->at(20), SIGNAL(hovered(std::string)), this->sideMenu, SLOT(setTraits(std::string)));

	connect(parent, SIGNAL(escapeKeyPressed()), this, SLOT(togglePauseMenu()));
	connect(pauseMenu, SIGNAL(escapeKeyPressed()), this, SLOT(togglePauseMenu()));
	connect(pauseMenu->getQuitButton(), SIGNAL(clicked()), pauseMenu, SLOT(close()));
	connect(pauseMenu->getQuitButton(), SIGNAL(clicked()), parent, SLOT(close()));
	connect(pauseMenu->getCancelGameButton(), SIGNAL(clicked()), parent, SLOT(quitGame()));
	connect(pauseMenu->getResumeButton(), SIGNAL(clicked()), this, SLOT(togglePauseMenu()));

	connect(sideMenu, SIGNAL(lowerBarTest(std::string, int)), lowerBar, SLOT(changeText(std::string, int)));

	this->setLayout(layout);
	//pauseMenu->show();
}


GameWindow::~GameWindow()
{
}

void GameWindow::toggleZoomMode() {
	if (zoomMode) {

		this->setCursor(Qt::ArrowCursor);
		for (int i = 0; i < grid->getCharacters()->size() - 1; i++) {
			disconnect(this->grid->getCharacters()->at(i), SIGNAL(clicked()), this->grid->getCharacters()->at(i), SLOT(zoomCard()));
			connect(this->grid->getCharacters()->at(i), SIGNAL(clicked()), this->grid->getCharacters()->at(i), SLOT(flipCard()));
		}
		disconnect(this->grid->getCharacters()->at(20), SIGNAL(clicked()), this->grid->getCharacters()->at(20), SLOT(zoomCard()));
		connect(this->grid->getCharacters()->at(20), SIGNAL(doubleClicked()), this->grid->getCharacters()->at(20), SLOT(flipCard()));
		
		zoomMode = false;
	}
	else {
		this->setCursor(zoomCursor);
		for (int i = 0; i < grid->getCharacters()->size() - 1; i++) {
			disconnect(this->grid->getCharacters()->at(i), SIGNAL(clicked()), this->grid->getCharacters()->at(i), SLOT(flipCard()));
			connect(this->grid->getCharacters()->at(i), SIGNAL(clicked()), this->grid->getCharacters()->at(i), SLOT(zoomCard()));
		}
		disconnect(this->grid->getCharacters()->at(20), SIGNAL(doubleClicked()), this->grid->getCharacters()->at(20), SLOT(flipCard()));
		connect(this->grid->getCharacters()->at(20), SIGNAL(clicked()), this->grid->getCharacters()->at(20), SLOT(zoomCard()));

		zoomMode = true;
	}
}

void GameWindow::togglePauseMenu() {
	if (isPaused) {
		pauseMenu->hide();
		this->setEnabled(true);
		isPaused = false;
	}
	else {
		pauseMenu->show();
		this->setEnabled(false);
		isPaused = true;
	}
}



