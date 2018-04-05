#include "LowerBar.h"



LowerBar::LowerBar(QWidget *parent, int windowWidth, int windowHeight,int cardHeight):QWidget(parent)
{
	image = new QLabel(this);
	layout = new QGridLayout(this);
	boutonZoom = new QPushButton("Mode Zoom", this);
	boutonZoom->setStyleSheet("background: green");
	boutonNormal = new QPushButton("Mode Normal", this);
	boutonNormal->setStyleSheet("background: green");
	
	QPixmap logo("./Photos/Red.png");
	image->setPixmap(logo.scaled(windowWidth-300, windowHeight-3*cardHeight));
	layout->addWidget(image,0,0,6,20);

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
