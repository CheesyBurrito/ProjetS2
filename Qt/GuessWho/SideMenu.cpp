#include "SideMenu.h"



SideMenu::SideMenu(QWidget *parent, int windowHeight) :QWidget(parent)
{
	image = new QLabel(this);
	characteristics = new QLabel(image);
	layout = new QGridLayout(this);

	QPixmap pix("./Photos/Green.png");
	image->setPixmap(pix.scaled(300, windowHeight));
	layout->addWidget(image, 0, 0, 2, 0);


	
	characteristics->setText("");
	characteristics->setFixedSize(300, 200);
	characteristics->setAttribute(Qt::WA_TranslucentBackground);
	layout->addWidget(characteristics, 1, 0);

	this->setFixedWidth(300);
	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(0);
	this->setLayout(layout);
	this->setGeometry(0, 0, 300, windowHeight);
}


SideMenu::~SideMenu()
{
}

void SideMenu::setTraits(std::string newTraits) {
	characteristics->setText(QString::fromStdString(newTraits));
}