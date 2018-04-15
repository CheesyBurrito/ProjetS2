/****************************************
GuessWho ProjetS2 - APP7Gi

P14
William Adam-Grenier - adaw2602
Charles Quesnel - quec2502
Maxime St-Onge - stom2105

Avril 2018

MainWindow.h
*****************************************/


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QKeyEvent>
#include <QMessageBox>
#include <QSound>
#include <QTimer>
#include "MenuWindow.h"
#include "StartWindow.h"
#include "GameWindow.h"
#include "Games.h"
#include "FPGA.h"

#define GAME_OVER_WON 2
#define GAME_OVER_LOST 1
#define GAME_OVER_NOT 0

#define FPGA_READ_INTERVAL 100
#define PHONEME_CLIC detectedPhoneme3() //I
#define PHONEME_YES detectedPhoneme2() //A
#define PHONEME_NO detectedPhoneme4() //E
#define PHONEME_KEY Qt::Key_M

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
	void disconnectFPGA();
	//bool checkEndGameCondition();
		
public slots:
	void deleteStart();
	void showMenuWindow();
	void gameWindow();
	void returnToMenu();
	void exitAfterGameOver();
	void quitGame();
	void nextSong();
	void prevSong();
	void playPause();
	void emulateMouseClick();

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
	void gameOver(QString winner);
	bool checkEndGameCondition();

signals:
	void wKeyPressed();
	void sKeyPressed();
	void enterKeyPressed();
	void escapeKeyPressed();
	void keyPressed();
	void phonemeKeyPressed();

private:
	int numGames;
	int numGamesPlayed;
	int winPlayer1;
	int winPlayer2;
	int numberPlayer;
	int activeSong;
	int player1GameOver = GAME_OVER_NOT;
	int player2GameOver = GAME_OVER_NOT;
	bool secondPlayerIsBot;
	bool play;
	bool gameWindowCreate = false;
	QString winner = "";
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
	FPGA fpgaComm;
	QTimer timer;
	
	
};
	
#endif 