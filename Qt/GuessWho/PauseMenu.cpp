#include "PauseMenu.h"


PauseMenu::PauseMenu(QWidget* parent)
{
	layout = new QGridLayout(this);
	quitButton = new QPushButton("Quitter", this);
	resumeButton = new QPushButton("Retourner au jeu", this);
	cancelGameButton = new QPushButton("Retourner au menu", this);

	this->setFixedSize(200, 200);
	this->setWindowFlag(Qt::WindowStaysOnTopHint);
	this->setWindowFlag(Qt::FramelessWindowHint);
	layout->addWidget(resumeButton, 0, 0);
	layout->addWidget(cancelGameButton, 1, 0);
	layout->addWidget(quitButton, 2, 0);
	this->setLayout(layout);
}


PauseMenu::~PauseMenu()
{
}

void PauseMenu::keyPressEvent(QKeyEvent *event) {
	if (event->key() == Qt::Key_Escape) {
		emit escapeKeyPressed();
	}
}