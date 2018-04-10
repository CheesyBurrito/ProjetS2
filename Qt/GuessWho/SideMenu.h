#pragma once
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <string>
#include <QPushButton>
#include <QIcon>
#include "QuestionMenuBar.h"

class SideMenu : public QWidget
{
	Q_OBJECT

private:
	QLabel * background;
	QLabel * cornerBackground;
	QLabel * characteristics;
	QGridLayout * layout;
	QVBoxLayout * scoreLayout;
	QHBoxLayout * hLayout;
	QLabel * infoText;

	QIcon zoomModeIcon;
	QIcon normalModeIcon;
	QPushButton * zoomButton;
	bool zoomMode = false;

	QLabel * nbHiddenCharactersLabel;
	QuestionMenuBar * questionMenuBar;

	int menuHeight, menuWidth;

public slots:
	void setTraits(std::string newTraits);
	void switchZoomIcon();

signals:
	void lowerBarTest(std::string, int);

public:
	SideMenu(QWidget *parent, int height, int width);
	~SideMenu();

	void setupLayouts();

	QPushButton* getZoomButton() { return zoomButton; }
};

