#include "StartWindow.h"

StartWindow::StartWindow(QWidget* parent) : QWidget(parent)
{
	int widthImage = parent->width() * 9/ 10;

    setWindowTitle("Guess Who?");
	setStyleSheet("background-image: url(./Photos/header_logo.png)");

	quitButton = new QPushButton("Appuyez pour commencer!",this);
	quitButton->setFlat(true);
	quitButton->setStyleSheet("background: transparent; color : white");
	quitButton->setCursor(Qt::PointingHandCursor);
	quitButton->setFont(QFont("Walkway Bold", 30));

	image = new QLabel(this);
	QPixmap logo("./Photos/logo.png");
	image->setPixmap(logo.scaled(widthImage, 1080, Qt::KeepAspectRatio));

    layoutPrincipal = new QGridLayout(this);
	layoutPrincipal->addWidget(image,0,0,Qt::AlignCenter);
    layoutPrincipal->addWidget(quitButton,1,0);
    setLayout(layoutPrincipal);
}

StartWindow::~StartWindow()
{
	delete quitButton;
	delete layoutPrincipal;
	delete image;
}


QPushButton* StartWindow::getButton()
{
	return quitButton;
}