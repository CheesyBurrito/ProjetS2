#pragma once
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <vector>

class CharacterGrid : public QWidget
{
private:
	QGridLayout * characterGrid;
	std::vector<QLabel*> images;
	int gridHeight;

public:
	CharacterGrid(QWidget *parent, int height);
	~CharacterGrid();
};

