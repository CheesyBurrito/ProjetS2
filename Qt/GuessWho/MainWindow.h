
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QDebug>
#include "MenuWindow.h"
#include "StartWindow.h"


class MainWindow : public QMainWindow
{
	Q_OBJECT

	public:
		MainWindow();
		~MainWindow();
	public slots:
		void openMenu();
		void menuWindow();
		void onePlayerWindow();
		void twoPlayersWindow();
		void optionsWindow();
		void gameWindow();
	private:
		StartWindow *start;
		MenuWindow *menu;
		QString joueur1Name;
		QString joueur2Name;
		int numberGames;
		int numberPlayer;
};
	
#endif 