#pragma once
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>

#define YES_NO_MODE 1
#define OK_MODE 2
#define EMPTY_MODE 3

class LowerBar : public QWidget
{
	Q_OBJECT

private:
	QLabel * image;
	QGridLayout * layout;
	QLabel *infoText;

	QPushButton * yesButton;
	QPushButton * noButton;
	QPushButton * okButton;

	public slots:
	void changeText(std::string text, int mode);

public:
	LowerBar(QWidget *parent, int windowWidth, int windowHeight, int cardHeight);
	~LowerBar();

	QPushButton* getYesButton() { return yesButton; }
	QPushButton* getNoButton() { return noButton; }
	QPushButton* getOkButton() { return okButton; }
};

