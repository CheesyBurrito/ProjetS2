#pragma once
#include <QWidget>
#include "CharacterGrid.h"
#include "SideMenu.h"
#include "LowerBar.h"
#include <QGridLayout>
#include <QLabel>
#include <vector>

class GameWindow : public QWidget
{
	Q_OBJECT
private:
	QGridLayout *layout;
	CharacterGrid *grid;
	LowerBar *lowerBar;
	SideMenu *sideMenu;
	QCursor zoomCursor;
	/*QGridLayout *characterGrid;
	std::vector<QLabel*> images;*/
	
	public slots :
		void setZoomMode();
		void setDefaultMode();

public:
	GameWindow(QWidget *parent);
	~GameWindow();
};

