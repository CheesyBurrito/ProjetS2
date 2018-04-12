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

