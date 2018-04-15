#pragma once

#include <QWidget>
#include <QKeyEvent>
#include <QGridLayout>
#include <QPushButton>

class PauseMenu : public QWidget
{
	Q_OBJECT

private:
	QGridLayout * layout;
	QPushButton * quitButton;
	QPushButton * resumeButton;
	QPushButton * cancelGameButton;

signals :
	void escapeKeyPressed();

public:
	PauseMenu(QWidget* parent);
	~PauseMenu();

	void keyPressEvent(QKeyEvent *event);
	QPushButton* getQuitButton() { return quitButton; }
	QPushButton* getResumeButton() { return resumeButton; }
	QPushButton* getCancelGameButton() { return cancelGameButton; }
};

