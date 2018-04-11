#pragma once
#include <QWidget>
#include <QKeyEvent>
#include <QGridLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QRadioButton>
#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>
#include <QFileDialog>
#include <QMessageBox>
#include <QStyle>
#include "Character.h"
#include "CharacterManager.h"
#include "QDir"
#include "QFile"

class AddCharacter : public QWidget
{
	Q_OBJECT
		
signals:
	void characterIsOk();

public slots:
	void showDialog();
	void verifyAddCharacter();

private:
	int ID;
	int eyes;
	int hairColor;
	int hairCharacteristics;
	int gender;
	int skinColor;
	std::vector<int> accessories;
	int facialHair;
	int age;
	QString name;

	QVBoxLayout * layout;
	QHBoxLayout *buttons;
	
	QHBoxLayout *nameBox;
	QLabel *nameLabel;
	QLineEdit *nameLineEdit;

	QHBoxLayout *eyesLayout;
	QGroupBox *eyesBox;
	QRadioButton *brownEyes;
	QRadioButton *greenEyes;
	QRadioButton *blueEyes;
	QRadioButton *redEyes;

	QGroupBox *hairColorBox;
	QGroupBox *hairTraitsBox;
	QHBoxLayout *hairColorLayout;
	QRadioButton *brownHair;
	QRadioButton *redhead;
	QRadioButton *blond;
	QRadioButton *blackHair;
	QRadioButton *whiteHair;
	QRadioButton *others;

	QHBoxLayout *hairTraitsLayout;
	QRadioButton *bald;
	QRadioButton *shortHair;
	QRadioButton *longHair;

	QHBoxLayout *accessoriesLayout;
	QGroupBox *accessoriesBox;
	QCheckBox *glasses;
	QCheckBox *hat;
	QCheckBox *piercing;
	QCheckBox *tattoo;
	QLabel *max3;

	QHBoxLayout *sexeLayout;
	QGroupBox *sexeBox;
	QRadioButton *man;
	QRadioButton *woman;

	QHBoxLayout *facialHairLayout;
	QGroupBox *facialHairBox;
	QRadioButton *shave;
	QRadioButton *beard;
	QRadioButton *mustache;
	QRadioButton *bouc;

	QHBoxLayout *ageLayout;
	QGroupBox *ageBox;
	QRadioButton *student;
	QRadioButton *teacher;
	
	QHBoxLayout *skinColorLayout;
	QGroupBox *skinColorBox;
	QRadioButton *blackSkin;
	QRadioButton *whiteSkin;
	QRadioButton *tanned;

	QHBoxLayout *pictureLayout;
	QGroupBox *pictureBox;
	QLineEdit *fileName;
	QPushButton *browse;
	QString picturePath;

	QPushButton *okButton;
	QPushButton *cancelButton;

	Character* character;
	CharacterManager* c_manager;
	QString listSavePath;

public:
	AddCharacter(QWidget* parent, CharacterManager* characterManager, QString activeList);
	~AddCharacter();
	void createAddCharacter();
	
	QPushButton* getOkButton() { return okButton; }
	QPushButton* getCancelButton() { return cancelButton; }
	
};