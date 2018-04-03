#include <QWidget>
#include <QFont>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QPixmap>

#ifndef MENUWINDOW_H
#define MENUWINDOW_H


class MenuWindow : public QWidget
{
	public:
		MenuWindow();
		~MenuWindow();
		QPushButton* getQuitButton();
		QPushButton* getOnePlayerButton();
		QPushButton* getTwoPlayersButton();
	private:
		QPushButton *quitButton;
		QPushButton *onePlayer;
		QPushButton *twoPlayers;
		QHBoxLayout *layoutPrincipal;

};
#endif 