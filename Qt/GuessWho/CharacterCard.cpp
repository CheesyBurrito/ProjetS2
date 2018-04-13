/****************************************
GuessWho ProjetS2 - APP7Gi

P14
William Adam-Grenier - adaw2602
Charles Quesnel - quec2502
Maxime St-Onge - stom2105

Avril 2018

CharacterCard.cpp
*****************************************/

#include "CharacterCard.h"

CharacterCard::CharacterCard(QWidget *parent, int width, Character* character, bool chosenCharacter) {
	this->character = character;
	cardWidth = width;
	cardHeight = 1.4*width;
	isChosenCharacter = chosenCharacter;
	if (isChosenCharacter)
		isSet = false;

	setupRessources();
	this->setMouseTracking(true);
}

CharacterCard::~CharacterCard()
{
}

void CharacterCard::setupRessources() {
	//Sets the empty image with a red border for the 21st character
	if (isChosenCharacter) {
		QImage background("./Photos/header_logo.png");
		QImage back("./Photos/BlankCharacter.png");

		QImage front("./Photos/emptyFrame.png");

		QPixmap combined(front.size());
		QPainter p(&combined);
		p.drawImage(QPoint(0, 0), background);
		p.drawImage(QPoint(0, 0), back);
		p.drawImage(QPoint(0, 0), front);
		p.end();

		picture = combined;
		flippedCard.load("./Photos/red_turned_card.png");
	}

	else {
		picture.load(QString::fromStdString(character->get_picture_path()));
		flippedCard.load("./Photos/turned_card.png");
	}

	pictureIcon.addPixmap(picture.scaled(cardWidth, cardHeight));
	flippedCardIcon.addPixmap(flippedCard.scaled(cardWidth, cardHeight));


	this->setIcon(pictureIcon);

	this->setIconSize(QSize(cardWidth, cardHeight));
	this->setFixedSize(QSize(cardWidth, cardHeight));
}

void CharacterCard::flipCard() {

		if (isFlipped)
			this->setIcon(pictureIcon);
		else
			this->setIcon(flippedCardIcon);

		isFlipped = !isFlipped;
}

void CharacterCard::enterEvent(QEvent* e)
{
	//OLD VERSION DELETE WHEN BACK-END IS CONNECTED
	/*
	if(!isFlipped && this->traits.getEyes() != -1)
		emit hovered(this->traits.convertPropertiesToString());
	*/
	//NEW VERSION
	if (!isFlipped && isSet){
		std::string traits = this->character->get_character_traits()->convertPropertiesToString();
		emit hovered(traits);
	}
	

	QWidget::enterEvent(e);
}

void CharacterCard::mouseDoubleClickEvent(QMouseEvent* event) {
	emit doubleClicked();
}

void CharacterCard::mousePressEvent(QMouseEvent* event) {
	emit clickedCharacter(character);
	QWidget::mousePressEvent(event);
}

void CharacterCard::zoomCard() {

	if (!isFlipped) {
		QWidget *zoomWindow;
		zoomWindow = new QWidget;
		QVBoxLayout *zoomLayout = new QVBoxLayout(zoomWindow);
		QLabel *img = new QLabel(zoomWindow);
		img->setPixmap(picture);
		zoomLayout->addWidget(img);

		zoomWindow->setStyleSheet("background-image: url(./Photos/header_logo.png)");
		zoomWindow->setLayout(zoomLayout);
		zoomWindow->setWindowFlags(Qt::SplashScreen);
		zoomWindow->show();
	}
}

void CharacterCard::setChosenCharacter(Character* character) {
	isSet = true;
	this->character = character;
	QImage background("./Photos/header_logo.png");
	QImage back(QString::fromStdString(character->get_picture_path()));

	QImage front("./Photos/emptyFrame.png");

	QPixmap combined(front.size());
	QPainter p(&combined);
	p.drawImage(QPoint(0, 0), background);
	p.drawImage(QPoint(0, 0), back);
	p.drawImage(QPoint(0, 0), front);
	p.end();

	picture = combined;
	pictureIcon.addPixmap(picture.scaled(cardWidth, cardHeight));
	this->setIcon(pictureIcon);
}

int CharacterCard::getCardHeight()
{
	return cardHeight;
}