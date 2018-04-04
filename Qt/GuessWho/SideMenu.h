#pragma once
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

class SideMenu : public QWidget
{
private:
	QLabel * image;
	QHBoxLayout * layout;
public:
	SideMenu(QWidget *parent, int windowHeight);
	~SideMenu();
};

