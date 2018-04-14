/****************************************
GuessWho ProjetS2 - APP7Gi

P14
William Adam-Grenier - adaw2602
Charles Quesnel - quec2502
Maxime St-Onge - stom2105

Avril 2018

LowerBar.cpp
*****************************************/

#include "LowerBar.h"


LowerBar::LowerBar(QWidget *parent, int width, int height) :QWidget(parent)
{
	this->setStyleSheet("background: transparent;");

	barHeight = height;
	barWidth = width - 300;

	setupWidgets();
	setupLayouts();

	this->setGeometry(0, 0, barWidth, height);
}


LowerBar::~LowerBar()
{
}

void LowerBar::changeText(std::string text, int mode) {
	infoText->setText(QString::fromStdString(text));

	//Delete current buttons
	yesButton->hide();
	noButton->hide();
	okButton->hide();

	//Create new buttons
	switch (mode) {
	case YES_NO_MODE:
		yesButton->show();
		noButton->show();
		break;

	case OK_MODE:
		okButton->show();
		break;

	default:
		break;
	}
}

void LowerBar::setupWidgets() {
	background = new QLabel(this);
	infoText = new QLabel(this);

	QPixmap img("./Photos/Red.png");
	background->setPixmap(img.scaled(barWidth, 100));

	infoText->setText("Charles, est-ce que votre personnage porte un chapeau?");
	infoText->setAttribute(Qt::WA_TranslucentBackground);
	infoText->setAlignment(Qt::AlignLeft);
	infoText->setAlignment(Qt::AlignVCenter);
	infoText->setStyleSheet("background:transparent; color:white");
	infoText->setFont(QFont("Walkway Bold", 16));

	yesButton = new QPushButton(this);
	yesButton->setFlat(false);
	yesButton->setStyleSheet("background-image: url(./Photos/yesButton.png);");
	yesButton->setCursor(Qt::PointingHandCursor);
	yesButton->setFixedSize(140, 70);

	noButton = new QPushButton(this);
	noButton->setFlat(false);
	noButton->setStyleSheet("background-image: url(./Photos/noButton.png);");
	noButton->setCursor(Qt::PointingHandCursor);
	noButton->setFixedSize(140, 70);

	okButton = new QPushButton(this);
	okButton->setFlat(false);
	okButton->setStyleSheet("background-image: url(./Photos/okButton.png);");
	okButton->setCursor(Qt::PointingHandCursor);
	okButton->setFixedSize(140, 70);

	yesButton->hide();
	noButton->hide();
	okButton->hide();
}

void LowerBar::setupLayouts() {
	layout = new QGridLayout(this);
	hLayout = new QHBoxLayout;

	hLayout->addWidget(infoText);
	hLayout->addWidget(yesButton);
	hLayout->addWidget(noButton);
	hLayout->addWidget(okButton);

	layout->setRowMinimumHeight(0, barHeight - 100); //First row is blank space
	layout->addWidget(background, 1, 0, 1, 2, Qt::AlignBottom); //Image takes all of 2nd row
	layout->addLayout(hLayout, 1, 1, 1, 1);

	layout->setColumnMinimumWidth(0, 50); //Adds a space before the hBoxLayout

	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(0);

}