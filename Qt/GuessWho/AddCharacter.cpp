#include "AddCharacter.h"


AddCharacter::AddCharacter(QWidget* parent)
{
	layout = new QGridLayout(this);
	cancelButton = new QPushButton("Cancel", this);
	okButton = new QPushButton("Ok", this);

	this->setFixedSize(500, 500);
	this->setWindowFlag(Qt::WindowStaysOnTopHint);
	this->setWindowFlag(Qt::FramelessWindowHint);
	layout->addWidget(okButton, 0, 0);
	layout->addWidget(cancelButton, 1, 0);
	this->setLayout(layout);
}


AddCharacter::~AddCharacter()
{
}