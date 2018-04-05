
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QDebug>
#include "MenuWindow.h"
#include "StartWindow.h"
#include "GameWindow.h"


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
		void showDialog();
		void showCharacterWindow();

	private:
		StartWindow *start;
		MenuWindow *menu;
		GameWindow *game;
		QString joueur1Name;
		QString joueur2Name;
		int numberGames;
		int numberPlayer;
};
	
#endif 