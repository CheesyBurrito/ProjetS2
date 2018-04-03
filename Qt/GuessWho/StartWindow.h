#include <QWidget>
#include <QFont>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QPixmap>

#ifndef STARTWINDOW_H
#define STARTWINDOW_H



class StartWindow : public QWidget
{
	public:
		StartWindow();
		~StartWindow();
		QPushButton* getButton();
	private:
		QPushButton *quitButton;
		QVBoxLayout *layoutPrincipal;
};
#endif 
