/****************************************
GuessWho ProjetS2 - APP7Gi

P14
William Adam-Grenier - adaw2602
Charles Quesnel - quec2502
Maxime St-Onge - stom2105

Avril 2018

PauseMenu.h
*****************************************/

#pragma once

#include <QWidget>
#include <QKeyEvent>
#include <QGridLayout>
#include <QPushButton>
#include "MenuButton.h"
#include "MediaPlayer.h"

class PauseMenu : public QWidget
{
	Q_OBJECT

private:
	QGridLayout * layout;
	MenuButton * quitButton;
	MenuButton * resumeButton;
	MenuButton * cancelGameButton;
	QLabel *pauseBackground;
	MediaPlayer *media_Player;

signals :
	void escapeKeyPressed();

public:
	PauseMenu(QWidget* parent);
	~PauseMenu();

	void keyPressEvent(QKeyEvent *event);
	MenuButton * getQuitButton() { return quitButton; }
	MenuButton * getResumeButton() { return resumeButton; }
	MenuButton * getCancelGameButton() { return cancelGameButton; }
	QPushButton* getNextButton() { return media_Player->getNextButton(); }
	QPushButton* getPrevButton() { return media_Player->getPrevButton(); }
	QPushButton * getMuteButton() { return media_Player->getMuteButton(); }
	QLabel* getActiveSongLabel() { return media_Player->getActiveSongLabel(); }

};

