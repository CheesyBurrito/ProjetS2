#include "MenuWindow.h"

MenuWindow::MenuWindow() : QWidget()
{
	
	setWindowTitle("Guess Who?");
	setWindowFlags(Qt::WindowStaysOnTopHint);
	setStyleSheet("background-image: url(:/Photos/Photos/menu_logo.png)");

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

	layoutPrincipal = new QHBoxLayout;
	QVBoxLayout *layout = new  QVBoxLayout;
	QFormLayout *layout1 = new QFormLayout;
	QFormLayout *layout2 = new QFormLayout;
	QFormLayout *layout3 = new QFormLayout;
	QFormLayout *layout4 = new QFormLayout;

	QLabel *nothing = new QLabel("", this);
	nothing->setPixmap(QPixmap(""));
	layout1->addWidget(nothing);
	layout2->addWidget(nothing);
	layout3->addWidget(nothing);
	layout4->addWidget(nothing);

	layout->addLayout(layout3);
	layout->addWidget(onePlayer);
	layout->addWidget(twoPlayers);
	layout->addWidget(quitButton);
	layout->addLayout(layout4);

	layoutPrincipal->addLayout(layout1);
	layoutPrincipal->addLayout(layout2);
	layoutPrincipal->addLayout(layout);
	setLayout(layoutPrincipal);

}

MenuWindow::~MenuWindow()
{

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