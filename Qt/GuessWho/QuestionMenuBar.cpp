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
	eyesTreeItem[0] = new QTreeWidgetItem(treeView);
	eyesTreeItem[0]->setText(0, "Yeux");
	//Setup for all the possible values
	for(int i = 0; i < characterMangagerDummy.propertiesEyesIndexSize; i++)
	{
		eyesTreeItem[i + 1] = new QTreeWidgetItem(eyesTreeItem[0]);
		eyesTreeItem[i + 1]->setText(0, QString::fromStdString(
			characterMangagerDummy.printPhysicalTraitsColorProperties(
				characterMangagerDummy.propertiesEyesIndex[i])));
	}
	
	
	//For Hair
	hairTreeItem[0] = new QTreeWidgetItem(treeView);
	hairTreeItem[0]->setText(0, "Cheveux");

	hairTreeItem[1] = new QTreeWidgetItem(hairTreeItem[0]);
	hairTreeItem[1]->setText(0, "Couleur");
	//Setup ossible values for hair color
	for (int i = 0; i < characterMangagerDummy.propertiesHairColorIndexSize; i++)
	{
		hairTreeItem[i + 2] = new QTreeWidgetItem(hairTreeItem[1]);
		hairTreeItem[i + 2]->setText(0, QString::fromStdString(
			characterMangagerDummy.printPhysicalTraitsColorProperties(
				characterMangagerDummy.propertiesHairColorIndex[i])));
	}

	hairTreeItem[2] = new QTreeWidgetItem(hairTreeItem[0]);
	hairTreeItem[2]->setText(0, "Physique");
	//Setup for all the possible values
	for (int i = 0; i < characterMangagerDummy.propertiesHairPhysiqueIndexSize; i++)
	{
		hairTreeItem[i + 1 + characterMangagerDummy.propertiesHairColorIndexSize] = new QTreeWidgetItem(hairTreeItem[2]);
		hairTreeItem[i + 1 + characterMangagerDummy.propertiesHairColorIndexSize]->setText(0, QString::fromStdString(
			characterMangagerDummy.printPhysicalTraitsProperties(
				characterMangagerDummy.propertiesHairPhysiqueIndex[i])));
	}


	//For Skin
	skinTreeItem[0] = new QTreeWidgetItem(treeView);
	skinTreeItem[0]->setText(0, "Peau");
	//Setup for all the possible values
	for (int i = 0; i < characterMangagerDummy.propertiesSkinColorIndexSize; i++)
	{
		skinTreeItem[i + 1] = new QTreeWidgetItem(skinTreeItem[0]);
		skinTreeItem[i + 1]->setText(0, QString::fromStdString(
			characterMangagerDummy.printPhysicalTraitsColorProperties(
				characterMangagerDummy.propertiesSkinColorIndex[i])));
	}

	//For Accessories
	accessoriesTreeItem[0] = new QTreeWidgetItem(treeView);
	accessoriesTreeItem[0]->setText(0, "Accessoires");
	//Setup for all the possible values
	for (int i = 0; i < characterMangagerDummy.propertiesAccessoriesIndexSize; i++)
	{
		accessoriesTreeItem[i + 1] = new QTreeWidgetItem(accessoriesTreeItem[0]);
		accessoriesTreeItem[i + 1]->setText(0, QString::fromStdString(
			characterMangagerDummy.printPhysicalTraitsProperties(
				characterMangagerDummy.propertiesAccessoriesIndex[i])));
	}

	//For Age
	ageTreeItem[0] = new QTreeWidgetItem(treeView);
	ageTreeItem[0]->setText(0, "Age");
	//Setup for all the possible values
	for (int i = 0; i < characterMangagerDummy.propertiesAgeIndexSize; i++)
	{
		ageTreeItem[i + 1] = new QTreeWidgetItem(ageTreeItem[0]);
		ageTreeItem[i + 1]->setText(0, QString::fromStdString(
			characterMangagerDummy.printPhysicalTraitsProperties(
				characterMangagerDummy.propertiesAgeIndex[i])));
	}

	//For Gender
	genderTreeItem[0] = new QTreeWidgetItem(treeView);
	genderTreeItem[0]->setText(0, "Genre");
	//Setup for all the possible values
	for (int i = 0; i < characterMangagerDummy.propertiesGenderSize; i++)
	{
		genderTreeItem[i + 1] = new QTreeWidgetItem(genderTreeItem[0]);
		genderTreeItem[i + 1]->setText(0, QString::fromStdString(
			characterMangagerDummy.printPhysicalTraitsProperties(
				characterMangagerDummy.propertiesGender[i])));
	}

	

	treeView->setStyleSheet("color:white");
	
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
	connect(treeView, SIGNAL(itemPressed(QTreeWidgetItem*, int)), this, SLOT(treeWidgetItemClicked(QTreeWidgetItem*)));
	connect(treeView, SIGNAL(itemActivated(QTreeWidgetItem*, int)), this, SLOT(treeWidgetItemClicked(QTreeWidgetItem*)));
}

void QuestionMenuBar::treeWidgetItemClicked(QTreeWidgetItem* item)
{
	//cout << item->childCount() << endl;
	//If selection for question is made
	if(item->childCount() == 0)
	{
		
	}
	else
	{
		if (item->isExpanded())
		{
			item->setExpanded(false);
		}
		else
		{
			item->setExpanded(true);
		}
	}
	
	
}
