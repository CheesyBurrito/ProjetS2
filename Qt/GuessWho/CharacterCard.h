#pragma once
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QPainter>
#include "CharacterTraits.h"

class CharacterCard : public QPushButton
{
	Q_OBJECT
private:
	int cardWidth;
	int cardHeight;
	bool isFlipped = false;
	bool isChosenCharacter;

	QPixmap picture;
	QIcon pictureIcon;
	QPixmap flippedCard;
	QIcon flippedCardIcon;

	//TODO:REPLACE TRAITS BY COMPLETE CHARACTER WHEN ADDING THE GAME TO THE UI
	CharacterTraits traits;

public slots:
	void flipCard();
	void zoomCard();

signals:
	void hovered(std::string traits);
	void doubleClicked();

protected:
	virtual void enterEvent(QEvent* e);
	virtual void mouseDoubleClickEvent(QMouseEvent* event);


public:
	CharacterCard(QWidget *parent, int height, QString path, string characterPath, bool chosenCharacter = false);
	~CharacterCard();
	void setChosenCharacter(QString path);
	int getCardHeight();
};

