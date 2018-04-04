#include "LowerBar.h"



LowerBar::LowerBar(QWidget *parent, int windowWidth):QWidget(parent)
{
	image = new QLabel(this);
	layout = new QHBoxLayout(this);

	QPixmap logo("./Photos/Red.png");
	image->setPixmap(logo.scaled(windowWidth-300, 100));
	layout->addWidget(image);
	this->setFixedHeight(100); 

	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(0);
	this->setLayout(layout);
	this->setGeometry(0, 0, windowWidth-300, 100);
	//this->setStyleSheet("background-color:black;");
}


LowerBar::~LowerBar()
{
}
