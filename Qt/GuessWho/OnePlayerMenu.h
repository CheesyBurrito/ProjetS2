#pragma once
#include <QWidget>
#include <QFont>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QLCDNumber>
#include <QSlider>

class OnePlayerMenu : public QWidget
{
	Q_OBJECT

public slots:
	void createOnePlayerMenu();

public:
	OnePlayerMenu(QWidget* parent);
	~OnePlayerMenu();

	QString getPlayer1Name() { return player1->text(); }
	int getNumberGames() { return m_lcd->value(); }
	QPushButton* getOkButton() { return ok; }

private:
	QGridLayout * layout;
	int widthImage;
	int heightImage;

	QLabel *numGames;
	QLabel *name1;
	QLineEdit *player1;
	QPushButton *ok;
	QLCDNumber *m_lcd;
	QSlider *m_slider;

};