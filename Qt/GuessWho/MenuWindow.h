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
		void onePlayerWindow();
		void twoPlayersWindow();
		QPushButton* getQuitButton();
		QPushButton* getOnePlayerButton();
		QPushButton* getTwoPlayersButton();
	private:
		QPushButton *quitButton;
		QPushButton *onePlayer;
		QPushButton *twoPlayers;

		QGridLayout *layoutPrincipal;
		QLabel *image;

		QLineEdit *joueur1;
		QLineEdit *joueur2;

};
#endif 