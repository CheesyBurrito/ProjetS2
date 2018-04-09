#include "StartWindow.h"

StartWindow::StartWindow(QWidget* parent) : QWidget(parent)
{
	//setFocusPolicy(Qt::StrongFocus);
	int widthImage = parent->width() * 8/ 9;

    setWindowTitle("Guess Who?");
	setStyleSheet("background-image: url(./Photos/header_logo.png)");

	quitButton = new QLabel("Appuyez sur une touche pour commencer!",this);
	quitButton->setStyleSheet("background: transparent; color : white");
	quitButton->setFont(QFont("Walkway Bold", 30));

	image = new QLabel(this);
	QPixmap logo("./Photos/logo.png");
	image->setPixmap(logo.scaled(widthImage, 1080, Qt::KeepAspectRatio));
	image->setStyleSheet("background: transparent;");

    layoutPrincipal = new QGridLayout(this);
	layoutPrincipal->addWidget(image,0,0,10,1,Qt::AlignCenter);
    layoutPrincipal->addWidget(quitButton,10,0,Qt::AlignCenter);

	layoutPrincipal->setRowStretch(0, 50);
	layoutPrincipal->setRowStretch(10,30);
	layoutPrincipal->setRowStretch(11, 30);

    setLayout(layoutPrincipal);
}

StartWindow::~StartWindow()
{
	delete quitButton;
	delete layoutPrincipal;
	delete image;
}
