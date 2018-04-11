#include "QuestionMenuBar.h"

QuestionMenuBar::QuestionMenuBar(QWidget *parent) :QWidget(parent)
{
	setupWidgets();
	setupLayout();
	
}

QuestionMenuBar::~QuestionMenuBar()
{
}

void QuestionMenuBar::setupTreeView()
{
	//For Eyes
	eyesTreeItem[0] = new QTreeWidgetItem(treeView);
	eyesTreeItem[0]->setText(0, "Yeux");
	//Setup for all the possible values

	
	//For Hair
	hairTreeItem[0] = new QTreeWidgetItem(treeView);
	hairTreeItem[0]->setText(0, "Cheveux");

	hairTreeItem[1] = new QTreeWidgetItem(hairTreeItem[0]);
	hairTreeItem[1]->setText(0, "Couleur");

	hairTreeItem[2] = new QTreeWidgetItem(hairTreeItem[0]);
	hairTreeItem[2]->setText(0, "Physique");
	//Setup for all the possible values

	/*
	hairTreeItem[3] = new QTreeWidgetItem(hairTreeItem[1]);
	hairTreeItem[3]->setText(0, "Green");

	hairTreeItem[4] = new QTreeWidgetItem(hairTreeItem[2]);
	hairTreeItem[4]->setText(0, "Bald");
	*/


	//For Skin
	skinTreeItem[0] = new QTreeWidgetItem(treeView);
	skinTreeItem[0]->setText(0, "Peau");
	//Setup for all the possible values


	//For Accessories
	accessoriesTreeItem[0] = new QTreeWidgetItem(treeView);
	accessoriesTreeItem[0]->setText(0, "Accessoires");
	//Setup for all the possible values

	//For Age
	ageTreeItem[0] = new QTreeWidgetItem(treeView);
	ageTreeItem[0]->setText(0, "Age");
	//Setup for all the possible values

	//For Gender
	genderTreeItem[0] = new QTreeWidgetItem(treeView);
	genderTreeItem[0]->setText(0, "Genre");
	//Setup for all the possible values

	

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
	connect(treeView, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(treeWidgetItemClicked(QTreeWidgetItem*)));
}

void QuestionMenuBar::treeWidgetItemClicked(QTreeWidgetItem* item)
{
	item->setText(0, "Click Worked!");
}



