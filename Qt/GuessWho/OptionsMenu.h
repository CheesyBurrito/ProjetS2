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
#include <QFormLayout>
#include "MenuButton.h"
#include "AddCharacter.h"
#include "CharacterManager.h"

class OptionsMenu : public QWidget
{
	Q_OBJECT

public slots:
	//void setHoveredButton(MenuButton *button);
	void showDialog();
	void addCharacters();
	void activateOptionsMenu();
	void createOptionsMenu();
	void newList();

signals:
	//void hovered(MenuButton*);

public:
	OptionsMenu(QWidget* parent, CharacterManager* characterManager);
	~OptionsMenu();

	AddCharacter *AddCharacterWindow;

	MenuButton* getAddCharacterButton() { return addCharacter; }
	MenuButton* getCreateNewListButton() { return createNewList; }
	MenuButton* getChangeListButton() { return changeList; }
	MenuButton* getBackButton() { return back; }

	QString getActiveList() { return activeList; }

private:
	QFormLayout * layout;
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
	QLabel *emptySpace;
	QPushButton *next;
	QPushButton *prev;
	QLabel *activeSong;
	QLabel *music;
	QHBoxLayout *mediaPlayer;
};