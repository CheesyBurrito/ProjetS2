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

class AddCharacter : public QWidget
{
	Q_OBJECT

public slots:
	void showDialog();
	void verifyAddCharacter();

private:
	QVBoxLayout * layout;
	QHBoxLayout *buttons;
	QLabel *title;
	
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
	QHBoxLayout *hairColor;
	QRadioButton *brownHair;
	QRadioButton *redhead;
	QRadioButton *blond;
	QRadioButton *blackHair;
	QRadioButton *whiteHair;
	QRadioButton *others;

	QHBoxLayout *hairTraits;
	QRadioButton *bald;
	QRadioButton *shortHair;
	QRadioButton *longHair;

	QVBoxLayout *accessoriesLayout;
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


public:
	AddCharacter(QWidget* parent);
	~AddCharacter();
	void createAddCharacter();

	QPushButton* getOkButton() { return okButton; }
	QPushButton* getCancelButton() { return cancelButton; }
	
};