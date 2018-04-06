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
	/*QGridLayout *characterGrid;
	std::vector<QLabel*> images;*/
	
	public slots :
		void setZoomMode();
		void setDefaultMode();
		void togglePauseMenu();

public:
	GameWindow(QWidget *parent);
	~GameWindow();
};

