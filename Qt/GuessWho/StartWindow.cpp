/****************************************
GuessWho ProjetS2 - APP7Gi

P14
William Adam-Grenier - adaw2602
Charles Quesnel - quec2502
Maxime St-Onge - stom2105

Avril 2018

StartWindow.cpp
*****************************************/

#include "StartWindow.h"

StartWindow::StartWindow(QWidget* parent) : QWidget(parent)
{
	constructorLogic();
}

StartWindow::~StartWindow()
{
	delete quitButton;
	delete layoutPrincipal;
	delete image;
}

void StartWindow::constructorLogic()
{
	settingVariables();
	creatingObjects();
	settingObjectsProperties();
	settingLayout();
	settingWindow();
}

void StartWindow::settingVariables()
{
	//Setting Variables
	widthImage = parentWidget()->width() * 8 / 9;
	heightImage = parentWidget()->height();
}

void StartWindow::creatingObjects()
{
	//Creating Objects
	quitButton = new QLabel("Appuyez sur une touche pour commencer!", this);
	image = new QLabel(this);
	logoImage = new QPixmap("./Photos/logo.png");
	layoutPrincipal = new QVBoxLayout(this);
}

void StartWindow::settingObjectsProperties()
{
	//Setting properties for Objects

	//Quit Button
	quitButton->setStyleSheet("background: transparent; color : white");
	quitButton->setFont(QFont("Walkway Bold", 30));
	quitButton->setAlignment(Qt::AlignCenter);

	//Logo Image
	image->setPixmap(logoImage->scaled(widthImage, heightImage, Qt::KeepAspectRatio));
}

void StartWindow::settingLayout()
{
	//Setting the Layout
	layoutPrincipal->addWidget(image, Qt::AlignCenter);
	layoutPrincipal->addWidget(quitButton, Qt::AlignCenter);
}

void StartWindow::settingWindow()
{
	setFocusPolicy(Qt::StrongFocus);
	setLayout(layoutPrincipal);
	setWindowTitle("Guess Who?");
	setStyleSheet("background-image: url(./Photos/header_logo.png)");
}