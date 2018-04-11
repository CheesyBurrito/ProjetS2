#include "PauseMenu.h"


PauseMenu::PauseMenu(QWidget* parent)
{

	pauseBackground = new QLabel(this);
	QPixmap pause_Pix("./Photos/pauseMenu.png");
	pauseBackground->setPixmap(pause_Pix.scaled(600, 320));

	layout = new QGridLayout(this);
	quitButton = new MenuButton(this, " Quitter");
	resumeButton = new MenuButton(this, " Retourner au jeu");
	cancelGameButton = new MenuButton(this, " Retourner au menu");

	this->setWindowFlag(Qt::WindowStaysOnTopHint);
	this->setWindowFlag(Qt::FramelessWindowHint);
	layout->setAlignment(Qt::AlignCenter);
	layout->setSpacing(0);
	layout->addWidget(pauseBackground,0,0,5,1,Qt::AlignCenter);
	layout->addWidget(resumeButton,1,0, Qt::AlignCenter);
	layout->addWidget(cancelGameButton,2,0, Qt::AlignCenter);
	layout->addWidget(quitButton,3,0, Qt::AlignCenter);
	this->setLayout(layout);

	connect(resumeButton, SIGNAL(hovered(MenuButton*)), this, SLOT(setHoveredButton(MenuButton*)));
	connect(cancelGameButton, SIGNAL(hovered(MenuButton*)), this, SLOT(setHoveredButton(MenuButton*)));
	connect(quitButton, SIGNAL(hovered(MenuButton*)), this, SLOT(setHoveredButton(MenuButton*)));
}


PauseMenu::~PauseMenu()
{
}

void PauseMenu::keyPressEvent(QKeyEvent *event) {
	if (event->key() == Qt::Key_Escape) {
		emit escapeKeyPressed();
	}
}

void PauseMenu::setHoveredButton(MenuButton *button)
{
	resumeButton->setIsSelected(false);
	cancelGameButton->setIsSelected(false);
	quitButton->setIsSelected(false);
	button->setIsSelected(true);
}