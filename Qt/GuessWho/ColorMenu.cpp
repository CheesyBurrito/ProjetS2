/****************************************
GuessWho ProjetS2 - APP7Gi

P14
William Adam-Grenier - adaw2602
Charles Quesnel - quec2502
Maxime St-Onge - stom2105

Avril 2018

ColorMenu.cpp
*****************************************/

#include "ColorMenu.h"


ColorMenu::ColorMenu(QWidget* parent)
{

	colorBackground = new QLabel(this);
	QPixmap color_Pix("./Photos/colorMenu.png");
	colorBackground->setPixmap(color_Pix.scaled(500, 267));

	layout = new QGridLayout(this);
	color0 = new QPushButton(this);
	color1 = new QPushButton(this);
	color2 = new QPushButton(this);
	color3 = new QPushButton(this);
	color4 = new QPushButton(this);
	color5 = new QPushButton(this);

	color0->setStyleSheet("background-image: url(./Photos/color0.png);");
	color0->setCursor(Qt::PointingHandCursor);
	color0->setFixedSize(40, 40);

	color1->setStyleSheet("background-image: url(./Photos/color1.png);");
	color1->setCursor(Qt::PointingHandCursor);
	color1->setFixedSize(40, 40);

	color2->setStyleSheet("background-image: url(./Photos/color2.png);");
	color2->setCursor(Qt::PointingHandCursor);
	color2->setFixedSize(40, 40);

	color3->setStyleSheet("background-image: url(./Photos/color3.png);");
	color3->setCursor(Qt::PointingHandCursor);
	color3->setFixedSize(40, 40);

	color4->setStyleSheet("background-image: url(./Photos/color4.png);");
	color4->setCursor(Qt::PointingHandCursor);
	color4->setFixedSize(40, 40);

	color5->setStyleSheet("background-image: url(./Photos/color5.png);");
	color5->setCursor(Qt::PointingHandCursor);
	color5->setFixedSize(40, 40);

	this->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);

	layout->setAlignment(Qt::AlignCenter);
	layout->addWidget(colorBackground,0,0,1,8,Qt::AlignCenter);
	layout->addWidget(color0, 0, 1,1,1);
	layout->addWidget(color1, 0, 2,1,1);
	layout->addWidget(color2, 0, 3,1,1);
	layout->addWidget(color3, 0, 4,1,1);
	layout->addWidget(color4, 0, 5,1,1);
	layout->addWidget(color5, 0, 6,1,1);
	hide();

}

ColorMenu::~ColorMenu()
{
}

void ColorMenu::setColorMenu(int color)
{
	layout->addWidget(colorBackground, 0, 0, 1, 7, Qt::AlignCenter);
	if (color == 0)
	{
		layout->addWidget(color1, 0, 1, 1, 1);
		layout->addWidget(color2, 0, 2, 1, 1);
		layout->addWidget(color3, 0, 3, 1, 1);
		layout->addWidget(color4, 0, 4, 1, 1);
		layout->addWidget(color5, 0, 5, 1, 1);
	}
	else if (color == 1)
	{
		layout->addWidget(color0, 0, 1, 1, 1);
		layout->addWidget(color2, 0, 2, 1, 1);
		layout->addWidget(color3, 0, 3, 1, 1);
		layout->addWidget(color4, 0, 4, 1, 1);
		layout->addWidget(color5, 0, 5, 1, 1);
	}
	else if (color == 2)
	{
		layout->addWidget(color0, 0, 1, 1, 1);
		layout->addWidget(color1, 0, 2, 1, 1);
		layout->addWidget(color3, 0, 3, 1, 1);
		layout->addWidget(color4, 0, 4, 1, 1);
		layout->addWidget(color5, 0, 5, 1, 1);
	}
	else if (color == 3)
	{
		layout->addWidget(color0, 0, 1, 1, 1);
		layout->addWidget(color1, 0, 2, 1, 1);
		layout->addWidget(color2, 0, 3, 1, 1);
		layout->addWidget(color4, 0, 4, 1, 1);
		layout->addWidget(color5, 0, 5, 1, 1);
	}
	else if (color == 4)
	{
		layout->addWidget(color0, 0, 1, 1, 1);
		layout->addWidget(color1, 0, 2, 1, 1);
		layout->addWidget(color2, 0, 3, 1, 1);
		layout->addWidget(color3, 0, 4, 1, 1);
		layout->addWidget(color5, 0, 5, 1, 1);
	}
	else if (color == 5)
	{
		layout->addWidget(color0, 0, 1, 1, 1);
		layout->addWidget(color1, 0, 2, 1, 1);
		layout->addWidget(color2, 0, 3, 1, 1);
		layout->addWidget(color3, 0, 4, 1, 1);
		layout->addWidget(color4, 0, 5, 1, 1);
	}
}

void ColorMenu::keyPressEvent(QKeyEvent *event) {
	if (event->key() == Qt::Key_Escape) {
		emit escapeKeyPressed();
		this->hide();
	}
}
