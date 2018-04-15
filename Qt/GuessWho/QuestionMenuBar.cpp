/****************************************
GuessWho ProjetS2 - APP7Gi

P14
William Adam-Grenier - adaw2602
Charles Quesnel - quec2502
Maxime St-Onge - stom2105

Avril 2018

QuestionMenuBar.cpp
*****************************************/

#include "QuestionMenuBar.h"

QuestionMenuBar::QuestionMenuBar(QWidget *parent) :QWidget(parent)
{
	setupWidgets();
	setupLayout();
	setupSignalsConnection();
}

QuestionMenuBar::~QuestionMenuBar()
{
}

void QuestionMenuBar::setupTreeView()
{
	//Hidding header 
	treeView->setHeaderHidden(true);
	//For Eyes
	eyesTreeItem[0] = new QTreeWidgetItemPropertiesIndex(treeView);
	eyesTreeItem[0]->setText(0, "Yeux");
	//Setup for all the possible values
	for(int i = 0; i < characterMangagerDummy.propertiesEyesIndexSize; i++)
	{
		eyesTreeItem[i + 1] = new QTreeWidgetItemPropertiesIndex(eyesTreeItem[0], 0, characterMangagerDummy.propertiesEyesIndex[i]);
		eyesTreeItem[i + 1]->setText(0, QString::fromStdString(
			characterMangagerDummy.printPhysicalTraitsColorProperties(
				characterMangagerDummy.propertiesEyesIndex[i])));
	}
	
	
	//For Hair
	hairTreeItem[0] = new QTreeWidgetItemPropertiesIndex(treeView);
	hairTreeItem[0]->setText(0, "Cheveux");

	hairTreeItem[1] = new QTreeWidgetItemPropertiesIndex(hairTreeItem[0], -1, -1);
	hairTreeItem[1]->setText(0, "Couleur");
	//Setup ossible values for hair color
	for (int i = 0; i < characterMangagerDummy.propertiesHairColorIndexSize; i++)
	{
		hairTreeItem[i + 2] = new QTreeWidgetItemPropertiesIndex(hairTreeItem[1], 1, characterMangagerDummy.propertiesHairColorIndex[i]);
		hairTreeItem[i + 2]->setText(0, QString::fromStdString(
			characterMangagerDummy.printPhysicalTraitsColorProperties(
				characterMangagerDummy.propertiesHairColorIndex[i])));
	}

	hairTreeItem[2] = new QTreeWidgetItemPropertiesIndex(hairTreeItem[0], -1, -1);
	hairTreeItem[2]->setText(0, "Physique");
	//Setup for all the possible values
	for (int i = 0; i < characterMangagerDummy.propertiesHairPhysiqueIndexSize; i++)
	{
		hairTreeItem[i + 1 + characterMangagerDummy.propertiesHairColorIndexSize] = new QTreeWidgetItemPropertiesIndex(hairTreeItem[2], 2, characterMangagerDummy.propertiesHairPhysiqueIndex[i]);
		hairTreeItem[i + 1 + characterMangagerDummy.propertiesHairColorIndexSize]->setText(0, QString::fromStdString(
			characterMangagerDummy.printPhysicalTraitsProperties(
				characterMangagerDummy.propertiesHairPhysiqueIndex[i])));
	}

	
	//For Skin
	skinTreeItem[0] = new QTreeWidgetItemPropertiesIndex(treeView);
	skinTreeItem[0]->setText(0, "Peau");
	//Setup for all the possible values
	for (int i = 0; i < characterMangagerDummy.propertiesSkinColorIndexSize; i++)
	{
		skinTreeItem[i + 1] = new QTreeWidgetItemPropertiesIndex(skinTreeItem[0], 3, characterMangagerDummy.propertiesSkinColorIndex[i]);
		skinTreeItem[i + 1]->setText(0, QString::fromStdString(
			characterMangagerDummy.printPhysicalTraitsColorProperties(
				characterMangagerDummy.propertiesSkinColorIndex[i])));
	}

	//For Accessories
	accessoriesTreeItem[0] = new QTreeWidgetItemPropertiesIndex(treeView);
	accessoriesTreeItem[0]->setText(0, "Accessoires");
	//Setup for all the possible values
	for (int i = 0; i < characterMangagerDummy.propertiesAccessoriesIndexSize; i++)
	{
		accessoriesTreeItem[i + 1] = new QTreeWidgetItemPropertiesIndex(accessoriesTreeItem[0], 4, characterMangagerDummy.propertiesAccessoriesIndex[i]);
		accessoriesTreeItem[i + 1]->setText(0, QString::fromStdString(
			characterMangagerDummy.printPhysicalTraitsProperties(
				characterMangagerDummy.propertiesAccessoriesIndex[i])));
	}

	//Facial Hair id == 5
	facialHairTreeItem[0] = new QTreeWidgetItemPropertiesIndex(treeView);
	facialHairTreeItem[0]->setText(0, "Poils Faciaux");
	//Setup for all the possible values
	for (int i = 0; i < characterMangagerDummy.propertiesFacialHairIndexSize; i++)
	{
		facialHairTreeItem[i + 1] = new QTreeWidgetItemPropertiesIndex(facialHairTreeItem[0], 5, characterMangagerDummy.propertiesFacialHairIndex[i]);
		facialHairTreeItem[i + 1]->setText(0, QString::fromStdString(
			characterMangagerDummy.printPhysicalTraitsProperties(
				characterMangagerDummy.propertiesFacialHairIndex[i])));
	}

	//For Age
	ageTreeItem[0] = new QTreeWidgetItemPropertiesIndex(treeView);
	ageTreeItem[0]->setText(0, "Age");
	//Setup for all the possible values
	for (int i = 0; i < characterMangagerDummy.propertiesAgeIndexSize; i++)
	{
		ageTreeItem[i + 1] = new QTreeWidgetItemPropertiesIndex(ageTreeItem[0], 6, characterMangagerDummy.propertiesAgeIndex[i]);
		ageTreeItem[i + 1]->setText(0, QString::fromStdString(
			characterMangagerDummy.printPhysicalTraitsProperties(
				characterMangagerDummy.propertiesAgeIndex[i])));
	}

	//For Gender
	genderTreeItem[0] = new QTreeWidgetItemPropertiesIndex(treeView);
	genderTreeItem[0]->setText(0, "Genre");
	//Setup for all the possible values
	for (int i = 0; i < characterMangagerDummy.propertiesGenderSize; i++)
	{
		genderTreeItem[i + 1] = new QTreeWidgetItemPropertiesIndex(genderTreeItem[0], 7, characterMangagerDummy.propertiesGender[i]);
		genderTreeItem[i + 1]->setText(0, QString::fromStdString(
			characterMangagerDummy.printPhysicalTraitsProperties(
				characterMangagerDummy.propertiesGender[i])));
	}

	treeView->setStyleSheet("color:white");
	treeView->setFont(QFont("Walkway Bold", 12));
	eyesTreeItem[0]->setSelected(true);
	treeView->setFocusPolicy(Qt::NoFocus);
	//cout << "ITEM: " << treeView->findItems("Yeux", Qt::MatchExactly, 0).size() << endl;
}

void QuestionMenuBar::setupLayout()
{
	vboxLayout->addWidget(treeView);
	this->setLayout(vboxLayout);
}

void QuestionMenuBar::setupWidgets()
{
	setupTreeView();
}

void QuestionMenuBar::setupSignalsConnection()
{
	/*
	for(int i = 0; i < parentWidgetsTree.size(); i ++)
	{
		connect(parentWidgetsTree.at(i), SIGNAL(itemPressed(QTreeWidgetItem*, int)), this, SLOT(parentCategoriesEventHandler(QTreeWidgetItem*)));
	}
	*/

	connect(treeView, SIGNAL(itemPressed(QTreeWidgetItem*, int)), this, SLOT(treeWidgetItemClicked()));
	//connect(treeView, SIGNAL(itemActivated(QTreeWidgetItem*, int)), this, SLOT(treeWidgetItemClicked(QTreeWidgetItem*)));
}

void QuestionMenuBar::treeWidgetItemClicked()
{
	//emit signal with vector as parameter
	if (treeView->selectedItems().size() <= 0)
	{
		return;
	}

	QTreeWidgetItem* item = treeView->selectedItems().at(treeView->selectedItems().size() - 1);
	QObject *qobject1 = dynamic_cast<QObject*>(item);

	QTreeWidgetItemPropertiesIndex *tempConversion = qobject_cast<QTreeWidgetItemPropertiesIndex*>(qobject1);

	if (item->childCount() == 0)
	{
		vector<int> tempVector = { tempConversion->getPropertyCategoryIndex(), tempConversion->getPropertyIndex() };
		//cout << "QESTION" << endl;
		emit sendQuestion(tempVector);
		characterMangagerDummy.propertyPrinterSpecificCharacteristics(tempConversion->getPropertyCategoryIndex(), tempConversion->getPropertyIndex());
	}
	else
	{
		
	}
}

void QuestionMenuBar::goUpTreeWidgetItem()
{

	//If selection for question is made
	if (treeView->selectedItems().size() <= 0)
	{
		return;
	}

	QTreeWidgetItem* item = treeView->selectedItems().at(treeView->selectedItems().size() - 1);
	QTreeWidgetItem* checkNextUpTree = treeView->itemAbove(item);

	if(checkNextUpTree == nullptr)
	{
		checkNextUpTree = genderTreeItem[0];
	}
	
	QList<QTreeWidgetItem*> selectedList = treeView->selectedItems();
	for(int i = 0; i < selectedList.size(); i++)
	{
		selectedList.at(i)->setSelected(false);
	}
	//If the next item is a parent selection item
	if(item->childCount() == 0 && checkNextUpTree->childCount() >= 1)
	{
		treeView->collapseItem(checkNextUpTree);
	}
	if (item->childCount() > 0 && checkNextUpTree->childCount() >= 1)
	{
		treeView->collapseItem(item);
	}
	else if (checkNextUpTree == hairTreeItem[0])
	{
		treeView->collapseItem(checkNextUpTree);
		treeView->collapseItem(skinTreeItem[0]);
	}
	checkNextUpTree->setSelected(true);
}

void QuestionMenuBar::goDownTreeWidgetItem()
{

	//If selection for question is made
	if (treeView->selectedItems().size() <= 0)
	{
		return;
	}

	QTreeWidgetItem* item = treeView->selectedItems().at(treeView->selectedItems().size() - 1);
	QTreeWidgetItem* checkNextDownTree = treeView->itemBelow(item);

	if (checkNextDownTree == nullptr)
	{
		checkNextDownTree = eyesTreeItem[0];
	}

	QList<QTreeWidgetItem*> selectedList = treeView->selectedItems();
	for (int i = 0; i < selectedList.size(); i++)
	{
		selectedList.at(i)->setSelected(false);
	}
	//If the next item is a parent selection item
	if (item->childCount() == 0 && checkNextDownTree->childCount() >= 1)
	{
		treeView->collapseItem(item->parent());
	}
	if(checkNextDownTree == skinTreeItem[0])
	{
		treeView->collapseItem(hairTreeItem[0]);
	}
	checkNextDownTree->setSelected(true);
}

void QuestionMenuBar::enterSubTree()
{
	//If selection for question is made
	if (treeView->selectedItems().size() <= 0)
	{
		return;
	}

	QTreeWidgetItem* item = treeView->selectedItems().at(treeView->selectedItems().size() - 1);
	if(item->childCount() == 0)
	{
		return;
	}

	if (item->isExpanded())
	{
		item->setExpanded(false);
	}
	else
	{
		item->setExpanded(true);
	}
}