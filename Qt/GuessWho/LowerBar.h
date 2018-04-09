#pragma once
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>

class LowerBar : public QWidget
{
private:
	QLabel * image;
	QGridLayout * layout;
	QLabel *infoText;


public:
	LowerBar(QWidget *parent, int windowWidth, int windowHeight, int cardHeight);
	~LowerBar();
};

