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

class GameWindow : public QWidget
{
	Q_OBJECT
private:
	QGridLayout *layout;
	CharacterGrid *grid;
	LowerBar *lowerBar;
	SideMenu *sideMenu;
	QCursor zoomCursor;
	PauseMenu *pauseMenu;
	bool isPaused = false;
	bool zoomMode = false;
	/*QGridLayout *characterGrid;
	std::vector<QLabel*> images;*/
	
	public slots :
		void togglePauseMenu();
		void toggleZoomMode();

public:
	GameWindow(QWidget *parent);
	~GameWindow();
	PauseMenu* getPauseMenu() { return pauseMenu; }
};

