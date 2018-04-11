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
	QTreeWidgetItem* skinTreeItem[4];
	QTreeWidgetItem* accessoriesTreeItem[6];
	QTreeWidgetItem* ageTreeItem[3];
	QTreeWidgetItem* genderTreeItem[3];

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
	void setupSignalsConnection();
	//Setters and Getters
};

