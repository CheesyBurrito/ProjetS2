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
#include "PauseMenu.h"
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
	PauseMenu *pauseMenu;
	bool isPaused = false;
	bool zoomMode = false;
	bool selectMode = false;
	int height, width;
	QWidget* parent;
	Player* player;
	public slots :
	void togglePauseMenu();
	void toggleZoomMode();
	void toggleSelectMode();

	public slots:
	void setChosenCharacter(Character* character);

public:
	GameWindow(QWidget* parent,  Player* player1);
	~GameWindow();

	void setupLayouts();
	void setupWidgets();
	void setupConnections();

	PauseMenu* getPauseMenu() { return pauseMenu; }
	SideMenu* getSideMenu() { return sideMenu; }
	LowerBar* getLowerBar() { return lowerBar; }
	bool getSelectMode() { return selectMode; }
};
