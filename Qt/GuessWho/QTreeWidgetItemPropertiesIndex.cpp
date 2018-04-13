/****************************************
GuessWho ProjetS2 - APP7Gi

P14
William Adam-Grenier - adaw2602
Charles Quesnel - quec2502
Maxime St-Onge - stom2105

Avril 2018

QTreeWidgetItemPropertiesIndex.cpp
*****************************************/

#include "QTreeWidgetItemPropertiesIndex.h"

QTreeWidgetItemPropertiesIndex::QTreeWidgetItemPropertiesIndex(QTreeWidget *view) : QTreeWidgetItem(view)
{
	
}

QTreeWidgetItemPropertiesIndex::QTreeWidgetItemPropertiesIndex(QTreeWidgetItemPropertiesIndex *other, int propertyCategoryIndex1, int propertyIndex1):QTreeWidgetItem(other)
{
	propertyCategoryIndex = propertyCategoryIndex1;
	propertyIndex = propertyIndex1;
}

QTreeWidgetItemPropertiesIndex::~QTreeWidgetItemPropertiesIndex()
{
}
