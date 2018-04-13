/****************************************
GuessWho ProjetS2 - APP7Gi

P14
William Adam-Grenier - adaw2602
Charles Quesnel - quec2502
Maxime St-Onge - stom2105

Avril 2018

MediaButton.cpp
*****************************************/

#include "MenuButton.h"

MenuButton::MenuButton(QWidget *parent, QString text, bool selected): QPushButton(parent)
{
	clickedSound = new QSound("./Sounds/portal_button_sound.wav", this);
	setText(text);
	setMouseTracking(true);
	setFlat(true);
	setStyleSheet("background-image: url(./Photos/button.png); color : white; Text-align:left");
	setCursor(Qt::PointingHandCursor);
	setFont(QFont("Walkway Bold", 30));
	setFixedWidth(520);
	connect(this, SIGNAL(clicked()), this, SLOT(playClickedSound()));
	connect(this, SIGNAL(hovered()), this, SLOT(is_Selected()));
	connect(this, SIGNAL(leaveHovered()), this, SLOT(not_Selected()));
}

MenuButton::~MenuButton()
{
}

void MenuButton::is_Selected()
{
	isSelected = true;
	setStyleSheet("background-image: url(./Photos/button_hovered.png); color : black; Text-align:left");
}

void MenuButton::not_Selected()
{
	isSelected = false;
	setStyleSheet("background-image: url(./Photos/button.png); color : white; Text-align:left");
}

void MenuButton::playClickedSound()
{
	clickedSound->play();
}

void MenuButton::enterEvent(QEvent* e)
{
	emit hovered();
	QWidget::enterEvent(e);
}

void MenuButton::leaveEvent(QEvent* e)
{
	emit leaveHovered();
	QWidget::enterEvent(e);
}