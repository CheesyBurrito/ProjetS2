#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QWidget>
#include <QFont>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QPixmap>
#include <QLCDNumber>
#include <QSlider>
#include <QFileDialog>
#include "MainMenu.h"
#include "OptionsMenu.h"
#include "OnePlayerMenu.h"
#include "TwoPlayersMenu.h"

class MenuWindow : public QWidget
{
	Q_OBJECT

	public slots:
		void createMenuWindow();
		void setOnePlayerGame();
		void setTwoPlayersGame();
		void showMainMenu();

	public:
		MenuWindow(QWidget* parent);
		~MenuWindow();
		int getNumberGames() { return numberGames; }
		QString  getPlayer1Name() { return player1Name; }
		QString  getPlayer2Name() { return player2Name; }
		QPushButton* getOkOnePlayerButton() { return onePlayerMenu->getOkButton(); }
		QPushButton* getOkTwoPlayersButton() { return twoPlayersMenu->getOkButton(); }

	private:
		MainMenu * mainMenu;
		OptionsMenu *optionsMenu;
		OnePlayerMenu *onePlayerMenu;
		TwoPlayersMenu *twoPlayersMenu;
		QHBoxLayout * layout;
		QLabel *image;
		int widthImage;
		int heightImage;
		int numberGames;
		QString player1Name;
		QString player2Name;
};
#endif 