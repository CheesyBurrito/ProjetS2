#pragma once
#include <QWidget>
#include <QKeyEvent>
#include <QGridLayout>
#include <QPushButton>

class AddCharacter : public QWidget
{
private:
	QGridLayout * layout;
	QPushButton * okButton;
	QPushButton * cancelButton;

public:
	AddCharacter(QWidget* parent);
	~AddCharacter();

	QPushButton* getOkButton() { return okButton; }
	QPushButton* getCancelButton() { return cancelButton; }
	
};