#include "LowerBar.h"



LowerBar::LowerBar(QWidget *parent, int windowWidth, int windowHeight,int cardHeight):QWidget(parent)
{
	image = new QLabel(this);
	layout = new QGridLayout(this);
	boutonZoom = new QPushButton("Mode Zoom", this);
	boutonZoom->setStyleSheet("background: green");
	boutonNormal = new QPushButton("Mode Normal", this);
	boutonNormal->setStyleSheet("background: green");
	
	infoText = new QLabel(this);
	infoText->setText("Charles, est-ce que votre personnage porte un chapeau?");
	infoText->setAttribute(Qt::WA_TranslucentBackground);
	infoText->setAlignment(Qt::AlignLeft);
	infoText->setAlignment(Qt::AlignVCenter);
	infoText->setStyleSheet("background:transparent; color:white");
	infoText->setFont(QFont("Walkway Bold", 16));
	layout->addWidget(infoText, 2, 1, 2, 10);

	QPixmap logo("./Photos/Red.png");
	image->setPixmap(logo.scaled(windowWidth-300, 100));
	layout->addWidget(image,0,0,6,20,Qt::AlignBottom);

	//this->setStyleSheet("background-image: url(./Photos/Red.png)");
	//this->setFixedHeight(100); 

	layout->addWidget(boutonZoom,2,14,2,2);
	layout->addWidget(boutonNormal,2,17,2,2);

	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(0);
	this->setLayout(layout);
	this->setGeometry(0, 0, windowWidth-300, windowHeight - 3 * cardHeight);
	//this->setStyleSheet("background-color:black;");
}


LowerBar::~LowerBar()
{
}
