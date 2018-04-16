/****************************************
GuessWho ProjetS2 - APP7Gi

P14
William Adam-Grenier - adaw2602
Charles Quesnel - quec2502
Maxime St-Onge - stom2105

Avril 2018

TwoPlayersMenu.h
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
#include "ColorMenu.h"
#include "MenuButton.h"

class TwoPlayersMenu : public QWidget
{
	Q_OBJECT

		public slots:
	void createTwoPlayersMenu();
	void setTwoPlayersGame();
	void showColorMenu1();
	void showColorMenu2();
	void set_Enabled();

public:
	TwoPlayersMenu(QWidget* parent, int colorMenu1, int colorMenu2);
	~TwoPlayersMenu();

	QPushButton* getColorMenuButtonPlayer1() { return colorMenuPlayer1; }
	QPushButton* getColorMenuButtonPlayer2() { return colorMenuPlayer2; }
	ColorMenu* getColorMenuPlayer1() { return player1Menu; }
	ColorMenu* getColorMenuPlayer2() { return player2Menu; }
	QString getPlayer1Name() { return player1Name; }
	QString getPlayer2Name() { return player2Name; }
	int getNumGames() { return m_lcd->value(); }
	QPushButton* getOkButton() { return ok; }
	void setColorButton(int color_1, int color_2);
private:
	QFormLayout * layout;
	int widthImage;
	int heightImage;
	int color1;
	int color2;

	QString player1Name;
	QString player2Name;

	QHBoxLayout *playerNameLayout1;
	QHBoxLayout *playerNameLayout2;

	ColorMenu* player1Menu;
	ColorMenu* player2Menu;
	QPushButton *colorMenuPlayer1;
	QPushButton *colorMenuPlayer2;
	QLCDNumber *m_lcd;
	QSlider *m_slider;
	QLabel *numGames;
	QLabel *name1;
	QLineEdit *player1;
	QLabel *name2;
	QLineEdit *player2;
	MenuButton *ok;

};