
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QKeyEvent>
#include <QMessageBox>
#include "MenuWindow.h"
#include "StartWindow.h"
#include "GameWindow.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

	public:
		MainWindow();
		~MainWindow();
		void keyPressEvent(QKeyEvent *event);

	public slots:
		void deleteStart();
		void showMenuWindow();
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