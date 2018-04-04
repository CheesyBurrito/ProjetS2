#include "SideMenu.h"



SideMenu::SideMenu(QWidget *parent, int windowHeight) :QWidget(parent)
{
	image = new QLabel(this);
	layout = new QHBoxLayout(this);

	QPixmap logo("./Photos/Green.png");
	image->setPixmap(logo.scaled(300, windowHeight));
	layout->addWidget(image);
	this->setFixedWidth(300);

	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(0);
	this->setLayout(layout);
	this->setGeometry(0, 0, 300, windowHeight);
}


SideMenu::~SideMenu()
{
}
