#pragma once
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QPainter>

class CharacterCard : public QPushButton
{
	Q_OBJECT
private:
	int cardHeigth;
	bool isFlipped = false;
	bool isChosenCharacter;

	QPixmap picture;
	QIcon pictureIcon;
	QPixmap flippedCard;
	QIcon flippedCardIcon;

public slots:
	void flipCard();
	void zoomCard();

signals:
	void hovered();
	void doubleClicked();

protected:
	virtual void enterEvent(QEvent* e);
	virtual void mouseDoubleClickEvent(QMouseEvent* event);


public:
	CharacterCard(QWidget *parent, int height, QString path, bool chosenCharacter = false);
	~CharacterCard();
	void setChosenCharacter(QString path);
};

