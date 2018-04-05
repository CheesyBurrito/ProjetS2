#include "GameWindow.h"



GameWindow::GameWindow(QWidget *parent):QWidget(parent)
{
	//setStyleSheet("background-image: url(./Photos/header_logo.png)");
	layout = new QGridLayout(this);
	grid = new CharacterGrid(this, parent->height()-100, parent->width()-300);
	lowerBar = new LowerBar(this, parent->width(),parent->height(),grid->getCardHeight());
	sideMenu = new SideMenu(this, parent->height());
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

	connect(lowerBar->getboutonZoom(), SIGNAL(clicked()), this, SLOT(setZoomMode()));
	connect(lowerBar->getBoutonNormal(), SIGNAL(clicked()), this, SLOT(setDefaultMode()));

	this->setLayout(layout);
}


GameWindow::~GameWindow()
{
}

void GameWindow::setZoomMode() {
	this->setCursor(zoomCursor);
	for (int i = 0; i < grid->getCharacters()->size(); i++){
		disconnect(this->grid->getCharacters()->at(i), SIGNAL(clicked()), this->grid->getCharacters()->at(i), SLOT(flipCard()));
		connect(this->grid->getCharacters()->at(i), SIGNAL(clicked()), this->grid->getCharacters()->at(i), SLOT(zoomCard()));
	}
}

void GameWindow::setDefaultMode() {
	this->setCursor(Qt::ArrowCursor);
	for (int i = 0; i < grid->getCharacters()->size(); i++) {
		disconnect(this->grid->getCharacters()->at(i), SIGNAL(clicked()), this->grid->getCharacters()->at(i), SLOT(zoomCard()));
		connect(this->grid->getCharacters()->at(i), SIGNAL(clicked()), this->grid->getCharacters()->at(i), SLOT(flipCard()));
	}
}