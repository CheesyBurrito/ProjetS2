/****************************************
GuessWho ProjetS2 - APP7Gi

P14
William Adam-Grenier - adaw2602
Charles Quesnel - quec2502
Maxime St-Onge - stom2105

Avril 2018

SideMenu.h
*****************************************/

#pragma once
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <string>
#include <QPushButton>
#include <QIcon>
#include <QSpinBox>
#include "QuestionMenuBar.h"

class SideMenu : public QWidget
{
	Q_OBJECT

private:
	QLabel * background;
	QLabel * cornerBackground;
	QLabel * characteristics;
	QGridLayout * layout;
	QVBoxLayout * scoreLayout;
	QHBoxLayout * hLayout;
	QLabel * infoText;
	QIcon zoomModeIcon;
	QIcon normalModeIcon;
	QPushButton * zoomButton;
	bool zoomMode = false;
	QLabel * nbHiddenCharactersLabel;
	QuestionMenuBar * questionMenuBar;
	int menuHeight, menuWidth;

	QPushButton * guessWhoButton;

public slots:
	void setTraits(std::string newTraits);
	void switchZoomIcon();

signals:
	void lowerBarTest(std::string, int);

public:
	SideMenu(QWidget *parent, int height, int width);
	~SideMenu();

	void setupLayouts();
	void setupWidgets();
	void setNbHiddenCharacter(int nb);

	QuestionMenuBar* getQuestionMenuBar() { return questionMenuBar; }
	QPushButton* getZoomButton() { return zoomButton; }
	QPushButton* getGuessWhoButton() { return guessWhoButton; }


};

