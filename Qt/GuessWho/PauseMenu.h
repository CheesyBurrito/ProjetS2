#pragma once

#include <QWidget>
#include <QKeyEvent>
#include <QGridLayout>
#include <QPushButton>
#include "MenuButton.h"

class PauseMenu : public QWidget
{
	Q_OBJECT

public slots:
	void setHoveredButton(MenuButton *button);
	
private:
	QGridLayout * layout;
	MenuButton * quitButton;
	MenuButton * resumeButton;
	MenuButton * cancelGameButton;
	QLabel *pauseBackground;

signals :
	void escapeKeyPressed();
	void hovered(MenuButton*);

public:
	PauseMenu(QWidget* parent);
	~PauseMenu();

	void keyPressEvent(QKeyEvent *event);
	MenuButton * getQuitButton() { return quitButton; }
	MenuButton * getResumeButton() { return resumeButton; }
	MenuButton * getCancelGameButton() { return cancelGameButton; }
};

