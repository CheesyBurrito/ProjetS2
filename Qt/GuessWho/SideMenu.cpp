#include "SideMenu.h"



SideMenu::SideMenu(QWidget *parent, int windowHeight, int windowWidth) :QWidget(parent)
{
	image = new QLabel(this);
	image2 = new QLabel(this);
	characteristics = new QLabel(image);
	layout = new QGridLayout(this);

	QPixmap pix("./Photos/side_menu.png");
	image->setPixmap(pix.scaled(300, windowHeight-100));
	QPixmap pix_corner("./Photos/corner_frame.png");
	image2->setPixmap(pix_corner.scaled(300, 100));
	layout->addWidget(image, 0, 0, 6, 10);
	layout->addWidget(image2, 6, 0,1,10);


	
	characteristics->setText("");
	characteristics->setMaximumWidth(280);
	characteristics->setAttribute(Qt::WA_TranslucentBackground);
	characteristics->setAlignment(Qt::AlignLeft);
	characteristics->setStyleSheet("background:transparent; color:white");
	characteristics->setFont(QFont("Walkway Bold", 14));
	layout->addWidget(characteristics, 5, 1,2,9);

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