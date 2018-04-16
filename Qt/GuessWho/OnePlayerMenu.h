/****************************************
GuessWho ProjetS2 - APP7Gi

P14
William Adam-Grenier - adaw2602
Charles Quesnel - quec2502
Maxime St-Onge - stom2105

Avril 2018

OnePlayerMenu.h
*****************************************/

#pragma once
#include <QWidget>
#include <QFont>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>
#include <QLCDNumber>
#include <QSlider>
#include "MenuButton.h"
#include "ColorMenu.h"

class OnePlayerMenu : public QWidget
{
	Q_OBJECT

public slots:
	void createOnePlayerMenu();
	void setOnePlayerGame();
	void showColorMenu();
	void set_Enabled();

public:
	OnePlayerMenu(QWidget* parent, int colorMenu);
	~OnePlayerMenu();

	ColorMenu* getColorMenuPlayer1() { return player1Menu; }
	QPushButton* getColorMenuButtonPlayer1() { return colorMenuPlayer1; }
	QString getPlayer1Name() { return player1Name; }
	int getNumGames() { return m_lcd->value(); }
	MenuButton* getOkButton() { return ok; }
	void setColorButton(int color);

private:
	QFormLayout * layout;
	int widthImage;
	int heightImage;
	int color;
	QString player1Name;

	QHBoxLayout *playerNameLayout;

	ColorMenu* player1Menu;
	QPushButton *colorMenuPlayer1;
	QLCDNumber *m_lcd;
	QSlider *m_slider;
	QLabel *numGames;
	QLabel *name1;
	QLineEdit *player1;
	MenuButton *ok;

};