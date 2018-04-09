#pragma once
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPainter>
#include "CharacterTraits.h"

class MenuButton : public QPushButton
{
	Q_OBJECT

	private:
		bool isSelected;

	signals:
		void hovered(MenuButton*);

	protected:
		virtual void enterEvent(QEvent* e);

	public:
		MenuButton(QWidget *parent, QString text, bool selected = false);
		~MenuButton();
		void setIsSelected(bool selected);
};