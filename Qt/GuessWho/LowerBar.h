#pragma once
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

class LowerBar : public QWidget
{
private:
	QLabel * image;
	QHBoxLayout * layout;

public:
	LowerBar(QWidget *parent, int windowWidth);
	~LowerBar();
};

