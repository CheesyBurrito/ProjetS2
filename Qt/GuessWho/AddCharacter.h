#pragma once
#include <QWidget>
#include <QKeyEvent>
#include <QGridLayout>
#include <QPushButton>
#include <QGroupBox>

class AddCharacter : public QWidget
{
private:
	QVBoxLayout * layout;
	QGroupBox *eyes;
	QGroupBox *hair;
	QGroupBox *accessories;
	QGroupBox *sexe;
	QGroupBox *facialHair;
	QGroupBox *age;
	QGroupBox *skinColor;
	QPushButton * okButton;
	QPushButton * cancelButton;

public:
	AddCharacter(QWidget* parent);
	~AddCharacter();
	void createAddCharacter();

	QPushButton* getOkButton() { return okButton; }
	QPushButton* getCancelButton() { return cancelButton; }
	
};