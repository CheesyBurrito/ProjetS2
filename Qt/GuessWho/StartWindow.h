
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

	signals:
		void keyPressed();
	public:
		StartWindow(QWidget* parent);
		~StartWindow();
		void keyPressEvent(QKeyEvent *event);
	
	private:
		QLabel * image;
		QPushButton *quitButton;
		QGridLayout *layoutPrincipal;
};
#endif 
