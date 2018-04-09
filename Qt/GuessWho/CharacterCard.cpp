#include "CharacterCard.h"



CharacterCard::CharacterCard(QWidget *parent, int width, QString path, string characterPath, bool chosenCharacter):QPushButton(parent)
{
	cardWidth = width;
	cardHeight = 1.4*width;
	isChosenCharacter = chosenCharacter;

	traits.importCharacterFromFile(characterPath);

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
		//picture.load("./Photos/emptyFrame.png");
		flippedCard.load("./Photos/red_turned_card.png");
	}

	else {
		picture.load(path);
		flippedCard.load("./Photos/turned_card.png");
	}

	pictureIcon.addPixmap(picture.scaled(width, cardHeight));
	flippedCardIcon.addPixmap(flippedCard.scaled(width, cardHeight));

	
	this->setIcon(pictureIcon);

	this->setIconSize(QSize(width, cardHeight));
	this->setFixedSize(QSize(width, cardHeight));

	/*QPixmap loopCursorPix("./Photos/zoom.png");
	QCursor loopCursor(loopCursorPix.scaled(25,25));
	this->setCursor(loopCursor);*/

	this->setMouseTracking(true);
	//connect(this, SIGNAL(clicked()), this, SLOT(flipCard()));
	//connect(this, SIGNAL(doubleClicked()), this, SLOT(zoomCard()));
}


CharacterCard::~CharacterCard()
{
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
	if(!isFlipped && this->traits.getEyes() != -1) //TODO : CHANGE TRAIT FOR CHARACTER WHEN CLASS IS IMPLEMENTED
		emit hovered(this->traits.convertPropertiesToString());

	QWidget::enterEvent(e);
}

void CharacterCard::mouseDoubleClickEvent(QMouseEvent* event) {
	emit doubleClicked();
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

void CharacterCard::setChosenCharacter(QString path) {
	QImage background("./Photos/header_logo.png");
	QImage back(path);

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