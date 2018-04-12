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
	void questionMenuSetup();
	std::string convertBoolToString(bool answer);

//Methods that should only be called by the constructor
protected:
	void constructorLogic();
	void creatingObjects();
	void connectSignals();
	void settingWidgets();
	void settingMainWindow();
	void settingSounds();

	void connectP1ToTree();
	void disconnectP1ToTree();
	void connectP2ToTree();
	void disconnectP2ToTree();
		
public slots:
	void deleteStart();
	void showMenuWindow();
	void gameWindow();
	void returnToMenu();
	void quitGame();
	void nextSong();
	void prevSong();
	void playPause();

	//GameFunctions
	void p1_chooseCharacter();
	void p1_askFirstQuestion();
	void p1_askQuestion();
	void p1_answerQuestion(std::vector<int>);
	void p1_answerQuestionYes();
	void p1_answerQuestionNo();
	void p2_chooseCharacter();
	void p1_getLastAnswer();
	void p2_askQuestion();
	void p2_answerQuestion(std::vector<int>);
	void p2_answerQuestionYes();
	void p2_answerQuestionNo();
	void p2_getLastAnswer();

signals:
	void escapeKeyPressed();
	void keyPressed();

private:
	int numberGames;
	int numberPlayer;
	int activeSong;
	bool secondPlayerIsBot;
	bool play;
	QString soundsFileExtension = ".wav";
	QString defaultSongPath = "./Sounds/"; //Default path of the sosund effect
	//Variables for storing the sound effects
	std::vector<QSound*> soundEffect;
	std::vector<string> soundEffectNames;
	//Variables for the game music
	std::vector<QSound*> songPlaylist;
	std::vector<QString> songNames;
	
	StartWindow *start;
	MenuWindow *menu;
	GameWindow *player1GameWindow;
	GameWindow *player2GameWindow;
	Games *gameLogic;
	QString player1Name;
	QString player2Name;
	bool p2_lastAnswer;
	bool p1_lastAnswer;
	std::vector<int> p1_lastQuestion;
	std::vector<int> p2_lastQuestion;
	
	
};
	
#endif 