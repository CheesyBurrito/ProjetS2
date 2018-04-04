#pragma once
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

class CharacterCard : public QPushButton
{
	Q_OBJECT
private:
	int cardHeigth;
	bool isFlipped = false;

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
	CharacterCard(QWidget *parent, int height, QString path);
	~CharacterCard();
};

