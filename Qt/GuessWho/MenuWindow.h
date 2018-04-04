
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

class MenuWindow : public QWidget
{
	public:
		MenuWindow(QWidget* parent);
		~MenuWindow();
		void onePlayerWindow();
		void twoPlayersWindow();
		void optionsWindow();
		void startMenu();
		void deleteOptionsWindow();
		void deletePlayersWindow();
		
		QPushButton* getOnePlayerButton();
		QPushButton* getTwoPlayersButton();
		QPushButton* getOptionsButton();
		QPushButton* getQuitButton();

		QPushButton* getAddCharacterButton();
		QPushButton* getListCharacterButton();
		QPushButton* getExportCharacterButton();
		QPushButton* getBackButton();
		QPushButton* getOkButton();

		QString getJoueur1Name();
		QString getJoueur2Name();
		int getNumberGames();

	private:

		QGridLayout * layoutPrincipal;
		QLabel *image;
		int widthImage;
		int numberPlayer;

		//menu1
		QPushButton *onePlayer;
		QPushButton *twoPlayers;
		QPushButton *optionsButton;
		QPushButton *quitButton;

		//menu2
		QPushButton *addCharacter;
		QPushButton *listCharacter;
		QPushButton *exportCharacter;
		QPushButton *back;
		
		//menu3
		QLabel *nom1;
		QLabel *nom2;
		QLabel *numGames;
		QLineEdit *joueur1;
		QLineEdit *joueur2;
		QPushButton *ok;
		QLCDNumber *m_lcd;
		QSlider *m_slider;
};
#endif 