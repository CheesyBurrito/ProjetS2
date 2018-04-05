#include "CharacterCard.h"



CharacterCard::CharacterCard(QWidget *parent, int height, QString path, bool chosenCharacter):QPushButton(parent)
{
	cardHeigth = height;
	isChosenCharacter = chosenCharacter;

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
	}

	else
		picture.load(path);

	pictureIcon.addPixmap(picture.scaled(0.715*height, height));

	flippedCard.load("./Photos/turned_card.png");
	flippedCardIcon.addPixmap(flippedCard.scaled(0.715*height, height));

	
	this->setIcon(pictureIcon);

	this->setIconSize(QSize(0.715*height,height));
	this->setFixedSize(QSize(0.715*height, height));

	/*QPixmap loopCursorPix("./Photos/zoom.png");
	QCursor loopCursor(loopCursorPix.scaled(25,25));
	this->setCursor(loopCursor);*/

	this->setMouseTracking(true);
	connect(this, SIGNAL(clicked()), this, SLOT(flipCard()));
	//connect(this, SIGNAL(doubleClicked()), this, SLOT(zoomCard()));
}


CharacterCard::~CharacterCard()
{
}

void CharacterCard::flipCard() {
	QPixmap pixmap;

	if (!isChosenCharacter) { //Can't flip the chose character
		if (isFlipped)
			this->setIcon(pictureIcon);
		else
			this->setIcon(flippedCardIcon);

		isFlipped = !isFlipped;
	}
}

void CharacterCard::enterEvent(QEvent* e)
{
	emit hovered();

	QWidget::enterEvent(e);
}

void CharacterCard::mouseDoubleClickEvent(QMouseEvent* event) {
	emit doubleClicked();
}

void CharacterCard::zoomCard() {

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
	pictureIcon.addPixmap(picture.scaled(0.715*cardHeigth, cardHeigth));
	this->setIcon(pictureIcon);
}