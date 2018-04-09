#include "AddCharacter.h"


AddCharacter::AddCharacter(QWidget* parent)
{
	createAddCharacter();
}


AddCharacter::~AddCharacter()
{
}

void AddCharacter::createAddCharacter()
{
	layout = new QVBoxLayout(this);
	cancelButton = new QPushButton("Cancel", this);
	okButton = new QPushButton("Ajouter", this);
	eyes = new QGroupBox("Yeux", this);
	hair = new QGroupBox("Cheveux", this);
	accessories = new QGroupBox("Accesoires", this);
	sexe = new QGroupBox("Genre", this);
	facialHair = new QGroupBox("Pilosité", this);
	age = new QGroupBox("Âge", this);
	skinColor = new QGroupBox("Couleur de peau", this);
	this->setFixedSize(800, 500);
	this->setWindowFlag(Qt::WindowStaysOnTopHint);
	this->setWindowFlag(Qt::FramelessWindowHint);
	layout->addWidget(eyes);
	layout->addWidget(hair);
	layout->addWidget(accessories);
	layout->addWidget(sexe);
	layout->addWidget(facialHair);
	layout->addWidget(age);
	layout->addWidget(skinColor);
	layout->addWidget(okButton, 0, 0);
	layout->addWidget(cancelButton, 1, 0);
	this->setLayout(layout);
}