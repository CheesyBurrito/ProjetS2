/****************************************
GuessWho ProjetS2 - APP7Gi

P14
William Adam-Grenier - adaw2602
Charles Quesnel - quec2502
Maxime St-Onge - stom2105

Avril 2018

QTreeWidgetItemPropertiesIndex.h
*****************************************/

#pragma once
#include <QTreeWidgetItem>
#include <QObject>


class QTreeWidgetItemPropertiesIndex :public QObject, public QTreeWidgetItem
{
	Q_OBJECT
private:
	int propertyCategoryIndex = -1;
	int propertyIndex = -1;
public:
	QTreeWidgetItemPropertiesIndex(QTreeWidget *view);
	QTreeWidgetItemPropertiesIndex(QTreeWidgetItemPropertiesIndex *other, int propertyCategoryIndex1, int propertyIndex1);
	~QTreeWidgetItemPropertiesIndex();

	int getPropertyCategoryIndex() { return propertyCategoryIndex; }
	int getPropertyIndex() { return propertyIndex; }
};

