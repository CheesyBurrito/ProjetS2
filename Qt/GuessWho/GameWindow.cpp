#include "GameWindow.h"



GameWindow::GameWindow(QWidget *parent):QWidget(parent)
{
	setStyleSheet("background-image: url(./Photos/header_logo.png)");
	layout = new QGridLayout(this);
	int h = parent->height() - 100;

	QPixmap logo("./Photos/claudette.png");
	for (int i = 0; i < 20; i++) {
		images.push_back(new QLabel);
		images.at(i)->setPixmap(logo.scaled(300, h/4, Qt::KeepAspectRatio));
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			layout->addWidget(images.at(5*j+i), j, i, Qt::AlignCenter);
		}
	}

	this->setLayout(layout);
}


GameWindow::~GameWindow()
{
}
