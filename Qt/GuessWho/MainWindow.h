
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include "MenuWindow.h"
#include "StartWindow.h"
#include "GameWindow.h"
#include <QKeyEvent>
#include <QMessageBox>


class MainWindow : public QMainWindow
{
	Q_OBJECT

	public:
		MainWindow();
		~MainWindow();
		void keyPressEvent(QKeyEvent *event);

	public slots:
		void openMenu();
		void menuWindow();
		void menuWindowFromGame();
		void onePlayerWindow();
		void twoPlayersWindow();
		void optionsWindow();
		void gameWindow();
		void returnToMenu();
		void quitGame();

	signals:
		void escapeKeyPressed();
		void keyPressed();

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