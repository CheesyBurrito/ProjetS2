
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
#include "MenuButton.h"
#include "AddCharacter.h"

class MenuWindow : public QWidget
{
	Q_OBJECT

	public slots:
		void setMenuHoveredButton(MenuButton *button);
		void setOptionsHoveredButton(MenuButton *button);
		void showDialog();
		void addCharacters();
		void set_Menu();

	signals:
		void hovered();

	public:
		MenuWindow(QWidget* parent);
		~MenuWindow();
		void startMenu();
		void onePlayerWindow();
		void twoPlayersWindow();
		void optionsWindow();
		void deleteOptionsWindow();
		void deletePlayersWindow();

		AddCharacter *AddCharacterWindow;
		std::vector<QString> *character;

		MenuButton* getOnePlayerButton() { return onePlayer; }
		MenuButton* getTwoPlayersButton() { return twoPlayers; }
		MenuButton* getOptionsButton() { return optionsButton; }
		MenuButton* getQuitButton() { return quitButton; }

		MenuButton* getAddCharacterButton() { return addCharacter; }
		MenuButton* getCreateNewListButton() { return createNewList; }
		MenuButton* getChangeListButton() { return changeList; }
		MenuButton* getBackButton() { return back; }
		QPushButton* getOkButton() { return ok; }

		QString getJoueur1Name();
		QString getJoueur2Name();
		QString getListName();
		int getNumberGames();

	private:
		QGridLayout * layoutPrincipal;
		QLabel *image;
		int widthImage;
		int numberPlayer;

		//menu1
		MenuButton *onePlayer;
		MenuButton *twoPlayers;
		MenuButton *optionsButton;
		MenuButton *quitButton;

		//menu2
		MenuButton *addCharacter;
		MenuButton *createNewList;
		MenuButton *changeList;
		MenuButton *back;
		QLineEdit *active_List;
		QString activeList = "./Ressources/CharacterFiles/characterList.gw";
		QLabel *list;
		
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