#pragma once
#include <QWidget>
#include <QtCore>
#include <QtGui>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTreeWidgetItem>
#include "CharacterManager.h"
#include <array>

class QuestionMenuBar : public QWidget
{
	Q_OBJECT
private:
	QVBoxLayout * vboxLayout = new QVBoxLayout;
	QTreeWidget * treeView = new QTreeWidget;
	QTreeWidgetItem* hairTreeItem[12];
	QTreeWidgetItem* eyesTreeItem[5];
	QTreeWidgetItem* skinTreeItem[1];
	QTreeWidgetItem* accessoriesTreeItem[1];
	QTreeWidgetItem* ageTreeItem[1];
	QTreeWidgetItem* genderTreeItem[1];

	//DOES NOT CONTAIN ANY CHARACTERS, IT IS ONLY THERE TO BE USED FOR ITS METHODS
	CharacterManager characterMangagerDummy;
	
	public slots:
	void treeWidgetItemClicked(QTreeWidgetItem* item);

public:
	//Constructors and deconstructor
	QuestionMenuBar(QWidget *parent);
	~QuestionMenuBar();

	//General Methods
	void setupWidgets();
	void setupTreeView();
	void setupLayout();
	//Setters and Getters
};

