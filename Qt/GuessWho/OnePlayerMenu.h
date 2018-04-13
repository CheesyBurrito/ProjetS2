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
#include <QGridLayout>
#include <QLCDNumber>
#include <QSlider>
#include "MenuButton.h"

class OnePlayerMenu : public QWidget
{
	Q_OBJECT

public slots:
	void createOnePlayerMenu();

public:
	OnePlayerMenu(QWidget* parent);
	~OnePlayerMenu();

	QString getPlayer1Name() { return player1->text(); }
	MenuButton* getOkButton() { return ok; }

private:
	QGridLayout * layout;
	int widthImage;
	int heightImage;

	QLabel *numGames;
	QLabel *name1;
	QLineEdit *player1;
	MenuButton *ok;

};