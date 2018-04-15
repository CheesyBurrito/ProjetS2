/****************************************
GuessWho ProjetS2 - APP7Gi

P14
William Adam-Grenier - adaw2602
Charles Quesnel - quec2502
Maxime St-Onge - stom2105

Avril 2018

OptionsMenu.h
*****************************************/

#pragma once
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
#include <QSpacerItem>
#include <QFormLayout>
#include <QString>
#include "MenuButton.h"
#include "AddCharacter.h"
#include "CharacterManager.h"
#include "MediaPlayer.h"

class OptionsMenu : public QWidget
{
	Q_OBJECT

public slots:
	void showDialog();
	void addCharacters();
	void activateOptionsMenu();
	void createOptionsMenu();
	void newList();

public:
	OptionsMenu(QWidget* parent, CharacterManager* characterManager);
	~OptionsMenu();

	AddCharacter *AddCharacterWindow;

	MenuButton* getAddCharacterButton() { return addCharacter; }
	MenuButton* getCreateNewListButton() { return createNewList; }
	MenuButton* getChangeListButton() { return changeList; }
	MenuButton* getBackButton() { return back; }
	QPushButton* getNextButton() { return media_Player->getNextButton(); }
	QPushButton* getPrevButton() { return media_Player->getPrevButton(); }
	QPushButton * getMuteButton() { return media_Player->getMuteButton(); }
	QLabel* getActiveSongLabel() { return media_Player->getActiveSongLabel(); }

	QString getActiveList() { return activeList; }

private:
	QVBoxLayout * layout;
	QWidget* options_menu;
	QVBoxLayout * layout_menu;

	int widthImage;
	int heightImage;
	CharacterManager* c_manager;
	MenuButton *addCharacter;
	MenuButton *createNewList;
	MenuButton *changeList;
	MenuButton *back;
	QLineEdit *active_List;
	QString activeList = "Ressources/CharacterFiles/characterList.gw";
	QLabel *list;
	QSpacerItem *emptySpace;
	MediaPlayer *media_Player;
};