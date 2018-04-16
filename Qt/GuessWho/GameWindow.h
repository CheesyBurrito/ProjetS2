/****************************************
GuessWho ProjetS2 - APP7Gi

P14
William Adam-Grenier - adaw2602
Charles Quesnel - quec2502
Maxime St-Onge - stom2105

Avril 2018

GameWindow.h
*****************************************/

#pragma once
#include <QWidget>
#include "CharacterGrid.h"
#include "SideMenu.h"
#include "LowerBar.h"
#include <QGridLayout>
#include <QLabel>
#include <vector>
#include "PauseMenu.h"
#include <QKeyEvent>
#include <QSound>
#include "PauseMenu.h"
#include "GameOverMenu.h"
#include "CharacterManager.h"
#include "Player.h"


class GameWindow : public QWidget
{
	Q_OBJECT
private:
	QGridLayout * layout;
	CharacterGrid *grid;
	LowerBar *lowerBar;
	SideMenu *sideMenu;
	QCursor zoomCursor;
	QCursor guessCursor;
	PauseMenu *pauseMenu;
	GameOverMenu *gameOverMenu;
	bool isPaused = false;
	bool zoomMode = false;
	bool selectMode = false;
	bool guessMode = false;
	int height, width;
	QWidget* parent;
	QSound *pauseSound;

	Player* player;

	public slots :
	void togglePauseMenu();
	void showGameOver();
	void toggleZoomMode();
	void toggleSelectMode();
	void enableOkButton();
	void setNormalMode(std::vector<int>);

	void setChosenCharacter(Character* character);
	void guessWhoMode();
	void setGuessMode();
	void emitGuessWho(Character* c);

signals:
	void guessWho(std::vector<int>);

public:
	GameWindow(QWidget* parent,  Player* player1, int menuColor);
	~GameWindow();

	void setupLayouts();
	void setupWidgets();
	void setupConnections();

	PauseMenu* getPauseMenu() { return pauseMenu; }
	GameOverMenu* getGameOverMenu() { return gameOverMenu; }
	SideMenu* getSideMenu() { return sideMenu; }
	LowerBar* getLowerBar() { return lowerBar; }
	CharacterGrid* getGrid() { return grid; }
	bool getSelectMode() { return selectMode; }
	QPushButton* getNextButton() { return pauseMenu->getNextButton(); }
	QPushButton* getPrevButton() { return pauseMenu->getPrevButton(); }
	QPushButton * getMuteButton() { return pauseMenu->getMuteButton(); }
	QLabel* getActiveSongLabel() { return pauseMenu->getActiveSongLabel(); }
	int color;
};
