
#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>
#include <QFont>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QPixmap>

class StartWindow : public QWidget
{
	public:
		StartWindow(QWidget* parent);
		~StartWindow();
		QPushButton* getButton();
	private:
		QLabel * image;
		QPushButton *quitButton;
		QGridLayout *layoutPrincipal;
};
#endif 
