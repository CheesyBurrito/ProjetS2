
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
	Q_OBJECT

	public:
		StartWindow(QWidget* parent);
		~StartWindow();
	
	private:
		QLabel * image;
		QLabel *quitButton;
		QGridLayout *layoutPrincipal;
};
#endif 
