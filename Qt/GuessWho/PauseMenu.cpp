#include "PauseMenu.h"


PauseMenu::PauseMenu(QWidget* parent)
{
	this->setFixedSize(200, 200);
	this->setWindowFlag(Qt::WindowStaysOnTopHint);
	this->setWindowFlag(Qt::FramelessWindowHint);

}


PauseMenu::~PauseMenu()
{
}

void PauseMenu::keyPressEvent(QKeyEvent *event) {
	if (event->key() == Qt::Key_Escape) {
		emit escapeKeyPressed();
	}
}