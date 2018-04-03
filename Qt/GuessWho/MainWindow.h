#include <QMainWindow>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QWidget>

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "MenuWindow.h"
#include "StartWindow.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

	public:
		MainWindow();
		~MainWindow();
	public slots:
		void openMenu();
		void onePlayerWindow();
		void twoPlayersWindow();
	private:
		StartWindow *start;
		MenuWindow *menu;
};
	
#endif 