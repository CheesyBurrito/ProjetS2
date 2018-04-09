#pragma once
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <string>
#include "QuestionMenuBar.h"

class SideMenu : public QWidget
{
	Q_OBJECT

private:
	QLabel * image;
	QLabel * image2;
	QLabel * characteristics;
	QGridLayout * layout;
	QuestionMenuBar * questionMenuBar;

public slots:
	void setTraits(std::string newTraits);

public:
	SideMenu(QWidget *parent, int windowHeight, int windowWidth);
	~SideMenu();
};

