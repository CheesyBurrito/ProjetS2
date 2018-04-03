#include "StartWindow.h"


StartWindow::StartWindow() : QWidget()
{
    setWindowTitle("Guess Who?");
	setWindowFlags( Qt::WindowStaysOnTopHint);
	setStyleSheet("background-image: url(:/Photos/Photos/header_logo.png)");

	quitButton = new QPushButton("Appuyez pour commencer!",this);
	quitButton->setFlat(true);
	quitButton->setStyleSheet("color : white");
	quitButton->setCursor(Qt::PointingHandCursor);
	quitButton->setFont(QFont("Walkway Bold", 30));

    layoutPrincipal = new QVBoxLayout;
	layout = new QFormLayout;

	image = new QLabel("",this);
	QPixmap pix("");
	image->setPixmap(pix);
	layout->addWidget(image);
	
	layoutPrincipal->addLayout(layout);
    layoutPrincipal->addWidget(quitButton);
    setLayout(layoutPrincipal);

	//connect(quitButton, SIGNAL(clicked()), this, SLOT());
}

StartWindow::~StartWindow()
{
	delete quitButton;
	delete layout;
	delete layoutPrincipal;
}


QPushButton* StartWindow::getButton()
{
	return quitButton;
}