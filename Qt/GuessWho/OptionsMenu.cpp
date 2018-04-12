#include "OptionsMenu.h"

OptionsMenu::OptionsMenu(QWidget* parent, CharacterManager* characterManager) : QWidget(parent)
{
	c_manager = characterManager;
	createOptionsMenu();
}

OptionsMenu::~OptionsMenu()
{
}

void OptionsMenu::createOptionsMenu()
{

	media_Player = new MediaPlayer(this);
	layout = new QVBoxLayout(this);
	layout->setSpacing(0);
	layout->setAlignment(Qt::AlignCenter);
	setLayout(layout);

	options_menu = new QWidget(this);

	layout_menu = new QVBoxLayout(this);
	layout_menu->setSpacing(0);
	layout_menu->setAlignment(Qt::AlignBottom);
	layout_menu->setContentsMargins(0, 0, 0, 0);

	options_menu->setLayout(layout_menu);

	layout->addWidget(options_menu);
	layout->addWidget(media_Player);

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
	active_List->setFixedWidth(520);
	active_List->setReadOnly(true);

	emptySpace = new QSpacerItem(520,30);

	list = new QLabel("Liste Active:", this);
	list->setFont(QFont("Walkway Bold", 20));
	list->setStyleSheet("background: transparent; color : white");
	
	layout_menu->addWidget(addCharacter);
	layout_menu->addWidget(createNewList);
	layout_menu->addWidget(changeList);
	layout_menu->addWidget(back);
	layout_menu->addItem(emptySpace);
	layout_menu->addWidget(list);
	layout_menu->addWidget(active_List);

	hide();
}

void OptionsMenu::addCharacters()
{
	AddCharacterWindow = new AddCharacter(this, c_manager, activeList);
	AddCharacterWindow->show();
	connect(AddCharacterWindow->getCancelButton(), SIGNAL(clicked()), AddCharacterWindow, SLOT(close()));
	connect(AddCharacterWindow->getCancelButton(), SIGNAL(clicked()), this, SLOT(activateOptionsMenu()));
	connect(AddCharacterWindow, SIGNAL(characterIsOk()), this, SLOT(activateOptionsMenu()));
	this->setDisabled(true);
}

void OptionsMenu::activateOptionsMenu()
{
	setDisabled(false);
}

void OptionsMenu::showDialog()
{
	QString selfilter = tr("GuessWho Files (*.gw)");
	QString fileDialog = QFileDialog::getOpenFileName(this, "Ouvrir une liste de personnages", "./Ressources/CharacterFiles", tr("GuessWho Files (*.gw)"), &selfilter);
	if (fileDialog != "") //The list has been changed
	{
		activeList = fileDialog;
		c_manager->importCharacters(fileDialog.toStdString()); //Change the current list
	}
	active_List->setText(activeList);
}

void OptionsMenu::newList() {
	QString selfilter = tr("GuessWho Files (*.gw)");
	QString fileDialog = QFileDialog::getSaveFileName(this, "Enregistrer une liste de personnages", "./Ressources/CharacterFiles", tr("GuessWho Files (*.gw)"), &selfilter);
	if (fileDialog != "") //The list has been changed
	{
		activeList = fileDialog;
		//Resets the list then exports the empty list to create the file
		c_manager->clearCharacterVector();
		c_manager->exportCharacters(fileDialog.toStdString());
		//c_manager->importCharacters(fileDialog.toStdString()); //Change the current list
	}
	active_List->setText(activeList);
}
