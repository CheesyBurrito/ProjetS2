#include "LowerBar.h"



LowerBar::LowerBar(QWidget *parent, int windowWidth, int windowHeight,int cardHeight):QWidget(parent)
{
	image = new QLabel(this);
	layout = new QGridLayout(this);
	
	infoText = new QLabel(this);
	infoText->setText("Charles, est-ce que votre personnage porte un chapeau?");
	infoText->setAttribute(Qt::WA_TranslucentBackground);
	infoText->setAlignment(Qt::AlignLeft);
	infoText->setAlignment(Qt::AlignVCenter);
	infoText->setStyleSheet("background:transparent; color:white");
	infoText->setFont(QFont("Walkway Bold", 16));
	layout->addWidget(infoText, 2, 1, 2, 14);

	QPixmap logo("./Photos/Red.png");
	image->setPixmap(logo.scaled(windowWidth-300, 100));
	layout->addWidget(image,0,0,6,20,Qt::AlignBottom);

	//this->setStyleSheet("background-image: url(./Photos/Red.png)");
	//this->setFixedHeight(100); 
	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(0);
	this->setLayout(layout);
	this->setGeometry(0, 0, windowWidth-300, windowHeight - 3 * cardHeight);
	//this->setStyleSheet("background-color:black;")

	yesButton = new QPushButton("Oui", this);
		yesButton->setFlat(false);
		yesButton->setStyleSheet("background: green; color : white");
		yesButton->setCursor(Qt::PointingHandCursor);
		yesButton->setFont(QFont("Walkway Bold", 30));
	noButton = new QPushButton("Non", this);
		noButton->setFlat(false);
		noButton->setStyleSheet("background: red; color : white");
		noButton->setCursor(Qt::PointingHandCursor);
		noButton->setFont(QFont("Walkway Bold", 30));
	okButton = new QPushButton("Ok", this);
		okButton->setFlat(false);
		okButton->setStyleSheet("background: green; color : white");
		okButton->setCursor(Qt::PointingHandCursor);
		okButton->setFont(QFont("Walkway Bold", 30));
	layout->addWidget(yesButton, 2, 16);
	layout->addWidget(noButton, 2, 18);
	layout->addWidget(okButton, 2, 16);
	yesButton->hide();
	noButton->hide();
	okButton->hide();
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