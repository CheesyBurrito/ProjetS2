#pragma once
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QPainter>
#include "CharacterTraits.h"
#include "Character.h"

class CharacterCard : public QPushButton
{
	Q_OBJECT
private:
	int cardWidth;
	int cardHeight;
	bool isFlipped = false;
	bool isSet = true;
	bool isChosenCharacter;

	QPixmap picture;
	QIcon pictureIcon;
	QPixmap flippedCard;
	QIcon flippedCardIcon;

	Character* character;

	//TODO:REPLACE TRAITS BY COMPLETE CHARACTER WHEN ADDING THE GAME TO THE UI
	CharacterTraits traits;

public slots:
	void flipCard();
	void zoomCard();
	void setChosenCharacter(Character* character);

signals:
	void hovered(std::string traits);
	void doubleClicked();
	void clickedCharacter(Character*);

protected:
	virtual void enterEvent(QEvent* e);
	virtual void mouseDoubleClickEvent(QMouseEvent* event);
	virtual void mousePressEvent(QMouseEvent* event);


public:
	//OLD CONSTRUCTOR DELETE WHEN BACKEND IS CONNECTED
	CharacterCard(QWidget *parent, int width, QString path, string characterPath, bool chosenCharacter = false);
	CharacterCard(QWidget *parent, int width, Character* character = NULL, bool chosenCharacter = false);
	~CharacterCard();
	void setupRessources();
	int getCardHeight();
	bool getIsFlipped() { return isFlipped; }
};

