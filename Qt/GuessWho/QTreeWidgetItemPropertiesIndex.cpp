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
