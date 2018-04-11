
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QKeyEvent>
#include <QMessageBox>
#include "MenuWindow.h"
#include "StartWindow.h"
#include "GameWindow.h"
#include "Games.h"


class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow();
	~MainWindow();
	void keyPressEvent(QKeyEvent *event);
	void questionMenuSetup();

//Methods that should only be called by the constructor
protected:
	void constructorLogic();
	void creatingObjects();
	void connectSignals();
	void settingWidgets();
	void settingMainWindow();
		
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
	int numberGames;
	int numberPlayer;
	StartWindow *start;
	MenuWindow *menu;
	GameWindow *game;
	Games *gameLogic;
	QString player1Name;
	QString player2Name;
	
};
	
#endif 