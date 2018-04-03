#pragma once
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <vector>

class GameWindow : public QWidget
{
private:
	QGridLayout *layout;
	std::vector<QLabel*> images;

public:
	GameWindow(QWidget *parent);
	~GameWindow();
};

