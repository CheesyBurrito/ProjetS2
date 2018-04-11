#pragma once
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHboxLayout>

#define YES_NO_MODE 1
#define OK_MODE 2
#define EMPTY_MODE 3

class LowerBar : public QWidget
{
	Q_OBJECT

private:
	QLabel * background;
	QGridLayout * layout;
	QHBoxLayout * hLayout;

	QLabel *infoText;
	QPushButton * yesButton;
	QPushButton * noButton;
	QPushButton * okButton;



	int barHeight;
	int barWidth;

	public slots:
	void changeText(std::string text, int mode);

public:
	LowerBar(QWidget *parent, int width, int height);
	~LowerBar();

	void setupLayouts();
	void setupWidgets();

	QPushButton* getYesButton() { return yesButton; }
	QPushButton* getNoButton() { return noButton; }
	QPushButton* getOkButton() { return okButton; }
};

