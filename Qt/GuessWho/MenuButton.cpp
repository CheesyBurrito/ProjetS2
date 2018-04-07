#include "MenuButton.h"

MenuButton::MenuButton(QWidget *parent, QString text, bool selected): QPushButton(parent)
{
	setText(text);
	setMouseTracking(true);
	setFlat(true);
	setStyleSheet("background-image: url(./Photos/button.png); color : white; Text-align:left");
	setCursor(Qt::PointingHandCursor);
	setFont(QFont("Walkway Bold", 30));
	setFixedWidth(520);
}

MenuButton::~MenuButton()
{
}

void MenuButton::setIsSelected(bool selected)
{
	isSelected = selected;
	if(selected == true)
		setStyleSheet("background-image: url(./Photos/button_hovered.png); color : black; Text-align:left");
	else
		setStyleSheet("background-image: url(./Photos/button.png); color : white; Text-align:left");
}

void MenuButton::enterEvent(QEvent* e)
{
	emit hovered();
	setIsSelected(true);
	QWidget::enterEvent(e);
}