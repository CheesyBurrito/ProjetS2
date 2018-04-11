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
	int height, width;
	QWidget* parent;
	CharacterManager* c_manager;
	public slots :
	void togglePauseMenu();
	void toggleZoomMode();

public:
	GameWindow(QWidget *parent, CharacterManager* characterManager);
	~GameWindow();

	void setupLayouts();
	void setupWidgets();
	void setupConnections();

	PauseMenu* getPauseMenu() { return pauseMenu; }
	SideMenu* getSideMenu() { return sideMenu; }
};
