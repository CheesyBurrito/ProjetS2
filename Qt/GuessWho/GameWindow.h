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
private:
	QGridLayout *layout;
	CharacterGrid *grid;
	LowerBar *lowerBar;
	SideMenu *sideMenu;
	/*QGridLayout *characterGrid;
	std::vector<QLabel*> images;*/
	
public:
	GameWindow(QWidget *parent);
	~GameWindow();
};

