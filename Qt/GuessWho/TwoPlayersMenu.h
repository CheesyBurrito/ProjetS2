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
#include <QGridLayout>
#include <QLCDNumber>
#include <QSlider>
#include "MenuButton.h"

class TwoPlayersMenu : public QWidget
{
	Q_OBJECT

		public slots:
	void createTwoPlayersMenu();

public:
	TwoPlayersMenu(QWidget* parent);
	~TwoPlayersMenu();

	QString getPlayer1Name() { return player1->text(); }
	QString getPlayer2Name() { return player2->text(); }
	int getNumGames() { return m_lcd->value(); }
	QPushButton* getOkButton() { return ok; }

private:
	QGridLayout * layout;
	int widthImage;
	int heightImage;

	QLCDNumber *m_lcd;
	QSlider *m_slider;
	QLabel *numGames;
	QLabel *name1;
	QLineEdit *player1;
	QLabel *name2;
	QLineEdit *player2;
	MenuButton *ok;

};
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
#include <QGridLayout>
#include <QLCDNumber>
#include <QSlider>
#include "MenuButton.h"

class TwoPlayersMenu : public QWidget
{
	Q_OBJECT

		public slots:
	void createTwoPlayersMenu();

public:
	TwoPlayersMenu(QWidget* parent);
	~TwoPlayersMenu();

	QString getPlayer1Name() { return player1->text(); }
	QString getPlayer2Name() { return player2->text(); }
	int getNumGames() { return m_lcd->value(); }
	QPushButton* getOkButton() { return ok; }

private:
	QGridLayout * layout;
	int widthImage;
	int heightImage;

	QLCDNumber *m_lcd;
	QSlider *m_slider;
	QLabel *numGames;
	QLabel *name1;
	QLineEdit *player1;
	QLabel *name2;
	QLineEdit *player2;
	MenuButton *ok;

};