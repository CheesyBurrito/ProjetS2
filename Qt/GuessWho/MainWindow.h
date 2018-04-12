
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QKeyEvent>
#include <QMessageBox>
#include <QSound>
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
	void nextSong();
	void prevSong();

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
	QSound *electroCabello;
	QSound *epicSaxGuy;
	QSound *luckyDay;
	QSound *weAreOne;
	QSound *adventures;
	QSound *summer;
	QSound *carefree;
	QString activeSong;
	
};
	
#endif 