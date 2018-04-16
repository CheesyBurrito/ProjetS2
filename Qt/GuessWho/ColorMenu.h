/****************************************
GuessWho ProjetS2 - APP7Gi

P14
William Adam-Grenier - adaw2602
Charles Quesnel - quec2502
Maxime St-Onge - stom2105

Avril 2018

ColorMenu.h
*****************************************/

#pragma once

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QKeyEvent>

class ColorMenu : public QWidget
{
	Q_OBJECT

private:
	QGridLayout * layout;
	QPushButton * color0;
	QPushButton * color1;
	QPushButton * color2;
	QPushButton * color3;
	QPushButton * color4;
	QPushButton * color5;
	QLabel *colorBackground;

signals:
	void escapeKeyPressed();

public:
	ColorMenu(QWidget* parent);
	~ColorMenu();
	void setColorMenu(int color);

	void keyPressEvent(QKeyEvent *event);
	QPushButton * getColor0Button() { return color0; }
	QPushButton * getColor1Button() { return color1; }
	QPushButton * getColor2Button() { return color2; }
	QPushButton * getColor3Button() { return color3; }
	QPushButton * getColor4Button() { return color4; }
	QPushButton * getColor5Button() { return color5; }


};
