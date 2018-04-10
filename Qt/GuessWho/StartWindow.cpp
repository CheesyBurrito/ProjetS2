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
	layoutPrincipal = new QGridLayout(this);
}

void StartWindow::settingObjectsProperties()
{
	//Setting properties for Objects

	//Quit Button
	quitButton->setStyleSheet("background: transparent; color : white");
	quitButton->setFont(QFont("Walkway Bold", 30));

	//Logo Image
	image->setPixmap(logoImage->scaled(widthImage, heightImage, Qt::KeepAspectRatio));
	image->setStyleSheet("background: transparent;");
}

void StartWindow::settingLayout()
{
	//Setting the Layout
	layoutPrincipal->addWidget(image, 0, 0, 10, 1, Qt::AlignCenter);
	layoutPrincipal->addWidget(quitButton, 10, 0, Qt::AlignCenter);

	layoutPrincipal->setRowStretch(0, 50);
	layoutPrincipal->setRowStretch(10, 30);
	layoutPrincipal->setRowStretch(11, 30);
}

void StartWindow::settingWindow()
{
	setLayout(layoutPrincipal);
	setWindowTitle("Guess Who?");
	setStyleSheet("background-image: url(./Photos/header_logo.png)");
}