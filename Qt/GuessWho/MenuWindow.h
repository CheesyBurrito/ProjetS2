
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
		void showFirstMenu();
		void showOptionsWindow();
		void showOnePlayerWindow();
		void showTwoPlayersWindow();
		void hideOptionsWindow();

	signals:
		void hovered();

	public:
		MenuWindow(QWidget* parent);
		~MenuWindow();
		void createFirstMenu();
		void createOnePlayerWindow();
		void createTwoPlayersWindow();
		void createOptionsWindow();
		void hideOnePlayerWindow();
		void hideTwoPlayersWindow();
		void hideFirstMenu();

		AddCharacter *AddCharacterWindow;

		MenuButton* getOnePlayerButton() { return onePlayer; }
		MenuButton* getTwoPlayersButton() { return twoPlayers; }
		MenuButton* getOptionsButton() { return optionsButton; }
		MenuButton* getQuitButton() { return quitButton; }

		MenuButton* getAddCharacterButton() { return addCharacter; }
		MenuButton* getCreateNewListButton() { return createNewList; }
		MenuButton* getChangeListButton() { return changeList; }
		MenuButton* getBackButton() { return back; }
		QPushButton* getOkButton() { return ok; }

		QString getJoueur1Name() { return joueur1->text();}
		QString getJoueur1_2Name() { return joueur1_2->text(); }
		QString getJoueur2Name() { return joueur2->text(); }
		QString getActiveList() { return activeList; }
		int getNumberGames() { return m_lcd->value(); }
		int getNumberGames_2() { return m_lcd_2->value(); }
		int getNumberPlayer() { return numberPlayer; }
		

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
		QString activeList = "Ressources/CharacterFiles/characterList.gw";
		QLabel *list;
		
		//menu3
		QLabel *nom1;
		QLabel *numGames;
		QLineEdit *joueur1;
		QPushButton *ok;
		QLCDNumber *m_lcd;
		QSlider *m_slider;

		//menu4
		QLabel *nom1_2;
		QLabel *numGames_2;
		QLineEdit *joueur1_2;
		QPushButton *ok_2;
		QLCDNumber *m_lcd_2;
		QSlider *m_slider_2;
		QLabel *nom2;
		QLineEdit *joueur2;
};
#endif 