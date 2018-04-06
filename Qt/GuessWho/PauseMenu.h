#pragma once

#include <QWidget>
#include <QKeyEvent>

class PauseMenu : public QWidget
{
	Q_OBJECT

signals :
	void escapeKeyPressed();

public:
	PauseMenu(QWidget* parent);
	~PauseMenu();

	void keyPressEvent(QKeyEvent *event);
};

