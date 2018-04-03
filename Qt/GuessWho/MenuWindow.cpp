#include "MenuWindow.h"

MenuWindow::MenuWindow() : QWidget()
{
	
	setWindowTitle("Guess Who?");
	setWindowFlags(Qt::WindowStaysOnTopHint);
	setStyleSheet("background-image: url(./Photos/header_logo.png)");

	quitButton = new QPushButton("Quitter", this);
	quitButton->setFlat(true);
	quitButton->setStyleSheet("color : white");
	quitButton->setCursor(Qt::PointingHandCursor);
	quitButton->setFont(QFont("Walkway Bold", 30));

	onePlayer = new QPushButton("1 joueur", this);
	onePlayer->setFlat(true);
	onePlayer->setStyleSheet("color : white");
	onePlayer->setCursor(Qt::PointingHandCursor);
	onePlayer->setFont(QFont("Walkway Bold", 30));

	twoPlayers = new QPushButton("2 joueurs", this);
	twoPlayers->setFlat(true);
	twoPlayers->setStyleSheet("color : white");
	twoPlayers->setCursor(Qt::PointingHandCursor);
	twoPlayers->setFont(QFont("Walkway Bold", 30));

	layoutPrincipal = new QGridLayout;
	
	image = new QLabel;
	QPixmap logo("./Photos/logo.png");
	image->setPixmap(logo.scaled(1536,1080,Qt::KeepAspectRatio));

	layoutPrincipal->addWidget(image, 0, 0, 12, 4);
	layoutPrincipal->addWidget(onePlayer, 5, 4);
	layoutPrincipal->addWidget(twoPlayers, 6, 4);
	layoutPrincipal->addWidget(quitButton, 7, 4);
	
	setLayout(layoutPrincipal);

}

MenuWindow::~MenuWindow()
{

}

void MenuWindow::onePlayerWindow()
{
	delete quitButton;
	delete onePlayer;
	delete twoPlayers;
	joueur1 = new QLineEdit;

}

void MenuWindow::twoPlayersWindow()
{
	delete quitButton;
	delete onePlayer;
	delete twoPlayers;
	joueur1 = new QLineEdit;
	joueur2 = new QLineEdit;

}

QPushButton* MenuWindow::getQuitButton()
{
	return quitButton;
}

QPushButton* MenuWindow::getOnePlayerButton()
{
	return onePlayer;
}

QPushButton* MenuWindow::getTwoPlayersButton()
{
	return twoPlayers;
}
