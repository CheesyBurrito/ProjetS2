#pragma once
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>
#include <string>
#include <QPushButton>
#include <QIcon>

class SideMenu : public QWidget
{
	Q_OBJECT

private:
	QLabel * image;
	QLabel * image2;
	QLabel * characteristics;
	QGridLayout * layout;
	QVBoxLayout * scoreLayout;

	QIcon zoomModeIcon;
	QIcon normalModeIcon;
	QPushButton * zoomButton;
	bool zoomMode = false;

	QLabel * nbHiddenCharactersLabel;

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

