#pragma once
#include <QWidget>
#include <QtCore>
#include <QtGui>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTreeWidgetItem>

class QuestionMenuBar : public QWidget
{
	Q_OBJECT
private:
	QVBoxLayout * vboxLayout = new QVBoxLayout;
	QTreeWidget * treeView = new QTreeWidget;
	QTreeWidgetItem* hairTreeItem[3];
	QTreeWidgetItem* eyesTreeItem[1];
	QTreeWidgetItem* skinTreeItem[1];
	QTreeWidgetItem* accessoriesTreeItem[1];
	QTreeWidgetItem* ageTreeItem[1];
	QTreeWidgetItem* genderTreeItem[1];
	
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

