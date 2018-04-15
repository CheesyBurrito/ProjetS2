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
#include "MenuButton.h"
#include "AddCharacter.h"

class OptionsMenu : public QWidget
{
	Q_OBJECT

		public slots:
	void setHoveredButton(MenuButton *button);
	void showDialog();
	void addCharacters();
	void activateOptionsMenu();
	void createOptionsMenu();

signals:
	void hovered(MenuButton*);

public:
	OptionsMenu(QWidget* parent);
	~OptionsMenu();

	AddCharacter *AddCharacterWindow;

	MenuButton* getAddCharacterButton() { return addCharacter; }
	MenuButton* getCreateNewListButton() { return createNewList; }
	MenuButton* getChangeListButton() { return changeList; }
	MenuButton* getBackButton() { return back; }

	QString getListName() { return activeList; }

private:
	QVBoxLayout * layout;
	int widthImage;
	int heightImage;

	MenuButton *addCharacter;
	MenuButton *createNewList;
	MenuButton *changeList;
	MenuButton *back;
	QLineEdit *active_List;
	QString activeList = "./Ressources/CharacterFiles/characterList.gw";
	QLabel *list;
	QLabel *emptySpace;
};