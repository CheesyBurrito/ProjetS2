/****************************************
GuessWho ProjetS2 - APP7Gi

P14
William Adam-Grenier - adaw2602
Charles Quesnel - quec2502
Maxime St-Onge - stom2105

Avril 2018

QuestionMenuBar.h
*****************************************/

#pragma once
#include <QWidget>
#include <QtCore>
#include <QtGui>
#include <QVBoxLayout>
#include <QPushButton>
#include "CharacterManager.h"
#include "QTreeWidgetItemPropertiesIndex.h"
using namespace std;

class QuestionMenuBar : public QWidget
{
	Q_OBJECT
private:
	QVBoxLayout* vboxLayout = new QVBoxLayout;
	QTreeWidget* treeView = new QTreeWidget;
	QTreeWidgetItemPropertiesIndex* facialHairTreeItem[5];
	QTreeWidgetItemPropertiesIndex* hairTreeItem[12];
	QTreeWidgetItemPropertiesIndex* eyesTreeItem[5];
	QTreeWidgetItemPropertiesIndex* skinTreeItem[4];
	QTreeWidgetItemPropertiesIndex* accessoriesTreeItem[6];
	QTreeWidgetItemPropertiesIndex* ageTreeItem[3];
	QTreeWidgetItemPropertiesIndex* genderTreeItem[3];

	//DOES NOT CONTAIN ANY CHARACTERS, IT IS ONLY THERE TO BE USED FOR ITS METHODS
	CharacterManager characterMangagerDummy;
	
	public slots:
	void treeWidgetItemClicked();
	void goUpTreeWidgetItem();
	void goDownTreeWidgetItem();
	void enterSubTree();

	signals:
	void sendQuestion(std::vector<int>);
	

public:
	//Constructors and deconstructor
	QuestionMenuBar(QWidget *parent);
	~QuestionMenuBar();

	//General Methods
	void setupWidgets();
	void setupTreeView();
	void setupLayout();
	void setupSignalsConnection();
	//Setters and Getters
};

