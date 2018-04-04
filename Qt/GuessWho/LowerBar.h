#pragma once
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>

class LowerBar : public QWidget
{
public:
	QLabel * image;
	QHBoxLayout * layout;
	QPushButton *boutonZoom;
	QPushButton *boutonNormal;


public:
	LowerBar(QWidget *parent, int windowWidth);
	~LowerBar();
};

