#include "OptionsMenu.h"

OptionsMenu::OptionsMenu(QWidget* parent) : QWidget(parent)
{
	createOptionsMenu();
}

OptionsMenu::~OptionsMenu()
{
}

void OptionsMenu::createOptionsMenu()
{
	layout = new QVBoxLayout;
	layout->setSpacing(0);
	layout->setAlignment(Qt::AlignCenter);

	addCharacter = new MenuButton(this, " Ajouter un personnage");
	addCharacter->setToolTip("Le personnage sera ajouté à la liste active");

	createNewList = new MenuButton(this, " Créer une nouvelle liste");
	createNewList->setToolTip("La nouvelle liste deviendra la liste active");

	changeList = new MenuButton(this, " Changer de liste");
	changeList->setToolTip("La liste choisie deviendra la liste active");

	back = new MenuButton(this, " Retour");
	back->setToolTip(" Retourner au menu principal");

	active_List = new QLineEdit(this);
	active_List->setStyleSheet("background: white;");
	active_List->setFont(QFont("Walkway Bold", 20));
	active_List->setText(activeList);
	active_List->setReadOnly(true);

	emptySpace = new QLabel("", this);
	emptySpace->setFont(QFont("Walkway Bold", 20));
	emptySpace->setStyleSheet("background: transparent");

	list = new QLabel("Liste Active:", this);
	list->setFont(QFont("Walkway Bold", 20));
	list->setStyleSheet("background: transparent; color : white");

	layout->addWidget(addCharacter);
	layout->addWidget(createNewList);
	layout->addWidget(changeList);
	layout->addWidget(back);
	layout->addWidget(emptySpace);
	layout->addWidget(list);
	layout->addWidget(active_List);

	connect(addCharacter, SIGNAL(hovered(MenuButton*)), this, SLOT(setHoveredButton(MenuButton*)));
	connect(createNewList, SIGNAL(hovered(MenuButton*)), this, SLOT(setHoveredButton(MenuButton*)));
	connect(changeList, SIGNAL(hovered(MenuButton*)), this, SLOT(setHoveredButton(MenuButton*)));
	connect(back, SIGNAL(hovered(MenuButton*)), this, SLOT(setHoveredButton(MenuButton*)));
	
	setLayout(layout); 

	hide();
}

void OptionsMenu::setHoveredButton(MenuButton *button)
{
	addCharacter->setIsSelected(false);
	createNewList->setIsSelected(false);
	changeList->setIsSelected(false);
	back->setIsSelected(false);
	button->setIsSelected(true);
}

void OptionsMenu::addCharacters()
{
	AddCharacterWindow = new AddCharacter(this);
	AddCharacterWindow->show();
	connect(AddCharacterWindow->getCancelButton(), SIGNAL(clicked()), AddCharacterWindow, SLOT(close()));
	connect(AddCharacterWindow->getCancelButton(), SIGNAL(clicked()), this, SLOT(activateOptionsMenu()));
	connect(AddCharacterWindow, SIGNAL(characterIsOk()), this, SLOT(activateOptionsMenu()));
	disconnect(addCharacter, SIGNAL(hovered(MenuButton*)), this, SLOT(setHoveredButton(MenuButton*)));
	disconnect(createNewList, SIGNAL(hovered(MenuButton*)), this, SLOT(setHoveredButton(MenuButton*)));
	disconnect(changeList, SIGNAL(hovered(MenuButton*)), this, SLOT(setHoveredButton(MenuButton*)));
	disconnect(back, SIGNAL(hovered(MenuButton*)), this, SLOT(setHoveredButton(MenuButton*)));
	this->setDisabled(true);
}

void OptionsMenu::activateOptionsMenu()
{
	setDisabled(false);
	connect(addCharacter, SIGNAL(hovered(MenuButton*)), this, SLOT(setHoveredButton(MenuButton*)));
	connect(createNewList, SIGNAL(hovered(MenuButton *)), this, SLOT(setHoveredButton(MenuButton*)));
	connect(changeList, SIGNAL(hovered(MenuButton *)), this, SLOT(setHoveredButton(MenuButton*)));
	connect(back, SIGNAL(hovered(MenuButton *)), this, SLOT(setHoveredButton(MenuButton*)));
}

void OptionsMenu::showDialog()
{
	QString selfilter = tr("GuessWho Files (*.gw)");
	QString fileDialog = QFileDialog::getOpenFileName(this, "Ouvrir une liste de personnages", "./Photos", tr("GuessWho Files (*.gw)"), &selfilter);
	if (fileDialog != "")
	{
		activeList = fileDialog;
	}
	active_List->setText(activeList);
}