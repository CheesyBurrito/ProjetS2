#pragma once
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>

class LowerBar : public QWidget
{
private:
	QLabel * image;
	QHBoxLayout * layout;
	QPushButton *boutonZoom;
	QPushButton *boutonNormal;


public:
	LowerBar(QWidget *parent, int windowWidth);
	~LowerBar();

	QPushButton* getboutonZoom(){ return boutonZoom; }
	QPushButton* getBoutonNormal(){ return boutonNormal; }
};

