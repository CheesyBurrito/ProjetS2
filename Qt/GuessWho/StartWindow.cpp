#include "StartWindow.h"


StartWindow::StartWindow() : QWidget()
{
    setWindowTitle("Guess Who?");
	setWindowFlags( Qt::WindowStaysOnTopHint);
	setStyleSheet("background-image: url(./Photos/header_logo.png)");

	quitButton = new QPushButton("Appuyez pour commencer!",this);
	quitButton->setFlat(true);
	quitButton->setStyleSheet("color : white");
	quitButton->setCursor(Qt::PointingHandCursor);
	quitButton->setFont(QFont("Walkway Bold", 30));

    layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addWidget(quitButton,0,Qt::AlignBottom);
    setLayout(layoutPrincipal);
}

StartWindow::~StartWindow()
{
	delete quitButton;
	delete layoutPrincipal;
}


QPushButton* StartWindow::getButton()
{
	return quitButton;
}