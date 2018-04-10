#pragma once
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>
#include <string>
<<<<<<< HEAD
#include <QPushButton>
#include <QIcon>
=======
#include "QuestionMenuBar.h"
>>>>>>> Search-Tree

class SideMenu : public QWidget
{
	Q_OBJECT

private:
	QLabel * image;
	QLabel * image2;
	QLabel * characteristics;
	QGridLayout * layout;
<<<<<<< HEAD
	QVBoxLayout * scoreLayout;

	QIcon zoomModeIcon;
	QIcon normalModeIcon;
	QPushButton * zoomButton;
	bool zoomMode = false;

	QLabel * nbHiddenCharactersLabel;
=======
	QuestionMenuBar * questionMenuBar;
>>>>>>> Search-Tree

public slots:
	void setTraits(std::string newTraits);
	void switchZoomIcon();

signals:
	void lowerBarTest(std::string, int);

public:
	SideMenu(QWidget *parent, int windowHeight, int windowWidth);
	~SideMenu();

	QPushButton* getZoomButton() { return zoomButton; }
};

