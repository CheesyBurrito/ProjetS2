/****************************************
GuessWho ProjetS2 - APP7Gi

P14
William Adam-Grenier - adaw2602
Charles Quesnel - quec2502
Maxime St-Onge - stom2105

Avril 2018

MenuButton.h
*****************************************/

#pragma once
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPainter>
#include <QSound>
#include "CharacterTraits.h"

class MenuButton : public QPushButton
{
	Q_OBJECT

	public slots:
		void playClickedSound();
		void is_Selected();
		void not_Selected();
	private:
		bool isSelected;
		QSound *clickedSound;

	signals:
		void hovered();
		void leaveHovered();

	protected:
		virtual void enterEvent(QEvent* e);
		virtual void leaveEvent(QEvent* e);

	public:
		MenuButton(QWidget *parent, QString text, bool selected = false);
		~MenuButton();

};